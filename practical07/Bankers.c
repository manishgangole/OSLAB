#include <stdio.h>
#include <stdlib.h>

#define MAX 10  // Maximum number of processes or resources

// Function to find if the system is in a safe state
int isSafe(int processes[], int n, int resources[], int m, int allot[][MAX], int max[][MAX]) {
    int need[n][m], finish[n], safeSeq[n];
    int work[m], count = 0;
    
    // Calculate need matrix (max - allot)
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            need[i][j] = max[i][j] - allot[i][j];
        }
    }

    // Initialize finish and work arrays
    for (int i = 0; i < n; i++) {
        finish[i] = 0;
    }
    for (int i = 0; i < m; i++) {
        work[i] = resources[i];
    }

    // Find the safe sequence
    while (count < n) {
        int found = 0;
        for (int i = 0; i < n; i++) {
            if (!finish[i]) {
                int canAllocate = 1;
                // Check if the process can be allocated resources
                for (int j = 0; j < m; j++) {
                    if (need[i][j] > work[j]) {
                        canAllocate = 0;
                        break;
                    }
                }
                // If the process can be allocated resources
                if (canAllocate) {
                    // Add allocated resources to work
                    for (int j = 0; j < m; j++) {
                        work[j] += allot[i][j];
                    }
                    finish[i] = 1;
                    safeSeq[count++] = i;
                    found = 1;
                    break;
                }
            }
        }

        // If no process can be allocated resources, then the system is not in a safe state
        if (!found) {
            printf("System is not in a safe state.\n");
            return 0;
        }
    }

    // If all processes can finish, the system is in a safe state
    printf("System is in a safe state. Safe Sequence: ");
    for (int i = 0; i < n; i++) {
        printf("P%d ", safeSeq[i]);
    }
    printf("\n");

    return 1;
}

// Driver code
int main() {
    int n, m;

    // Get number of processes and resources
    printf("Enter number of processes: ");
    scanf("%d", &n);
    printf("Enter number of resources: ");
    scanf("%d", &m);

    int processes[n], resources[m], allot[n][m], max[n][m];

    // Input processes
    printf("Enter the processes: ");
    for (int i = 0; i < n; i++) {
        processes[i] = i;  // P0, P1, P2, ..., Pn-1
    }

    // Input available resources
    printf("Enter the available resources: ");
    for (int i = 0; i < m; i++) {
        scanf("%d", &resources[i]);
    }

    // Input allocated resources
    printf("Enter the allocated resources matrix (allocation matrix):\n");
    for (int i = 0; i < n; i++) {
        printf("Enter allocated resources for process P%d: ", i);
        for (int j = 0; j < m; j++) {
            scanf("%d", &allot[i][j]);
        }
    }

    // Input maximum resource needs
    printf("Enter the maximum resources matrix (max matrix):\n");
    for (int i = 0; i < n; i++) {
        printf("Enter maximum resources for process P%d: ", i);
        for (int j = 0; j < m; j++) {
            scanf("%d", &max[i][j]);
        }
    }

    // Check if the system is in a safe state
    isSafe(processes, n, resources, m, allot, max);

    return 0;
}
