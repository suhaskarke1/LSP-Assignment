#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <unistd.h>

int main() 
{
    const char *file_path = "file1.txt";
    int fd = open(file_path, O_RDONLY);
    
	if (fd == -1) 
	{
        perror("open");
        exit(EXIT_FAILURE);
    }

    // Get the size of the file
    struct stat file_stat;
    if (fstat(fd, &file_stat) == -1)
		{
        perror("fstat");
        close(fd);
        exit(EXIT_FAILURE);
    }
    off_t file_size = file_stat.st_size;

    // Map the file into memory
    void *mapped_ptr = mmap(NULL, file_size, PROT_READ, MAP_PRIVATE, fd, 0);
    if (mapped_ptr == MAP_FAILED)
		{
        perror("mmap");
        close(fd);
        exit(EXIT_FAILURE);
    }

    // Close the file descriptor, as it's no longer needed
    close(fd);

    // Now you can read data from the mapped memory
    printf("Contents of the mapped file:\n");
    printf("%.*s\n", (int)file_size, (char *)mapped_ptr);

    // Unmap the memory
    if (munmap(mapped_ptr, file_size) == -1) 
	{
        perror("munmap");
        exit(EXIT_FAILURE);
    }

    return 0;
}
