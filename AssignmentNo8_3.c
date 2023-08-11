#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


void process_4() 
{
    printf("Process 4 (PID: %d) created by Process 2 (PID: %d)\n", getpid(), getppid());
}

void process_3() 
{
    pid_t pid4 = fork();

    if (pid4 < 0) 
    {
        printf("Fork failed");
        exit(EXIT_FAILURE);
    } 
    else if (pid4 == 0) 
    {
        // Process 4 (child of process 3)
        process_4();
    } 
    else 
    {
        // Process 3 (continued)
        printf("Process 3 (PID: %d) created by Process 2 (PID: %d)\n", getpid(), getppid());
        wait(NULL); // Wait for Process 4 to complete
    }
}

void process_2() 
{
    pid_t pid3 = fork();

    if (pid3 < 0) 
    {
        printf("Fork failed");
        exit(EXIT_FAILURE);
    } 
    else if (pid3 == 0) 
    {
        // Process 3 (child of process 2)
        process_3();
    }
     else 
     {
        // Process 2 (continued)
        printf("Process 2 (PID: %d) created by Process 1 (PID: %d)\n", getpid(), getppid());
        wait(NULL); // Wait for Process 3 to complete
    }
}

int main() {
    // Process 1
    pid_t pid2 = fork();

    if (pid2 < 0) 
    {
        printf("Fork failed");
        exit(EXIT_FAILURE);
    } 
    else if (pid2 == 0) {
        // Process 2 (child of process 1)
        process_2();
    } 
    else 
    {
        // Process 1 (continued)
        printf("Process 1 (PID: %d) is the parent of Process 2 (PID: %d)\n", getpid(), pid2);
        wait(NULL); // Wait for Process 2 to complete
    }

    return 0;
}

