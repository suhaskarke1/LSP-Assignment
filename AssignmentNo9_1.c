#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <dirent.h>

int main(int argc,char*argv[]) 

{
   
   char dirName[20];
    pid_t pid = fork();

    if (pid < 0)
     {
        printf("Failed to fork process.\n");
        return -1;
    }
    
     else if (pid == 0) 
     
     {
        
        DIR *dir = opendir("/home/suhas/Desktop/LSP"); 

        if (dir == NULL) 
        {
            printf("Failed to open directory.\n");
            return -1;
        }

        
        FILE *demoFile = fopen("demo.txt", "w");

        if (demoFile == NULL) 
        {
            printf("Failed to create/open demo.txt.\n");
            closedir(dir);
            return 1;
        }

        struct dirent *entry;
        while ((entry = readdir(dir)) != NULL) 
        {
            if (entry->d_type == DT_REG) 
            {
                fprintf(demoFile, "%s\n", entry->d_name);
            }
        }

        
        closedir(dir);
        fclose(demoFile);

        printf("File names written to demo.txt.\n");
    } 
    else 
    {
        
        wait(NULL); 
    }

    return 0;
}

