#include <math.h> // pow 用
#include <stdio.h>

int main(int argc, char const *argv[])
{
    char bits[] = "00110101";    // 2進数を表す文字列
    size_t n = sizeof(bits) - 1; // 変数 bits のサイズ
    int dec = 0;                 // 10進数の値の保存用
    int exponent = n - 1;        // exponent (指数) = 7;
    for (int i = 0; i < n; i++)
    {
        int a = bits[i] - '0';   // int型に直す
        dec += a * pow(2, exponent);
        exponent--;
    }
    printf("%d\n", dec);         // 合計値を表示
    return 0;
}
