#include<stdio.h>
struct times{
	int bt;
	int at;
	int tat;
	int wt;
	int rt;
};
int main(){
	int n,i,s=0,sum=0;
	printf("Enter the no. of process:");
	scanf("%d",&n);
	struct times p[n];
	printf("Enter burst time of each process:");
	for(i=0;i<n;i++){
		scanf("%d",&p[i].bt);
	}
	printf("Enter arrival time of each process:");
	for(i=0;i<n;i++){
                scanf("%d",&p[i].at);
        }
	for(i=0;i<n;i++){
		s=s+p[i].bt;
		p[i].tat=s-p[i].at;
		p[i].wt=p[i].tat-p[i].bt;
		sum=sum+p[i].wt;
	}
	double awt=sum/n;
	printf("Process\tBurst time\tArrival time\tTAT\tWT\n");
	for(i=0;i<n;i++){
		printf("P%d\t%d\t\t%d\t\t%d\t%d\n",i+1,p[i].bt,p[i].at,p[i].tat,p[i].wt);
	}
	printf("Average waiting time: %f\n",awt);
}
