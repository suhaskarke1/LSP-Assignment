// main_program.c

#include <stdio.h>
#include <stdbool.h>
#include <dlfcn.h> 
int main() {
    int num;

    printf("Enter a number: ");
    scanf("%d", &num);

    void* prime_handle = dlopen("./libprime.so", RTLD_LAZY); 
    void* perfect_handle = dlopen("./libperfect.so", RTLD_LAZY); 

    if (!prime_handle || !perfect_handle) 
    {
        fprintf(stderr, "Error: %s\n", dlerror());
        return 1;
    }

    bool (*is_prime)(int) = (bool (*)(int))dlsym(prime_handle, "is_prime");
    bool (*is_perfect)(int) = (bool (*)(int))dlsym(perfect_handle, "is_perfect");

    if (!is_prime || !is_perfect) {
        fprintf(stderr, "Error: %s\n", dlerror());
        dlclose(prime_handle);
        dlclose(perfect_handle);
        return 1;
    }

    if (is_prime(num))
     {
        printf("%d is a prime number.\n", num);
    }
     else 
     {
        printf("%d is not a prime number.\n", num);
    }

    if (is_perfect(num)) 
    {
        printf("%d is a perfect number.\n", num);
    } 
    else 
    {
        printf("%d is not a perfect number.\n", num);
    }

    dlclose(prime_handle);
    dlclose(perfect_handle);
    return 0;
}

