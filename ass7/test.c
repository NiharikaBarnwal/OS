#include<stdio.h>
#include<stdlib.h>
#include<signal.h>
void fp_err(int signo){
	printf("signal cought ... ... SIGFPE\n");
	exit(0);
}
int main(){
	int x=5,y=0,z;
	signal(SIGFPE, fp_err);
	z=x/y;
}

