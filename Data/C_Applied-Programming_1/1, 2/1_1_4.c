#include <stdio.h>
#include <math.h> // pow 用

int main(int argc, char const *argv[])
{
    char hex = 'A';                        // 16進数の値
    char hex_table[] = "0123456789ABCDEF"; // 16進数への変換用テーブル
    int n_hex_table = sizeof(hex_table);   // 変数 hex_table のサイズ
    int i = 0;                             // インデックス
    for (; i < n_hex_table; i++)
    {
        if (hex == hex_table[i])
        {
            break;
        }
    }
    printf("%c %d\n", hex, i); // 10進数への変換結果の表示
    return 0;
}
