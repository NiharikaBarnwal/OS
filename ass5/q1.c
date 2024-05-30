#include<stdio.h>
#include<sys/types.h>
#include <unistd.h>
int main()
{
	int pid;
	printf("\nWelcome to the Program!");

	pid=fork();
	printf("%d",pid);

	if(pid==0)
	{
		//pid=getpid();
		printf("\n The Child Process Process ID is %d\n",getpid());
	}
	else
	{
		//pid=getpid();
		printf("\n The Parent Process Process ID is %d\n",getppid());
	}
}

