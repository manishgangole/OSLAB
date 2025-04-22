#include <stdio.h>
#include <stdlib.h>

// Function to implement SSTF Disk Scheduling
void SSTF(int requests[], int n, int start) {
    int visited[n];
    int total_seek_time = 0;
    int current_position = start;

    // Initialize visited array
    for (int i = 0; i < n; i++) {
        visited[i] = 0;
    }

    printf("Disk Scheduling using SSTF:\n");
    printf("Initial position of the disk head: %d\n", start);

    // Perform SSTF Disk Scheduling
    for (int i = 0; i < n; i++) {
        int min_seek_time = 9999, next_request = -1;

        // Find the closest request
        for (int j = 0; j < n; j++) {
            if (!visited[j]) {
                int seek_time = abs(requests[j] - current_position);
                if (seek_time < min_seek_time) {
                    min_seek_time = seek_time;
                    next_request = j;
                }
            }
        }

        // Visit the selected request
        visited[next_request] = 1;
        total_seek_time += min_seek_time;
        current_position = requests[next_request];

        // Print the request being processed
        printf("Move to disk position: %d\n", current_position);
    }

    printf("Total seek time = %d\n", total_seek_time);
}

// Driver code
int main() {
    int n, start;

    // Get number of requests
    printf("Enter the number of disk requests: ");
    scanf("%d", &n);

    int requests[n];

    // Get the disk requests
    printf("Enter the disk requests:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &requests[i]);
    }

    // Get the starting position of the disk head
    printf("Enter the initial position of the disk head: ");
    scanf("%d", &start);

    // Call the SSTF function
    SSTF(requests, n, start);

    return 0;
}
