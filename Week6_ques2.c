// Producer–Consumer Problem

#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>

#define BUFFER_SIZE 5

int buffer[BUFFER_SIZE];
int in = 0, out = 0, count = 0;

pthread_mutex_t mutex;
pthread_cond_t not_full;
pthread_cond_t not_empty;

// Producer function
void *producer(void *arg)
{
    while (1)
    {

        // produce an item
        int item = rand() % 100;

        pthread_mutex_lock(&mutex);

        // buffer full
        while (count == BUFFER_SIZE)
        {
            pthread_cond_wait(&not_full, &mutex);
        }

        buffer[in] = item;
        printf("Produced: %d at %d\n", item, in);
        in = (in + 1) % BUFFER_SIZE;
        count++;

        // signal buffer has item
        pthread_cond_signal(&not_empty);
        pthread_mutex_unlock(&mutex);

        // simulate production time
        sleep(1);
    }
    return NULL;
}

// Consumer function
void *consumer(void *arg)
{
    while (1)
    {
        pthread_mutex_lock(&mutex);

        // buffer empty
        while (count == 0)
        {
            pthread_cond_wait(&not_empty, &mutex);
        }

        int item = buffer[out];
        printf("Consumed: %d at %d\n", item, out);
        out = (out + 1) % BUFFER_SIZE;
        count--;

        // signal buffer has space
        pthread_cond_signal(&not_full);
        pthread_mutex_unlock(&mutex);

        // simulate consumption time
        sleep(1);
    }
    return NULL;
}

int main()
{
    pthread_t prod, cons;

    pthread_mutex_init(&mutex, NULL);
    pthread_cond_init(&not_full, NULL);
    pthread_cond_init(&not_empty, NULL);

    pthread_create(&prod, NULL, producer, NULL);
    pthread_create(&cons, NULL, consumer, NULL);

    pthread_join(prod, NULL);
    pthread_join(cons, NULL);

    pthread_mutex_destroy(&mutex);
    pthread_cond_destroy(&not_full);
    pthread_cond_destroy(&not_empty);

    return 0;
}