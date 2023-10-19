#include <stdio.h>

int main(int argc, char const *argv[])
{
    char word[] = "tanq";         // 暗号化したい文
    size_t n = sizeof(word) - 1;  // 暗号化したい文のサイズ
    char encryption[n];           // 暗号化された文
    char decryption[n];           // 複合された文
    int key = 5;                  // 暗号化キー

    // 暗号化の処理
    for (size_t i = 0; i < n; i++)
    {
        encryption[i] = word[i] + key;
    }
    printf("%s\n", encryption); // 暗号文の表示

    // 複合の処理
    for (size_t i = 0; i < n; i++)
    {
        decryption[i] = encryption[i] - key;
    }
    printf("%s\n", decryption); // 複合文の表示
    return 0;
}
