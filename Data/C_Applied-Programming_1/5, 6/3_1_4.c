#include <stdio.h>

int main(int argc, char const *argv[])
{
    char bits[] = "01101100";  // 2進数を表す文字列
    // char bits[] = "1000";  // 2進数を表す文字列
    // char bits[] = "111111";  // 2進数を表す文字列
    size_t n = sizeof(bits) - 1;   // 変数 bits のサイズ
    int f = 0;                 // フラグ

    for (int i = n - 1; i >= 0; i--) // (1.1) bits配列を右から左へ調べる
    {
        if (f) // (2.1) もし、f （フラグ） が 1（真）ならif文の処理を実行
        {
            if (bits[i] == '0') // (2.2 → 2.1へ) 0なら1へ変換する
            {
                bits[i] = '1';
            }
            else // (2.2 → 2.1へ) 1なら0へ変換する
            {
                bits[i] = '0';
            }
        }
        else if (bits[i] == '1') // (1.2) もし、i番目に1が格納されていたら、else if文の処理を実行
        {
            f = 1; // (1.3 → 2.1へ) フラグを立てる (1にする)
        }
    }
    printf("%s\n", bits); // 2の補数の表示
    return 0;
}
