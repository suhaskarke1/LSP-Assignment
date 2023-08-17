#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <signal.h>

void child_process()
 {
    printf("Child process started (PID: %d)\n", getpid());
    while (1) 
	{
        pause();
    }
}

int main()
 {
    printf("Parent process started (PID: %d)\n", getpid());

    pid_t child_pid = fork();

    if (child_pid == -1) 
	{
        perror("fork");
        return 1;
    } 
	else if (child_pid == 0)
		{
        // Child process
        child_process();
    } 
	else
		{
        // Parent process
        printf("Child process spawned with PID: %d\n", child_pid);
        printf("Type 'signal' and press Enter to send signal to the child process.\n");

        char user_input[10];
        while (1) 
		{
            fgets(user_input, sizeof(user_input), stdin);
            if (strcmp(user_input, "signal\n") == 0) 
			{
                kill(child_pid, SIGUSR1);
                printf("Signal sent to child process\n");
            }
        }
    }

    return 0;
}
