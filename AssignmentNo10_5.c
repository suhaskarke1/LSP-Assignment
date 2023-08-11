#include <stdio.h>
#include <pthread.h>

void* thread_function(void* arg)
 {
    pthread_t thread_id = pthread_self();
    printf("Thread ID: %lu\n", (unsigned long)thread_id);
    return NULL;
}

int main() {
    pthread_t threads[5];

    for (int i = 0; i < 5; i++) {
        if (pthread_create(&threads[i], NULL, thread_function, NULL) != 0) {
            printf("pthread_create");
            return 1;
        }
    }

    for (int i = 0; i < 5; i++) {
        if (pthread_join(threads[i], NULL) != 0) {
            printf("pthread_join");
            return 1;
        }
    }

    return 0;
}
