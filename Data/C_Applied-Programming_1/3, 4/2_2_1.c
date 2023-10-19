#include <stdio.h>

int main(int argc, char const *argv[])
{
    int bits[][2] = {{1, 1}, {0, 1}, {1, 0}, {0, 0}}; // 2入力のすべての組み合わせ
    size_t n = sizeof(bits) / sizeof(bits[0]);        // 変数 bits の要素数

    for (int i = 0; i < n; i++)
    {
        int a = bits[i][0]; // i 番目の配列の0番目の要素を取得すること
        int b = bits[i][1]; // i 番目の配列の1番目の要素を取得すること

        printf("%d %d\n", a, b);
    }

    return 0;
}
