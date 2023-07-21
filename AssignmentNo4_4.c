#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <fcntl.h>
#include <unistd.h>

#define BUFFER_SIZE 10

int main(int argc, char *argv[])
 {
	  char *dir_name = argv[1];
    char buffer[BUFFER_SIZE];
	int fd=0;
	int fd1=0;
	  struct dirent *entry;
    if (argc != 2) 
	{
        printf("Insufficent Arguments");
        return -1;
    }


    DIR *dir = opendir(dir_name);

    if (dir == NULL) 
	{
        perror("Error opening directory");
        return -1;
    }

    fd = open("Demo.txt", O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
    if (fd == -1) 
	{
        perror("Error creating Demo.txt");
        closedir(dir);
        return -1;
    }

  
    while ((entry = readdir(dir)) != NULL) 
	{
        if (entry->d_type == DT_REG) // Check if it's a regular file
		{ 
            char file_path[200];
            snprintf(file_path, sizeof(file_path), "%s/%s", dir_name, entry->d_name);

            int fd1 = open(file_path, O_RDONLY);
            if (fd1 == -1) {
                perror("Error opening file");
                continue;
            }

            ssize_t bytes_read = read(fd1, buffer, BUFFER_SIZE);
            if (bytes_read == -1) {
                perror("Error reading from file");
                close(fd1);
                continue;
            }

            close(fd1);

            if (bytes_read > 0) {
                ssize_t bytes_written = write(fd, buffer, bytes_read);
                if (bytes_written == -1) {
                    perror("Error writing to Demo.txt");
                    close(fd);
                    closedir(dir);
                    return -1;
                }
            }
        }
    }

    close(fd);
    closedir(dir);
    printf("Data from regular files copied to Demo.txt successfully.\n");
    return 0;
}
