#include <stdio.h>

void printString(int idxStart, int idxEnd, char word[])
{
    for (int i = idxStart; i < idxEnd; i++)
    {
        printf("%c", word[i]);
    }

    printf("\n");
}

int main(int argc, char const *argv[])
{
    char line[] = "tantanqtatanq";     // 被検索対象の文字列
    size_t n_line = sizeof(line) - 1;  // 被検索対象の文字列のサイズ
    char target[] = "tanq";            // 検索する文字列
    size_t n_target = sizeof(target) - 1;  // 検索する文字列のサイズ

    int i = 0;
    while (i < n_line - n_target + 1)
    {
        int j = 0;  // 変数 target 用のカウンタ
        int c = 0;  // 一致する文字数のカウンタ

        while (j < n_target)
        {
            if (line[i + j] == target[j]) 
            {
                c++;
            }
            else
            {
                break;
            }
            j++;
        }

        printString(0, j, target);

        if (c == n_target)
        {
            printf("%d\n", i);
        }

        i += j;
    }

    return 0;
}
