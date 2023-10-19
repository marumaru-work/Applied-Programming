#include <stdio.h>

int toHash(char *s)
{
    int i = 0;
    while (*s)
    {
        i += *s++;
    }
    return i % 100;
}

int main(void)
{
    char str[64];
    puts("文字列をハッシュ値に変換します．");
    printf("文字列を入力して下さい: ");
    scanf("%s", str);
    printf("Result: %d\n", toHash(str));
    return 0;
}
