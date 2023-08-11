// main.c

#include <stdio.h>
#include "sharedfile.h" // Assuming you have a header file for the library function

int main() {
    char filename[100];

    printf("Enter the file name: ");
    scanf("%s", filename);

    display_file_info(filename);

    return 0;
}

