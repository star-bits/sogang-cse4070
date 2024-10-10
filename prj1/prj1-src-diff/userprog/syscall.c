#include "userprog/syscall.h"
#include <stdio.h>
#include <syscall-nr.h>
#include "threads/interrupt.h"
#include "threads/thread.h"
// 1수정시작
#include "threads/vaddr.h"
#include "userprog/pagedir.h"
#include "devices/shutdown.h"
#include "userprog/process.h"
#include "devices/input.h"
#include "threads/malloc.h"
// 1수정끝

static void syscall_handler (struct intr_frame *);

void
syscall_init (void) 
{
  intr_register_int (0x30, 3, INTR_ON, syscall_handler, "syscall");
}

// 1수정시작
static void
syscall_handler(struct intr_frame *f) 
{
    validate_user_pointer(f->esp);

    /* 시스템 콜 번호를 얻기 위해 스택 포인터를 uint32_t 포인터로 캐스팅 */
    uint32_t *args = (uint32_t *)f->esp;
    int syscall_num = args[0];

    switch (syscall_num)
    {
        case SYS_HALT:
            halt();
            break;

        case SYS_EXIT:
            validate_user_pointer(args + 1); // 인자(args[1])의 유효성 검증
            exit((int)args[1]);
            break;

        case SYS_EXEC:
            validate_user_pointer(args + 1);
            f->eax = exec((const char *)args[1]); // 새로운 프로그램 실행 후 PID 반환
            break;

        case SYS_WAIT:
            validate_user_pointer(args + 1);
            f->eax = wait((pid_t)args[1]); // 지정된 PID의 프로세스가 종료될 때까지 대기
            break;

        case SYS_READ:
            validate_user_pointer(args + 3); // 인자(args[1] ~ args[3])의 유효성 검증
            f->eax = read((int)args[1], (void *)args[2], (unsigned)args[3]);
            break;

        case SYS_WRITE:
            validate_user_pointer(args + 3);
            f->eax = write((int)args[1], (const void *)args[2], (unsigned)args[3]);
            break;

        case SYS_FIBONACCI:
            validate_user_pointer(args + 1);
            f->eax = fibonacci((int)args[1]);
            break;

        case SYS_MAXOFFOURINT:
            validate_user_pointer(args + 4); // 인자(args[1] ~ args[4])의 유효성 검증
            f->eax = max_of_four_int((int)args[1], (int)args[2], (int)args[3], (int)args[4]);
            break;

        default:
            printf("Unknown syscall number: %d\n", syscall_num);
            exit(-1);
            break;
    }
}

void
validate_user_pointer(const void *ptr)
{
    /* 포인터가 NULL이거나 유저 영역의 주소가 아니거나 페이지가 매핑되지 않은 경우 프로세스 종료 */
    if (ptr == NULL || !is_user_vaddr(ptr) || pagedir_get_page(thread_current()->pagedir, ptr) == NULL)
        exit(-1);
}

void
halt(void)
{
    shutdown_power_off();
}

void
exit(int status)
{
    printf("%s: exit(%d)\n", thread_name(), status); // 프로세스 이름과 종료 상태를 출력
    thread_current()->exit_status = status; // 현재 스레드의 종료 상태 설정
    thread_exit(); // 스레드 종료
}

pid_t
exec(const char *cmd_line)
{
    validate_user_pointer(cmd_line);
    return process_execute(cmd_line); // 새로운 프로세스 실행 및 PID 반환
}

int
wait(pid_t pid)
{
    return process_wait(pid); // 지정된 PID의 프로세스가 종료될 때까지 대기
}

int
read(int fd, void *buffer, unsigned size)
{
    /* 버퍼의 시작과 끝 주소의 유효성 검증 */
    validate_user_pointer(buffer);
    validate_user_pointer(buffer + size - 1);

    if (fd == 0) // 표준 입력인 경우
    {
        unsigned i;
        for (i = 0; i < size; i++)
        {
            int c = input_getc(); // 한 글자 입력 받음
            ((uint8_t *)buffer)[i] = (uint8_t)c; // 버퍼에 저장
            if (c == '\0')
                break; // \0을 만나면 종료
        }
        return i; // 읽은 바이트 수 반환
    }
    return -1;
}

int
write(int fd, const void *buffer, unsigned size)
{
    validate_user_pointer(buffer);
    validate_user_pointer(buffer + size - 1);

    if (fd == 1) // 표준 출력인 경우
    {
        putbuf(buffer, size); // 버퍼의 내용을 출력
        return size; // 출력한 바이트 수 반환
    }
    return -1;
}

int
fibonacci(int n)
{
    if (n < 0)
        exit(-1);

    if (n == 0 || n == 1)
        return n;

    int *dp = malloc(sizeof(int) * (n + 1));
    if (dp == NULL)
        exit(-1);

    dp[0] = 0;
    dp[1] = 1;

    for (int i = 2; i <= n; i++)
    {
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    int result = dp[n];
    free(dp);
    return result;
}

int
max_of_four_int(int a, int b, int c, int d)
{
    int max = a;
    if (b > max) max = b;
    if (c > max) max = c;
    if (d > max) max = d;
    return max;
}
// 1수정끝