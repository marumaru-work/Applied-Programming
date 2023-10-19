#include <stdio.h>

void reverseCopy(char str1[], char str2[])
{
    char *str1_start = str1;

    while (*str1++) {}
    str1 -= 2;

    while (1)
    {
        *str2 = *str1;
        // printf("str2: %c (%p), str1: %c (%p)\n", *str2, str2, *str1, str1);
        if (str1_start == str1)
        {
            *++str2 = 0;
            break;
        }
        str2++; str1--;
    }
}

int main(void)
{
    char str1[] = "abcdefghijklmnopqrstuvwxyz";
    char str2[30];
    reverseCopy(str1, str2);
    printf("str1: %s\n", str1);
    printf("str2: %s\n", str2);

    return 0;
}
