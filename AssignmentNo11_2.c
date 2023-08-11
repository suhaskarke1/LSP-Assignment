#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

void *thread_function(void *thread_id)
 {
    printf("Thread %ld starting...\n", (long)thread_id);
    sleep(2);
    printf("Thread %ld finished!\n", (long)thread_id);
    return NULL;
}

int main() {
    pthread_t thread1, thread2;
    pthread_attr_t attr;

    // Initialize attributes
    pthread_attr_init(&attr);

    // Create thread with default attributes
    pthread_create(&thread1, NULL, thread_function, (void *)1);
    pthread_join(thread1, NULL);

    // Set custom attributes
    pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED);

    // Create thread with custom attributes
    pthread_create(&thread2, &attr, thread_function, (void *)2);

    // No need to join detached thread

    // Clean up attributes
    pthread_attr_destroy(&attr);

    printf("All threads have been created!\n");

    return 0;
}
