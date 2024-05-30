#include <stdio.h>
#include <limits.h>

struct process {
    int pno;
    int bt;
    int at;
    int tat;
    int wt;
    int rt;
    int rbt;  // Remaining Burst Time
    int priority;
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
    int n, i;
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    struct process p[n];

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

        // First time this process gets the CPU
        if (p[shortest].rbt == p[shortest].bt - 1) {
            p[shortest].rt = s - p[shortest].at;
        }

        // Completion of the process
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

