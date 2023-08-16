# include<sys/types.h>
# include<sys/ipc.h>
# include<sys/shm.h>
# include<stdio.h>
# include<stdlib.h>

# define SHMSZ 30

int main()
{
	int shmid;
	key_t key;
	char *shm,*s;
	
	printf("Demo of using Shared Memory \n");
	
	printf("Client is Running \n");
	
	key=ftok(".",'a');
	
	shmid=shmget(key,SHMSZ,0666);
	
	shm=shmat(shmid,NULL,0);
	
	printf("Data Received from Server\n");
	
	for(s =shm; *s !='\0';s++)
	{
		printf("%c",*s);
	}
	
	*shm='*';
	printf("\nTerminating the client \n");
	
	exit (0);
}
