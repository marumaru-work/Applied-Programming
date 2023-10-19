#include <stdio.h>

double m[100];  // 計算結果の保存用の配列

double fibonacci(int n)
{
    if (m[n] == 0)
    {
        if (n < 2)
        {
            return n;
        }
        else
        {
            double t = fibonacci(n - 1) + fibonacci(n - 2);
            m[n] = t;
            return m[n];
        }
    }
    else
    {
        return m[n];
    }
}

int main(void)
{
    int n = 70;
    double f = fibonacci(n);
    printf("%lf\n", f);
    return 0;
}
