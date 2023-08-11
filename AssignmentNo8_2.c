#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() 
{
    // Process 1
    pid_t pid1 = fork();

    if (pid1 < 0) 
    {
        printf("Fork failed");
        exit(EXIT_FAILURE);
    } 
    else if (pid1 == 0) 
    {
        // Process 2 (child of process 1)
        pid_t pid2 = fork();

        if (pid2 < 0)
         {
            printf("Fork failed");
            exit(EXIT_FAILURE);
        } 
        else if (pid2 == 0) 
        {
            // Process 3 (child of process 2)
            printf("Process 3 (PID: %d) created by Process 2 (PID: %d)\n", getpid(), getppid());
        } 
        else 
        {
            // Process 2 (continued)
            printf("Process 2 (PID: %d) created by Process 1 (PID: %d)\n", getpid(), getppid());
            wait(NULL); // Wait for Process 3 to complete
        }
    } 
      else 
    {
        // Process 1 (continued)
        printf("Process 1 (PID: %d) is the parent of Process 2 (PID: %d)\n", getpid(), pid1);
        wait(NULL); // Wait for Process 2 to complete
    }

    return 0;
}

