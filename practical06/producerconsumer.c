// file5.c
#include <stdio.h>
#include <stdlib.h>
#include <semaphore.h>
#include <pthread.h>

sem_t mutex, full, empty;
int buffer[5];
int in = 0, out = 0;

void *producer(void *p) {
    int item = rand() % 100;
    sem_wait(&empty);
    sem_wait(&mutex);

    buffer[in] = item;
    printf("Produced: %d\n", item);
    in = (in + 1) % 5;

    sem_post(&mutex);
    sem_post(&full);
}

void *consumer(void *c) {
    sem_wait(&full);
    sem_wait(&mutex);

    int item = buffer[out];
    printf("Consumed: %d\n", item);
    out = (out + 1) % 5;

    sem_post(&mutex);
    sem_post(&empty);
}

int main() {
    pthread_t prod, cons;

    sem_init(&mutex, 0, 1);
    sem_init(&full, 0, 0);
    sem_init(&empty, 0, 5);

    pthread_create(&prod, NULL, producer, NULL);
    pthread_create(&cons, NULL, consumer, NULL);

    pthread_join(prod, NULL);
    pthread_join(cons, NULL);

    return 0;
}
