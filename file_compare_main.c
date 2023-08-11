// file_compare_main.c

#include <stdio.h>
#include <dlfcn.h> // For Linux, or use windows.h for Windows

int main() {
    const char* file1 = "file1.txt";
    const char* file2 = "file2.txt";

    void* handle;
    int (*compare_files)(const char*, const char*);
    char* error;

    handle = dlopen("./libfilecompare.so", RTLD_LAZY); // For Linux, use "./libfilecompare.dll" for Windows

    if (!handle) {
        fprintf(stderr, "Error: %s\n", dlerror());
        return 1;
    }

    compare_files = (int (*)(const char*, const char*))dlsym(handle, "compare_files");

    if ((error = dlerror()) != NULL) {
        fprintf(stderr, "Error: %s\n", error);
        dlclose(handle);
        return 1;
    }

    int result = compare_files(file1, file2);

    if (result == -1) {
        printf("Error occurred while comparing the files.\n");
    } else if (result == 1) {
        printf("Files are identical.\n");
    } else {
        printf("Files are different.\n");
    }

    dlclose(handle);
    return 0;
}

