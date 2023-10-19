#include <stdio.h>

#define _and(a, b) ((a) && (b)) // 論理積 AND 演算子

int main(int argc, char const *argv[])
{
    int a = 1;
    int b = 1;
    printf("%d\n", _and(a, b));
    return 0;
 }
