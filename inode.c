#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
    char d[50];
    if (argc == 2) {
        bzero(d, sizeof(d)); // bzero -> erases data (writes zeroes) (of size d)
        strcat(d, "ls "); // destination, source (adds and stores in d)
        strcat(d, "-i "); 
        strcat(d, argv[1]); // now d contains ls -i and the arg -> the terminal command for inode
        system(d); // pass commands to terminal.
    } else {
        printf("\n Invalid number of inputs!");
    }
} 
