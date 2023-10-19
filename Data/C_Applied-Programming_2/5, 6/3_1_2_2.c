#include <stdio.h>

double m[100];  // 計算結果の保存用の配列

double fibonacci(int n)
{
    double *p = m;
    if (*(p + n) == 0)
    {
        if (n < 2)
        {
            return n;
        }
        else
        {
            double t = fibonacci(n - 1) + fibonacci(n - 2);
            *(p + n) = t;
            return *(p + n);
        }
    }
    else
    {
        return *(p + n);
    }
}

int main(void)
{
    int n = 70;
    double f = fibonacci(n);
    printf("%lf\n", f);
    return 0;
}

/*
配列操作ではなく、ポインタ操作でしてみました。提出は配列操作の方 (3_1_2_1.c) だと思います。
ポインタ操作見にくいですね。
*/
