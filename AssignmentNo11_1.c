#include <stdio.h>
#include <pthread.h>

#define NUM_THREADS 4

void* thread_function(void* arg) 
{
    int thread_id = *(int*)arg;
    printf("Thread %d started\n", thread_id);
    
    for (int i = 0; i < 10000000; i++) {}
    printf("Thread %d finished\n", thread_id);
    return NULL;
}

int main() 
{
    pthread_t threads[NUM_THREADS];
    int thread_args[NUM_THREADS];

    for (int i = 0; i < NUM_THREADS; i++) 
	{
        thread_args[i] = i;
        if (pthread_create(&threads[i], NULL, thread_function, &thread_args[i]) != 0)
			{
            printf("pthread_create");
            return 1;
        }
    }

    for (int i = 0; i < NUM_THREADS; i++) 
	{
        if (pthread_join(threads[i], NULL) != 0) 
		{
            printf("pthread_join");
            return 1;
        }
    }

    printf("Main threads have terminated.\n");

    return 0;
}
