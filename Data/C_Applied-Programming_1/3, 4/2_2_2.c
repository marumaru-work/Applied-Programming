#include <stdio.h>

#define _and(a, b) ((a) && (b))
#define _or(a, b) ((a) || (b))
#define _xor(a, b) ((a) ^ (b))

int main(int argc, char const *argv[])
{
    int bits[][2] = {{1, 1}, {0, 1}, {1, 0}, {0, 0}}; // 2入力のすべての組み合わせ
    for (int i = 0; i < 4; i++)
    {
        int a = bits[i][0];// i 番目の配列の0番目の要素を取得すること
        int b = bits[i][1];// i 番目の配列の1番目の要素を取得すること

        printf("%d %d %d\n", _and(a, b), _or(a, b), _xor(a, b));
    }
    return 0;
}
