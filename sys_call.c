#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    pid_t pid; // pid_t -> process identification -> data type -> just like integer but represents process ID.
    pid = fork(); // variable to store fork() -> either 0 (child) or negative (no child) or pos (parent)
    if (pid < 0) { // no process
        printf("Fork failed");
        exit(1);
    } else if (pid == 0) { // child process
        execlp("whoami", "ls", NULL); // excelp -> system call -> tells which user is running.
        exit(0);
    } else { // parent process (positive) -> getpid()
        printf("\n Process id = %d \n", getpid());
        wait(NULL);
        exit(0);
    }
}

// will return the process id of child process
