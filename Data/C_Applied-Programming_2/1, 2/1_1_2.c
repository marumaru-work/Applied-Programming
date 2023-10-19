#include <stdio.h>

void reduce(int *e, int *d)
{
    int f = 2;
    while (*d >= f)
    {
        if (*d % f == 0 && *e % f == 0)
        {
            *d /= f;
            *e /= f;
        }
        else
        {
            f++;
        }
    }
}

int main(void)
{
    int e = 110268;  // 分子
    int d = 72;      // 分母

    printf("%d/%d\n", e, d);
    reduce(&e, &d);
    printf("%d/%d\n", e, d);
}
