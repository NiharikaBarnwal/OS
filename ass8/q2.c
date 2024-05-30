#include<stdio.h>
#include<stdlib.h>
int main(){
	int p[10],count=0;
	while(1){
		if(pipe(p)==-1){
			printf("Maximum no. of pipe that can exist simultaneously is: %d\n",count);
			break;
		}
		count++;
	}
}
