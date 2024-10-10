#ifndef USERPROG_PROCESS_H
#define USERPROG_PROCESS_H

#include "threads/thread.h"

tid_t process_execute (const char *file_name);
int process_wait (tid_t);
void process_exit (void);
void process_activate (void);

// 1수정시작
void push_arguments_to_stack(char **argv, int argc, void **esp);
// 1수정끝

#endif /* userprog/process.h */
