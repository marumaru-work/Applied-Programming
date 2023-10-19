#include <stdio.h>

int main(int argc, char const *argv[])
{
    char word[] = "t@a@@@n@@q@@@ku@@n"; // 文字列(18文字)
    size_t n = sizeof(word) - 1;        // 文字数
    
    printf("%s\n", word);
    for (int i = 0; i < n - 1; i++) // 16回繰り返す
    {
        for (int j = n - 1; j > i; j--) // 17番目から開始
        {
            // printf("word[%d] = %c ←→ word[%d] = %c\n", j - 1, word[j - 1], j, word[j]);
            if (word[j] != '@' && word[j - 1] == '@')
            {
                char t = word[j - 1];
                word[j - 1] = word[j];
                word[j] = t;
            }
            // printf("i = %d, j = %d\t, word = %s\n", i, j, word);
        }
    }

    printf("%s\n", word); // 入れ替えた結果の表示
    return 0;
}
