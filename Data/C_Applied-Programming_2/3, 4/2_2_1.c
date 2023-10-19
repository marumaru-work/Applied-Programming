#include <stdio.h>

int factorial(int n)
{
    if (n == 1)
    {
        return 1;
    }
    else
    {
        return n * factorial(n - 1);
    }
}

int main(void)
{
    int n = 10;
    int f = factorial(n);
    printf("%d\n", f);
    
    return 0;
}
