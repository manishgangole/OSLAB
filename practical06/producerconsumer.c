#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX 10  // Size of the buffer

// Shared variables
int buffer = 0;  // Buffer to store produced items
int mutex = 1;   // Mutex to ensure mutual exclusion
int full = 0;    // Number of full slots in the buffer
int empty = MAX; // Number of empty slots in the buffer

// Mutex variable
pthread_mutex_t lock;

// Producer function
void producer() {
    // Decrement mutex to enter critical section
    pthread_mutex_lock(&lock);

    // Check if there is space to produce
    if (empty > 0) {
        // Produce an item
        buffer++;
        full++;
        empty--;
        printf("\nProducer produces item %d", buffer);
    } else {
        printf("\nBuffer is full!");
    }

    // Increment mutex to leave critical section
    pthread_mutex_unlock(&lock);
}

// Consumer function
void consumer() {
    // Decrement mutex to enter critical section
    pthread_mutex_lock(&lock);

    // Check if there are items to consume
    if (full > 0) {
        // Consume an item
        printf("\nConsumer consumes item %d", buffer);
        buffer--;
        full--;
        empty++;
    } else {
        printf("\nBuffer is empty!");
    }

    // Increment mutex to leave critical section
    pthread_mutex_unlock(&lock);
}

int main() {
    int choice;

    // Initialize the mutex
    pthread_mutex_init(&lock, NULL);

    printf("\n1. Press 1 for Producer");
    printf("\n2. Press 2 for Consumer");
    printf("\n3. Press 3 for Exit");

    while (1) {
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                // Producer operation
                producer();
                break;

            case 2:
                // Consumer operation
                consumer();
                break;

            case 3:
                // Exit program
                printf("\nExiting program...");
                pthread_mutex_destroy(&lock);
                exit(0);

            default:
                printf("\nInvalid choice! Please try again.");
        }
    }

    return 0;
}
