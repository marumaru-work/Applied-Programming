#include <stdio.h>

int main(int argc, char const *argv[])
{
    char word[] = "t@a@@@n@@q@@@ku@@n"; // 文字列
    size_t n = sizeof(word) - 1;        // 文字数

    for (int i = 1; i < n; i++)
    {
        int j = i;
        while (word[j] != '@')
        {
            char t = word[j];
            word[j] = word[j - 1];
            word[j - 1] = t;

            if (word[j - 2] != '@')
            {
                break;
            }
            else
            {
                j--;
            }
        }
        // printf("i = %d\t, word = %s\n", i, word);
    }

    printf("%s\n", word); // 入れ替えた結果の表示
    return 0;
}
