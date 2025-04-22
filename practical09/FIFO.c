#include <stdio.h>

#define MAX_FRAMES 10

// Function to implement FIFO Page Replacement
void FIFOPageReplacement(int pages[], int n, int frames) {
    int memory[frames];
    int pageFaults = 0;
    int pointer = 0;

    // Initialize memory with -1 indicating empty frames
    for (int i = 0; i < frames; i++) {
        memory[i] = -1;
    }

    printf("\nPage\tMemory Frames\n");
    for (int i = 0; i < n; i++) {
        int page = pages[i];
        int pageFault = 1;

        // Check if the page is already in memory
        for (int j = 0; j < frames; j++) {
            if (memory[j] == page) {
                pageFault = 0;  // No page fault
                break;
            }
        }

        // If page not found in memory, replace the oldest page
        if (pageFault) {
            memory[pointer] = page;
            pointer = (pointer + 1) % frames;  // Move pointer to next frame
            pageFaults++;

            // Print the current state of memory
            printf("%d\t", page);
            for (int j = 0; j < frames; j++) {
                if (memory[j] == -1) {
                    printf("-\t");
                } else {
                    printf("%d\t", memory[j]);
                }
            }
            printf("\n");
        }
    }

    printf("\nTotal Page Faults: %d\n", pageFaults);
}

// Driver code
int main() {
    int pages[MAX_FRAMES], n, frames;

    // Get the number of frames
    printf("Enter number of frames: ");
    scanf("%d", &frames);

    // Get the number of pages
    printf("Enter number of pages: ");
    scanf("%d", &n);

    // Get the page sequence
    printf("Enter the page sequence:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &pages[i]);
    }

    // Call the FIFO function
    FIFOPageReplacement(pages, n, frames);

    return 0;
}
