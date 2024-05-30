#include<stdio.h>
#include<stdlib.h>
#include<signal.h>
void loop(int signo){
	printf("Endless loop... SIGINT\n");
	exit(0);
}
int main(){
	signal(SIGINT,loop);
	while(1){
		printf("hello\n");
	}
}
