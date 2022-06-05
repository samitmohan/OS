// fork is used to create child process. (clone of parent) (not using thread, creating another process)
// fork returns -> 0 (child process) or +1 (positive -> parent process) or -1 (if child process not created);

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
  
int main() // main is the parent process
{
    for(int i = 0; i < 5; i++) // loop will run n times (n=5)
    {
        if (fork() == 0) // child process
        {
            printf("[son] pid %d from [parent] pid %d\n", getpid(), getppid()); // pid -> child, ppid -> parent
            exit(0);
        }
    }
    for(int i = 0; i < 5; i++) 
    { 
        // after every call (if process has more than one child process after wait call, it has to be in wait state)
        wait(NULL); 
    }
    // this makes sure program is mutually exclusive
}
