#include <stdio.h>

int main() {
    int blockSize[10], processSize[10];
    int blockCount, processCount;
    int allocated[10];
    
    // Get number of blocks and processes
    printf("Enter number of memory blocks: ");
    scanf("%d", &blockCount);
    
    printf("Enter size of each block:\n");
    for (int i = 0; i < blockCount; i++) {
        printf("Block %d size: ", i + 1);
        scanf("%d", &blockSize[i]);
    }

    printf("Enter number of processes: ");
    scanf("%d", &processCount);
    
    printf("Enter size of each process:\n");
    for (int i = 0; i < processCount; i++) {
        printf("Process %d size: ", i + 1);
        scanf("%d", &processSize[i]);
        allocated[i] = -1;  // initially not allocated
    }

    // First Fit Allocation
    for (int i = 0; i < processCount; i++) {
        for (int j = 0; j < blockCount; j++) {
            if (blockSize[j] >= processSize[i]) {
                allocated[i] = j;
                blockSize[j] -= processSize[i];
                break;
            }
        }
    }

    // Output result
    printf("\nProcess No.\tProcess Size\tBlock No.\n");
    for (int i = 0; i < processCount; i++) {
        printf("    %d\t\t    %d\t\t", i + 1, processSize[i]);
        if (allocated[i] != -1)
            printf("%d\n", allocated[i] + 1);
        else
            printf("Not Allocated\n");
    }

    return 0;
}
