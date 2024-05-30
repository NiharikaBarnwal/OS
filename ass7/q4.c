#include<stdio.h>
#include<signal.h>
#include<stdlib.h>
void message(int s) {
    printf("Still working...\n");
    alarm(1);
    signal(SIGALRM, message);
}

int main() {
        int i=0;
    signal(SIGALRM, message);
    alarm(1);

    while (1) {
       pause();
    }

    return 0;
}
