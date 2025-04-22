#include <stdio.h>

// Function to swap values
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to perform SJF Scheduling
void findAvgTime(int processes[], int n, int bt[]) {
    int wt[n], tat[n], total_wt = 0, total_tat = 0;

    // Sorting processes by burst time using simple selection sort
    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < n; j++) {
            if (bt[j] < bt[min_idx])
                min_idx = j;
        }
        // Swap burst time
        swap(&bt[i], &bt[min_idx]);
        // Swap process IDs to match burst time
        swap(&processes[i], &processes[min_idx]);
    }

    wt[0] = 0; // First process has 0 waiting time

    // Calculating waiting time
    for (int i = 1; i < n; i++)
        wt[i] = bt[i - 1] + wt[i - 1];

    // Calculating turnaround time
    for (int i = 0; i < n; i++)
        tat[i] = bt[i] + wt[i];

    printf("Processes  Burst Time  Waiting Time  Turnaround Time\n");

    for (int i = 0; i < n; i++) {
        total_wt += wt[i];
        total_tat += tat[i];
        printf("   %d\t\t%d\t    %d\t\t   %d\n", processes[i], bt[i], wt[i], tat[i]);
    }

    printf("\nAverage waiting time = %.2f", (float)total_wt / n);
    printf("\nAverage turnaround time = %.2f\n", (float)total_tat / n);
}

// Driver code
int main() {
    int processes[] = {1, 2, 3};
    int n = sizeof(processes) / sizeof(processes[0]);

    int burst_time[] = {6, 8, 7};

    findAvgTime(processes, n, burst_time);
    return 0;
}
