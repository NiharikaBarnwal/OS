#include<stdio.h>
#include<sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
int R1,C1,R2,C2;
void multiplyMatrix(int m1[][C1], int m2[][C2])
{
    int result[R1][C2];
 
    printf("Resultant Matrix is:\n");
 
    for (int i = 0; i < R1; i++) {
        for (int j = 0; j < C2; j++) {
            result[i][j] = 0;
 
            for (int k = 0; k < R2; k++) {
                result[i][j] += m1[i][k] * m2[k][j];
            }
 
            printf("%d\t", result[i][j]);
        }
 
        printf("\n");
    }
}
int main()
{
	int pid,n;
	printf("enter row and column of matrix once!");
	scanf("%d",&R1);
	scanf("%d",&C1);
	R2=R1;
	C2=C1;
	int m1[R1][C1],m2[R2][C2];
	printf("enter the matrix one");
	for(int i=0;i<R1;i++)
	{
		for(int j=0;j<C1;j++)
		{
			scanf("%d",&m1[i][j]);
		}
	}
	printf("enter the matrix two");
        for(int i=0;i<R2;i++)
        {
                for(int j=0;j<C2;j++)
                {
                        scanf("%d",&m2[i][j]);
                }
        }
	pid=fork();
	if(pid<0)
	{
		printf("error");
		
	}
	if (pid==0)
	{
		multiplyMatrix(m1, m2);
	}
	if(pid>0)
	{
		int C[R1][C1];
		for (int i=0;i<R1;i++)
		{
			for (int j=0;j<C1;j++)
			{
				C[i][j]=m1[i][j]+m2[i][j];
			}
		}
		for (int i=0;i<R1;i++)
                {
                        for (int j=0;j<C1;j++)
                        {
                                printf("%d ",C[i][j]);
  			}
			printf("\n");
                }
	}
}

