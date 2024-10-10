#ifndef USERPROG_SYSCALL_H
#define USERPROG_SYSCALL_H

// 1수정시작
typedef int pid_t;
// 1수정끝

void syscall_init (void);
// 1수정시작
void validate_user_pointer(const void *ptr);
void validate_user_buffer(const void *buffer, unsigned size);

void halt(void);
void exit(int status);
pid_t exec(const char *cmd_line);
int wait(pid_t pid);
int read(int fd, void *buffer, unsigned size);
int write(int fd, const void *buffer, unsigned size);
int fibonacci(int n);
int max_of_four_int(int a, int b, int c, int d);
// 1수정끝

#endif /* userprog/syscall.h */
