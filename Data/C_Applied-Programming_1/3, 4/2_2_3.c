#include <stdio.h>

#define not(a) (!(a))

int main(int argc, char const *argv[])
{
    int bits[][2] = {{1, 1}, {0, 1}, {1, 0}, {0, 0}}; // 2入力のすべての組み合わせ
    for (int i = 0; i < 4; i++)
    {

        int a = bits[i][0]; // i 番目の配列の0番目の要素を取得すること
        int b = bits[i][1]; // i 番目の配列の1番目の要素を取得すること
        int r = (not(a) && b) || (not(a) && not(b)); // 論理式を書く

        printf("%d %d %d\n", a, b, r);
    }
    return 0;
}
