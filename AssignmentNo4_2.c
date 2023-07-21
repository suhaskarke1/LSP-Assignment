# include<stdio.h>
# include<stdlib.h>
# include<string.h>
# include<unistd.h>
# include<fcntl.h>
# include<dirent.h>
# include<sys/stat.h>

int main(int argc,char *argv[])
{
   char DirName[20];
   DIR *dp=NULL;
   struct dirent *entry=NULL;
   
   printf("Enter name of Directory \n");
   scanf("%s",DirName);
   
   dp =mkdir(DirName,0777);
   if(dp==NULL)
   {
    printf("create Directory successfully \n");
	return -1;
	}
	else
	{
		printf("Unable create Directory  \n");
		
	   return 1;
	}
	return 0;
	}
	