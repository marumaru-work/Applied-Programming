#include <stdio.h>

int factorial(int a)
{
    for (int i = a - 1; i > 0; i--)
    {
        a *= i;
    }
    return a;
}

int main(int argc, char const *argv[])
{
    int a = 5;
    printf("%d\n", factorial(a));
    return 0;
}
