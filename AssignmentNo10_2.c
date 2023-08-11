# include<stdio.h>
# include<stdlib.h>
# include<unistd.h>
# include<pthread.h>

void * ThreadProc1(void *ptr)
{
int iCnt=0;

for(iCnt=0;iCnt<=500;iCnt++)
{
	printf("Thread 1 is %d \n",iCnt);
}
pthread_exit(NULL);
}
void * ThreadProc2(void *ptr)
{
int iCnt=0;

for(iCnt=500;iCnt>=0;iCnt--)
{
	printf("Thread 2 is %d \n",iCnt);
}
pthread_exit(NULL);
}

int main()
{
	
	pthread_t TID1,TID2;
	
	int ret1=0,ret2=0;
	
	ret1=pthread_create(&TID1,NULL,ThreadProc1,NULL);
	
	if(ret1 !=0)
	{
		printf("Unable to Create thread \n");
		return -1;
	}
	
	printf("Thread1 is created with Id : %d \n",TID1);
	
	ret2=pthread_create(&TID2,NULL,ThreadProc2,NULL);
	
	if(ret2 !=0)
	{
		printf("Unable to create Thread \n");
		return -1;
	}
	
	printf("Thread 2 is Created with Id : %d \n",TID2);
	
	pthread_join(TID1,NULL);
	pthread_join(TID2,NULL);
	
	printf("End of main thread \n");
	
	pthread_exit(NULL);
	
	return 0;
}

	