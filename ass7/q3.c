#include<stdio.h>
#include<stdlib.h>
#include<signal.h>
#include<sys/types.h>
void loop(int signo){
	printf("SIGCHLD=%d\n",SIGCHLD);
	exit(0);
}
int main()
{
	int pid,i=0;
	pid=fork();
	signal(SIGCHLD,loop);
	if(pid<0){
		printf("error");
		exit(0);
	}
	if(pid==0){
		while(i<11){
			printf("%d\n",i);
			i++;
			if(i==10)
				kill(pid,SIGCHLD);
		}
	}
}
