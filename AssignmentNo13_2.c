#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>

void child_handler(int signal_num) 
{
    printf("Child process received signal from parent\n");
}

int main() 
{
    pid_t child_pid;

    // Create a child process
    child_pid = fork();

    if (child_pid < 0) 
	{
        perror("Fork failed");
        exit(EXIT_FAILURE);
    } 
	else if (child_pid == 0) 
	{
        // Child process

        // Register a signal handler for the child process
        signal(SIGUSR1, child_handler);

        printf("Child process waiting for signal from parent\n");
        while (1) 
		{
            // Child process waits for signals forever
            sleep(1);
        }
    } 
	else 
	{
        // Parent process

        // Wait for a moment to ensure child process is ready
        sleep(1);

        // Send a signal to the child process
        printf("Parent process sending signal to child\n");
        kill(child_pid, SIGUSR1);

        // Wait for the child process to finish
        wait(NULL);

        printf("Parent process finished\n");
    }

    return 0;
}
