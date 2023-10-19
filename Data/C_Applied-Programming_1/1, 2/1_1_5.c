#include <stdio.h>
#include <math.h>

int main(int argc, char const *argv[])
{
    int v = 57; // 10進数の値
    // int v = 0; // 10進数の値
    // int v = 1; // 10進数の値

    int b = 0;         // 2進数の値を保存する用の変数
    int exponent = 0;  // 指数
    while (v != 0)
    {
        b += (v % 2) * pow(10, exponent);
        exponent++;
        v /= 2;
    }
    printf("%d\n", b);
    return 0;
}
