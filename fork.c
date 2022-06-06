#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// parent process which holds the positive id

int main()
{
    // fork();
    // printf("child process created, will print twice \n");
    // both child and parent run together.

    int pid = fork();
    if (pid > 0)
    {
        printf("fork() returned +ve value, this is parent process with id : %d \n", getpid());
    }
    else if (pid == 0)
    {
        printf("fork() returned a 0 value, this is newly created child process : %d \n", getpid());
        printf("parent process id : %d \n", getppid());
    }
    else
    {
        printf("Negative value, fail");
    }

    printf("Print statement, if fork() successful, this should run for both child and parent (will print twice) \n");
    // If the PPID is 1, it means the parent process terminated before the child process. And ppid of child got updated to 1 -> new parent

    return 0;
}
