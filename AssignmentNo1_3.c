#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char *argv[])
 {
    if (argc != 3) 
	{
        printf("Invalid Arguments \n");
       
	   return 1;
    }

    char *file_name = argv[1];
    char *mode = argv[2];

    int access_mode;
    if (mode[0] == 'r')
		
        access_mode = R_OK; 		// Read access
   
   else if (mode[0] == 'w')
        access_mode = W_OK;  // Write access
   else if(mode[0]=='x')
	   access_mode=X_OK;      //execute mode
   else 
	{
        printf("Invalid access mode.\n");
        return 1;
    }

    int status = access(file_name, access_mode);

    if (status == 0)
		{
        printf("You can access %s file in %s mode \n",argv[1],argv[2]);
    } 
	else 
	{
        printf("Unable to access %s file in %s mode \n",argv[1],argv[2]);
    }

    return 0;
}
