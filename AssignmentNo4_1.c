#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

int main(int argc, char *argv[]) 
{
	int fd=0;
	int fd1 =0;
    if (argc != 3) 
	{
        printf("Insufficent arguments \n");
        return -1;
    }

    // Open the input file for reading
    fd= open(argv[1], O_RDONLY);
    if (fd == -1) 
	{
        perror("Error opening input file");
        return -1;
    }

    // Open or create the output file for writing
    fd1 =  open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
  
    if (fd1== -1) 
	{
        perror("Error opening output file");
        return -1;
    }

    // Redirect standard input to the input file
    if (dup2(fd, STDIN_FILENO) == -1) 
	{
        perror("Error redirecting standard input");
        return 1;
    }

    // Redirect standard output to the output file
    if (dup2(fd1, STDOUT_FILENO) == -1)
		{
        perror("Error redirecting standard output");
        return 1;
    }

    // Now we can read from the input file and write to the output file
    char buffer[1024];
    ssize_t bytesRead;

    while ((bytesRead = read(STDIN_FILENO, buffer, sizeof(buffer))) > 0) {
        if (write(STDOUT_FILENO, buffer, bytesRead) == -1) 
		{
            perror("Error writing to output file");
            return 1;
        }
    }

    // Close file descriptors and return
    close(fd);
    close(fd1);

    return 0;
}
