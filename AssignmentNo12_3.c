# include<stdio.h>
# include<sys/wait.h>
# include<stdlib.h>
# include<unistd.h>
# include<string.h>

# define ReadEnd 0
# define WriteEnd 1

int main()
{
	int pipeFDs[2];
	char buf;
	const char* msg="Marvellous Infosystem \n";
	
	printf("Demnstration of IPC using Unnamed Pipe\n");
	
	if(pipe(pipeFDs)<0)
	{
		perror("Pipe Creation Failed");
		exit(-1);
	}
	
	pid_t cpid=fork();
	
	if(cpid <0)
	{
		perror("Fork Failed");
		exit(-1);
	}
	
	if(0==cpid)
	{
		printf("Child Process is Running \n");
		
	close(pipeFDs[WriteEnd]);
	
	
	printf("Data received from Parent Process \n");
	
	while(read(pipeFDs[ReadEnd],&buf,1)>0)
	{
		write(STDOUT_FILENO,&buf,sizeof(buf));
	}
	
	close(pipeFDs[ReadEnd]);
	_exit(0);
	}
	else
	{
		printf("Parent Process is Running \n");
		
		close(pipeFDs[ReadEnd]);
		
		write(pipeFDs[WriteEnd],msg,strlen(msg));
		
		close(pipeFDs[WriteEnd]);
		
		printf("Data is Successfully Written into pipe by Parent Process \n");
		
		wait(NULL);
		
		exit(0);
		
	}
	return 0;
}

		
	