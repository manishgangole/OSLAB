#include <stdio.h>

void FCFS(int processes[], int n, int bt[]) {
    int wt[n], tat[n], total_wt = 0, total_tat = 0;

    // Calculating waiting time for each process
    wt[0] = 0;
    for (int i = 1; i < n; i++) {
        wt[i] = bt[i - 1] + wt[i - 1];
    }

    // Calculating turnaround time for each process
    for (int i = 0; i < n; i++) {
        tat[i] = bt[i] + wt[i];
    }

    // Displaying results
    printf("\nProcess\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++) {
        total_wt += wt[i];
        total_tat += tat[i];
        printf("%d\t%d\t\t%d\t\t%d\n", processes[i], bt[i], wt[i], tat[i]);
    }

    printf("\nAverage Waiting Time = %.2f", (float)total_wt / n);
    printf("\nAverage Turnaround Time = %.2f\n", (float)total_tat / n);
}

int main() {
    int n;

    // Get the number of processes
    printf("Enter number of processes: ");
    scanf("%d", &n);

    int processes[n], bt[n];

    // Get the burst time for each process
    printf("Enter the burst time for each process:\n");
    for (int i = 0; i < n; i++) {
        printf("Process %d burst time: ", i + 1);
        scanf("%d", &bt[i]);
        processes[i] = i + 1;  // Process IDs
    }

    // Call FCFS function
    FCFS(processes, n, bt);
    return 0;
}
