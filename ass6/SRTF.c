#include<stdio.h>
#include<limits.h>
struct times{
	int pno;
	int bt;
	int at;
	int tat;
	int wt;
	int rt;
	int rbt;
};
void sort_process(struct times p[], int n ){
	int i,j;
	struct times temp;
	for(i=0;i<n;i++){
                for(j=i+1;j<n;j++){
                        if(p[i].bt>p[j].bt){
                                temp=p[i];
                                p[i]=p[j];
                                p[j]=temp;
                        }
                }
        }
}
int main(){
	int n,i,j,s=0, completed=0,sum=0, prev=0,check=0;
	printf("Enter the no. of process:");
	scanf("%d",&n);
	struct times p[n];
	printf("Enter burst time of each process:");
	for(i=0;i<n;i++){
		scanf("%d",&p[i].bt);
		p[i].rbt=p[i].bt;
	}
	printf("Enter arrival time of each process:");
	for(i=0;i<n;i++){
                scanf(" %d",&p[i].at);
		p[i].pno=i+1;
        }
	sort_process(p,n);
	int min_rt;
	int shortest=-1;
	while(completed != n){
		min_rt=INT_MAX;
		for(i=0;i<n;i++){
			if(s>=p[i].at && p[i].rbt<min_rt && p[i].rbt>0){
				min_rt=p[i].rbt;
				shortest=i;
				check=1;
			}
		}
		if(check == -1){
			s++;
			continue;
		}
		p[shortest].rbt--;
		if(p[shortest].rbt==p[shortest].bt-1){
			p[shortest].rt=s-p[shortest].at;
		}
		if(p[shortest].rbt==0){
			completed++;
			p[shortest].tat=s+1-p[shortest].at;
		        p[shortest].wt=p[shortest].tat-p[shortest].bt;
                	sum=sum+p[shortest].wt;
		}
		s++;
	}
	double awt=(double)sum/n;
	printf("Process\tBurst time\tArrival time\tTAT\tWT\n");
        for(i=0;i<n;i++){
                printf("P%d\t%d\t\t%d\t\t%d\t%d\n",p[i].pno,p[i].bt,p[i].at,p[i].tat,p[i].wt);
        }
	printf("Average waiting time: %f\n",awt);
}
