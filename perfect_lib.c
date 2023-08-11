// perfect_lib.c

#include <stdbool.h>

bool is_perfect(int num) 
{
    int sum = 1;

    for (int i = 2; i * i <= num; i++) 
    {
        if (num % i == 0) 
        {
            sum += i;
            if (i != num / i) 
            {
                sum += num / i;
            }
        }
    }

    return sum == num;
}

