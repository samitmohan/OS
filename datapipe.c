#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <string.h>
#include <sys/wait.h>

// pipe() creates a unidirectional data channel for interprocess communication
// we use 2 pipes here -> 1 to read, 1 to write

int main()
{
    int file[2]; // 2 array elements
    char input_str[100];
    pid_t p;
    if (pipe(file) == -1)
    {   // creates file[0] and file[1] file descripters for interprocess comm
        // fd[0] -> used for reading, d[1] -> used for writing data to pipe.
        // pipe error returns -1
        fprintf(stderr, "Pipe Failed");
        return 1;
    }

    printf("Enter the string \n");
    scanf("%s", input_str);
    p = fork(); // create process
    if (p < 0)  // if no process created
    {
        fprintf(stderr, "Fork Failed \n");
        return 1;
    }

    // write

    else if (p > 0) // parent process
    {
        close(file[0]);                                   // close read file descripter
        write(file[1], input_str, strlen(input_str) + 1); // open write file descripter, and write input_str to it
        close(file[1]);                                   // close file descripter
        wait(NULL);                                      // to ensure mutual exclusivity.
    }

    // read
    else
    {
        close(file[1]); // close write file descripter
        printf("Child reading parent data from pipe \n");
        char parent_str[100]; // create parent string to cpy elements from read (file[0]) to parent_str
        read(file[0], parent_str, 100); // file, parent_str, size of parent_str
        printf("Read string : %s \n", parent_str);
        close(file[0]); // close read file descripter
        exit(0);
    }
}
