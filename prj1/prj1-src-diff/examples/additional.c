// 1수정시작
#include <stdio.h>
#include <stdlib.h>
#include <syscall.h>

int main(int argc, char **argv)
{
    int arr[4] = {0};

    for (int i = 0; i < 4 && i + 1 < argc; i++) {
        arr[i] = atoi(argv[i + 1]);
    }

    printf("%d %d\n", fibonacci(arr[0]), max_of_four_int(arr[0], arr[1], arr[2], arr[3]));
    return EXIT_SUCCESS;
}
// 1수정끝