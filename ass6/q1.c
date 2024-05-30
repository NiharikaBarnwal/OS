#include <stdio.h>
#include<stdlib.h>
#include<limits.h>
struct times{
        int pno;
        int bt;
        int at;
        int tat;
        int wt;
        int rt;
        int rbt;
	int priority;
};
void sort_processes_by_arrival(struct times p[], int n) {
    int i, j;
    struct times temp;
    for (i = 0; i < n; i++) {
        for (j = i + 1; j < n; j++) {
            if (p[i].at > p[j].at) {
                temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
    }
}
void FCFS(){
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
void SJF(){
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
void SRTF(){
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
        sort_processes_by_arrival(p, n);
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
                if(check == 0){
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
		check=0;
        }
        double awt=(double)sum/n;
        printf("Process\tBurst time\tArrival time\tTAT\tWT\n");
        for(i=0;i<n;i++){
                printf("P%d\t%d\t\t%d\t\t%d\t%d\n",p[i].pno,p[i].bt,p[i].at,p[i].tat,p[i].wt);
        }
        printf("Average waiting time: %f\n",awt);
}
void RR(){
    int n, i, quantum;
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    struct times p[n];
    printf("Enter burst time for each process: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &p[i].bt);
        p[i].rbt = p[i].bt;
    }
    printf("Enter arrival time for each process: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &p[i].at);
        p[i].pno = i + 1;
    }
    printf("Enter the time quantum: ");
    scanf("%d", &quantum);
    sort_processes_by_arrival(p, n);
    int total_time = 0, completed = 0, current_time = 0, flag = 0, sum_wt = 0;
    while (completed != n) {
        flag = 0;
        for (i = 0; i < n; i++) {
            if (p[i].at <= current_time && p[i].rbt > 0) {
                flag = 1;
                if (p[i].rbt > quantum) {
                    current_time += quantum;
                    p[i].rbt -= quantum;
                } else {
                    current_time += p[i].rbt;
                    p[i].tat = current_time - p[i].at;
                    p[i].wt = p[i].tat - p[i].bt;
                    sum_wt += p[i].wt;
                    p[i].rbt = 0;
                    completed++;
                }
            }
        }
        if (flag == 0) {
            current_time++;
        }
    }
    double avg_wt = (double)sum_wt / n;
    printf("Process\tBurst Time\tArrival Time\tTAT\tWT\n");
    for (i = 0; i < n; i++) {
        printf("P%d\t%d\t\t%d\t\t%d\t%d\n", p[i].pno, p[i].bt, p[i].at, p[i].tat, p[i].wt);
    }
    printf("Average waiting time: %.2f\n", avg_wt);
}
void PS(){
    int n, i;
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    struct times p[n];
    printf("Enter burst time and priority for each process:\n");
    for (i = 0; i < n; i++) {
        printf("Process %d - Burst time: ", i + 1);
        scanf("%d", &p[i].bt);
        printf("Process %d - Priority: ", i + 1);
        scanf("%d", &p[i].priority);
        p[i].rbt = p[i].bt;
    }
    printf("Enter arrival time for each process:\n");
    for (i = 0; i < n; i++) {
        printf("Process %d: ", i + 1);
        scanf("%d", &p[i].at);
        p[i].pno = i + 1;
    }
    sort_processes_by_arrival(p, n);
    int completed = 0, s = 0, min_priority, shortest = -1, sum_wt = 0;
    int check = 0;
    while (completed != n) {
        min_priority = INT_MAX;
        for (i = 0; i < n; i++) {
            if ((p[i].at <= s) && (p[i].priority < min_priority) && (p[i].rbt > 0)) {
                min_priority = p[i].priority;
                shortest = i;
                check = 1;
            }
        }
        if (check == 0) {
            s++;
            continue;
        }
        p[shortest].rbt--;
        if (p[shortest].rbt == p[shortest].bt - 1) {
            p[shortest].rt = s - p[shortest].at;
        }
        if (p[shortest].rbt == 0) {
            completed++;
            p[shortest].tat = s + 1 - p[shortest].at;
            p[shortest].wt = p[shortest].tat - p[shortest].bt;
            sum_wt += p[shortest].wt;
        }
        s++;
        check = 0;
    }
    double avg_wt = (double)sum_wt / n;
    printf("Process\tBurst Time\tArrival Time\tPriority\tTAT\tWT\n");
    for (i = 0; i < n; i++) {
        printf("P%d\t%d\t\t%d\t\t%d\t\t%d\t%d\n", p[i].pno, p[i].bt, p[i].at, p[i].priority, p[i].tat, p[i].wt);
    }
    printf("Average waiting time: %.2f\n", avg_wt);
}
int main()
{
	int opt;
	char cont='Y';
	printf("OPTIONS:\n1) FCFS\t2) SJF\t3) SRTF\t4) RR\t5) PS\n");
	while(cont=='Y'){
		printf("Enter your option:");
		scanf("%d",&opt);
		switch(opt)
		{
			case 1:
				FCFS();
				break;
			case 2:
				SJF();
				break;
			case 3:
				SRTF();
				break;
			case 4:
				RR();
				break;
			case 5:
				PS();
				break;
			default:
				exit(0);
				break;
		}
		printf("Do you want to continue?(Y/N): ");
		scanf(" %c",&cont);
	}
}
