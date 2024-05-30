#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

#define ARRAY_SIZE 10

int freq(int arr[], int n, int m) {
    int count = 0;
    for (int j = 0; j < n; j++) {
        if (arr[j] == m) {
            count++;
        }
    }
    return count;
}

int main() {
    int arr[ARRAY_SIZE] = {1, 2, 3, 4, 2, 1, 2, 3, 4, 5};
    int pipefd[2];

    if (pipe(pipefd) == -1) {
        perror("pipe");
        exit(0);
    }

    pid_t pid = fork();

    if (pid < 0) {
        perror("fork");
        exit(0);
    }
    else if(pid == 0){ 
        close(pipefd[0]); 
        for (int i=1; i <= 5; i++) {
            int f = freq(arr, ARRAY_SIZE, i);
            write(pipefd[1], &f, sizeof(f));
        }
        close(pipefd[1]);
        exit(0);
    }
    else{ 
        wait(NULL); 
        close(pipefd[1]); 
        for (int i = 1; i <= 5; i++) {
            int freq_read;
            read(pipefd[0], &freq_read, sizeof(freq_read));
            printf("Frequency of element %d: %d\n", i, freq_read);
        }
        close(pipefd[0]); 
    }
    return 0;
}
