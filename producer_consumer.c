#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
    int count = 0;
    for (int i = 0; i < 50; i++)
    {
        int pid = fork();
        if (pid == 0)
        {
            count++;
            printf("Count : %d", count);
            sleep(1000);
        }
        else if (pid > 0)
        {
            count--;
            printf("Count : %d", count);
            sleep(1000);
        }
        else if (pid < 0)
        {
            printf("Fork Fail");
        }
        // this will run twice. (100 times)
        printf("Successful loop");
    }
    return 0;
}