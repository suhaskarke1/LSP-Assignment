# include<sys/types.h>
# include<sys/ipc.h>
# include<sys/shm.h>
# include<stdio.h>
# include<unistd.h>
#include<stdlib.h>

# define SHMSZ 30
int main()
{
	char c;
	int shmid;
	char *shm,*s;
	
	printf("Demo of IP Using Shared Memory \n");
	
	key_t key=ftok(".",'a');

shmid=shmget(key,SHMSZ,IPC_CREAT | 0666);

shm=shmat(shmid,NULL,0);

s=shm;

for(c='a';c<='z';c++)
{
 *s =c;
s++;
}

printf("Data is Written in shared Memory \n");

*s='\0';

while(*shm !='*')
{
sleep(1);
}

printf("Data is Successfully fatched bu client \n");

printf("Terminating server \n");

exit(0);

}
	