#include<stdio.h> 
#include<stdlib.h>
#include<string.h>
#include<sys/types.h> 
int main() 
{ 
	int p[2]; 
	int pid;
	char msg1[] = "Hello, parent!!!\n"; 
	char readbuffer1[80]; 
	pipe(p);
	pid=fork();
	if(pid == 0) 
	{ 
		close(p[0]);
		write(p[1], msg1, (strlen(msg1)+1));
	}
	else   
	{ 
		close(p[1]);
		read(p[0], readbuffer1, sizeof(readbuffer1)); 	
                printf("Received message from child: %s", readbuffer1);
	} 
	return(0); 
}
