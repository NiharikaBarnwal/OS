#include<stdio.h>
#include<sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
int main()
{
	int pid,n;
	printf("\nEnter number to check");
	scanf("%d",&n);
	pid=fork();
	if(pid<0)
	{
		printf("error");
		
	}
	if (pid==0)
	{
		if(n%2==0)
		{
			printf("The number is even");
		}
		else
		{
			printf("The number is odd");
		}
	}
	if(pid>0)
	{
		if(n==1 || n==0)
                {
                        printf("Neither prime Nor Composite\n");
                }
                else{
                        int ct=0,i;
                        for(i=2;i<n;i++)
                        {
                                if(n%i==0)
                                {
                                        ct++;
                                }
                        }
                        if(ct==0) printf("Number is prime\n");
                        else printf("Number is not prime\n");
		}
	}
}

