#include <stdio.h>

int main(int argc, char const *argv[])
{
    char word[] = "t@a@@@n@@q@@@ku@@n";  // 文字列
    size_t n = sizeof(word) - 1;         // 文字数

    for (int i = 0; i < n; i++)
    {
        char c = word[i];  // i 番目の文字
        if (c != '@')
        {
            printf("%c", c);
        }
    }
    printf("\n");
    return 0;
}
