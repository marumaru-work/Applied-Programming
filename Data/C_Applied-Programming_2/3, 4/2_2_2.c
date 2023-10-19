#include <stdio.h>

int getNumberOfDigits(int d)
{
    if (d == 0 || d == 1)
    {
        return 1;
    }
    else
    {
        return getNumberOfDigits(d / 2) + 1;
    }
}

int main(void)
{
    int data[] = {0, 1, 2, 128, 71, 6301}; // 2進数
    int n = sizeof(data) / sizeof(data[0]);
    for (int i = 0; i < n; i++)
    {
        int d = data[i];
        printf("%d: %d\n", d, getNumberOfDigits(d));
    }

    return 0;
}

/*
【再帰関数の考え方】 (ex) d = 128 とする。

No.1 : getNumberOfDigits(128 / 2) → return 1 |→ d = 7 + 1 = 8 → main関数へreturnする
No.2 : getNumberOfDigits( 64 / 2) → return 1 |→ d = 6 + 1 = 7 → No.1へreturnする
No.3 : getNumberOfDigits( 32 / 2) → return 1 |→ d = 5 + 1 = 6 → No.2へreturnする
No.4 : getNumberOfDigits( 16 / 2) → return 1 |→ d = 4 + 1 = 5 → No.3へreturnする
No.5 : getNumberOfDigits(  8 / 2) → return 1 |→ d = 3 + 1 = 4 → No.4へreturnする
No.6 : getNumberOfDigits(  4 / 2) → return 1 |→ d = 2 + 1 = 3 → No.5へreturnする
No.7 : getNumberOfDigits(  2 / 2) → return 1 |→ d = 1 + 1 = 2 → No.6へreturnする
No.8 : 2 / 2 = 1 → if (d == 0 || d == 1) { return 1; } → No.7へreturnする

何もしなければ、No.8の return された 1 がどんどん返っていき、最終的には main 関数に 1 が return されてしまう。
そこで、 return されるごとに 1 を加算してあげることで、2進数の桁を数えることができる。
d = 0 の場合は、そのまま再帰せずに、if文内で return 1 されるため、main関数に 1 が返される。
*/
