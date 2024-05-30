#include <stdio.h>

struct process {
    int pno;
    int bt;
    int at;
    int tat;
    int wt;
    int rt;
    int rbt;  // Remaining Burst Time
};

void sort_processes_by_arrival(struct process p[], int n) {
    int i, j;
    struct process temp;
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

int main() {
    int n, i, quantum;
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    struct process p[n];

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

