# include<stdio.h>
# include<fcntl.h>

int main(int argc, char *argv[])
{
	
	char Fname[20];
	int fd=0;
	printf("Enter The File Name That You want to Open :\n");
	scanf("%s",Fname);
	
	fd =open(Fname,O_RDONLY);
	if(fd==-1)
	{
		printf("unable to open the file \n");
		
		return -1;
	}
	else
	{
		printf("File  is Open Succesfully fd With  %d\n",fd);
	}
	return 0;
}
