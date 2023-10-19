#include <stdio.h>

int main(int argc, char const *argv[])
{
    char bits[] = "01110101";    // 2進数を表す文字列
    size_t n = sizeof(bits) - 1; // 変数 bits のサイズ
    int c = 0;                   // 0か1のいずれか一方の値を数えるカウンタ
    for (int i = 0; i < n; i++)
    {
        if (bits[i] == '0')
        {
            c++;
        }
    }
    printf("0: %d\n", c);   // 0 の数を表示
    printf("1: %d\n", n - c); // 1 の数を表示
    return 0;
}
