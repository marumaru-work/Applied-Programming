#include <stdio.h>

double series(double i, double s, double th)
{
    double p = 1 / ((i - 1) * 2 + 1);
    if (p < th)
    {
        return p * s;
    }
    else
    {
        return p * s + series((i + 1), -s, th);
    }
}

int main(void)
{
    double th = 0.0001;  // 閾値
    double s = 1.0;      // 符号
    double p = series(1.0, s, th);
    printf("%f\n", p);

    return 0;
}
