#include <stdio.h>
#include<signal.h>
int pid;
void abc()
{
        sleep(1);
        printf("Bye Papa\n");
        exit(0);
}
void def(){
        sleep(1);
        printf("Hello baby\n");
        kill(pid,SIGUSR2);
	sleep(1);
}
main()
{
        void abc(),def();
        pid=fork();
        if(pid==0)
        {
                signal(SIGUSR2,abc);
                sleep(1);
                printf("Hello Paapa\n");
                kill(getppid(), SIGUSR1);
                sleep(5);
        }
        else
        {
                signal(SIGUSR1,def);
                sleep(5);
        }
}
