#include <stdio.h>

void countCharacter(const char s[], int counter[])
{
    for (int i = 0; s[i] != '.'; i++)
    {
        if (s[i] != ' ' || s[i] != '.')
        {
            int num = s[i] - 'a';
            counter[num]++;
        }
    }
}

int main(int argc, char const *argv[])
{
    char line[] = "c is a general-purpose, procedural computer programming language supporting structured programming.";    // 文字列
    int hist[26] = {0}; // 英語の小文字をカウントする配列
    int n = sizeof(hist) / sizeof(hist[0]);  // ヒストグラムの要素数

    countCharacter(line, hist);  // ヒストグラムの作成
    // ヒストグラムの表示
    for (int i = 0; i < n; i++)
    {
        printf("%c:%d\n", i + 'a', hist[i]);
    }
    return 0;
}
