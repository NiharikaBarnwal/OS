#include <stdio.h>
#include <stdlib.h> // Included for exit() function
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
    int pid;
    pid = fork();   /* fork a process  */
    if (pid < 0)   /* child process not created, error occurred  */
    {
        fprintf(stderr, "Error Occurred\n"); // Changed printf to fprintf and fixed the string formatting
        exit(-1);
    }
    else if (pid == 0)  /* child process created  */
    {
        printf("I am in child process\n"); // Added \n for new line
        for (int i = 0; i <= 10; i++)
        {
            printf("%d  ", i);
        }
        printf("I am exiting child process\n"); // Added \n for new line
    }
    else    /* parent process  */
    {
        wait(NULL); // Wait for the child process to finish
        printf(" parent process ends\n"); // Added \n for new line
    }
    return 0; // Added return statement
}


