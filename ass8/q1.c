#include<stdio.h>
#include<stdlib.h>
int main()
{
	int pipefd[2], n;
	char buff[100];
	if (pipe(pipefd) < 0) {
		error ("pipe error");
	}
	printf ("readfd = %d, writefd = %d\n",pipefd[0], pipefd[1]);
	if (write(pipefd[1], "hello world\n", 12) != 12) {
		error ("write error");
	}
	if ((n=read(pipefd[0], buff, sizeof(buff))) < 0) {
		error ("read error");
	}
	write (1, buff, n);
	exit (0);
}
