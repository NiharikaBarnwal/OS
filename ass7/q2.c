#include<stdio.h>
#include<stdlib.h>
#include<signal.h>
void loop(int signo){
	printf("SIGINT=%d....SIGQUIT=%d\n",SIGINT,SIGQUIT);
	exit(0);
}
int main()
{
	signal(SIGQUIT,loop);
	signal(SIGINT,loop);
	while(1){
		printf("hello\n");
	}
}
