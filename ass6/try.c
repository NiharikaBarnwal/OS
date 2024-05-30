#include<stdio.h>
struct times{
	int pno;
	int bt;
	int at;
	int tat;
	int wt;
	int rt;
};
int main(){
	int n,i,j,s=0,sum=0;
	printf("Enter the no. of process:");
	scanf("%d",&n);
	struct times p[n],temp;
	printf("Enter burst time of each process:");
	for(i=0;i<n;i++){
		scanf("%d",&p[i].bt);
	}
	printf("Enter arrival time of each process:");
	for(i=0;i<n;i++){
                scanf("%d",&p[i].at);
		p[i].pno=i+1;
        }
	for(i=0;i<n;i++){
		for(j=i+1;j<n;j++){
			if(p[i].bt>p[j].bt){
				temp=p[i];
				p[i]=p[j];
				p[j]=temp;
			}
		}
	}
	for(i=0;i<n;i++){
		s=s+p[i].bt;
		p[i].tat=s-p[i].at;
		p[i].wt=p[i].tat-p[i].bt;
		sum=sum+p[i].wt;
	}
	double awt=sum/n;
	printf("Process\tBurst time\tArrival time\tTAT\tWT\n");
	for(j=0;j<n;j++){
		for(i=0;i<n;i++){
			if(p[i].pno==j+1)
				printf("P%d\t%d\t\t%d\t\t%d\t%d\n",p[i].pno,p[i].bt,p[i].at,p[i].tat,p[i].wt);
		}
	}
	printf("Average waiting time: %f\n",awt);
}
