#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    int pid;
    
    // Create a child process
    pid = fork();
    
    if (pid < 0) {
        // Error occurred while forking
        fprintf(stderr, "Error occurred while forking.\n");
        return 1;
    } else if (pid == 0) {
        // Child process
        printf("Parent starts\n");
        printf("Child starts\n");
        for (int i = 1; i <= 10; i++) {
            printf("%d ", i);
        }
        printf("// Parent Process\n");
        printf("Parent ends\n");
    } else {
        // Parent process
        printf("Child starts\n");
        for (int i = 1; i <= 10; i++) {
            printf("%d ", i);
        }
        printf("// Child Process\n");
        printf("Child ends\n");
        // Wait for the child process to finish
        wait(NULL);
    }
    
    return 0;
}


