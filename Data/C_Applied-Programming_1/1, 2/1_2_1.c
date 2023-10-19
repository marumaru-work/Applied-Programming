#include <stdio.h>
#include <math.h> // pow 用

int main(int argc, char const *argv[])
{
    char bits[] = "0101101"; // 2D
    // char bits[] = "00000"; // 00
    // char bits[] = "1"; // 1
    // char bits[] = "111111111"; // 1FF
    size_t n_bits = sizeof(bits) - 1; // 配列のサイズ
    
    char hex[(n_bits / sizeof(int)) + 1]; // 16進数保存用

    int sum = 0;                           // 4桁ごとの(10進数)合計値を計算するための変数
    char hex_table[] = "0123456789ABCDEF"; // 16進数への変換用テーブル

    int syou = n_bits / 4;
    int amari = n_bits % 4;
    int j = 0, syou_count = 0, amari_count = 0;

    // 2進数から16進数への変換
    for (int i = n_bits, four = 0; i > 0; i--, four++) // 配列のサイズ分、ループ
    {
        if (four == 4)
        {
            four = 0;
        }
        if (syou_count == syou)
        {
            amari_count++;
        }
        sum += (bits[i - 1] - '0') * pow(2, four);  // n_bitesは配列のサイズだが、配列の数え方は0から数えるので1引く
        if (four % 3 == 0 && four != 0 || syou_count == syou && amari_count == amari)
        {
            if (0 < j)
            {
                for (int slide = j; slide > 0; slide--)
                {
                    hex[slide] = hex[slide - 1];
                }
            }
            hex[0] = hex_table[sum];
            j++;
            syou_count++;
            sum = 0;
        }
    }
    
    // 16進数の表示
    for (int i = 0; i < sizeof(hex); i++)
    {
        printf("%c", hex[i]);
    }
    printf("\n");
    return 0;
}
