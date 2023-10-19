#include <stdio.h>

int combination(int n, int r)
{
    if (r == 0 || n == r)
    {
        return 1;
    }
    else if (r == 1)
    {
        return n;
    }
    else if (n < r)
    {
        return 0;
    }
    else
    {
        return combination(n - 1, r - 1) + combination(n - 1, r);
    }
}

int main(void)
{
    int arN[3] = {1, 5, 9};
    int arR[3] = {0, 3, 5};
    for (int i = 0; i < 3; i++)
    {
        int n = arN[i];
        for (int j = 0; j < 3; j++)
        {
            int r = arR[j];
            int c = combination(n, r);  // 組み合わせ
            printf("%dC%d: %d\n", n, r, c);
        }
    }
    return 0;
}
