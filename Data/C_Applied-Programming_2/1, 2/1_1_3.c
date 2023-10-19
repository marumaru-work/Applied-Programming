#include <stdio.h>

void swapcase(char str[])
{
   int small = 'a';             // (int) 97
   int difference = 'a' - 'A';  // (int) 42
   int flag = 0;
    while (1)
    {
        if (*str == (char) 0)
        {
            break;
        }
        // 大文字
        for (int big = 'A'; big <= 'Z'; big++)
        {
            if (*str == (char) big)
            {
                *str = (char)(big + difference);
                flag = 1;
                break;
            }
        }
        // 小文字 (大文字がなければ小文字を調べる)
        if (flag == 0)
        {
            for (int small = 'a'; small <= 'z'; small++)
            {
                if (*str == (char) small)
                {
                    *str = (char)(small - difference);
                    break;
                }
            }
        }
        str++;
        flag = 0;
    }
}

int main(void)
{
    char str[] = "0Abc3De1f@GHijk2lmN5OPZz";

    printf("before: %s\n", str);
    swapcase(str);  // 大文字と小文字を入れ替え
    printf("after: %s\n", str);

    return 0;
}
