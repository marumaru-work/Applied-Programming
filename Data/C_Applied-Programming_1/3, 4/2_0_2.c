#include <stdio.h>

#define _or(a, b) ((a) || (b)) // 論理和 OR 演算子
#define _xor(a, b) ((a) ^ (b)) // 排他的論理和(排他 OR 演算子) (どちらかが真ならば1、それ以外は0(どちらも真の場合も0))

int main(int argc, char const *argv[])
{
    int a = 1;
    int b = 1;
    printf("%d\n", _or(a, b));
    printf("%d\n", _xor(a, b));
    return 0;
 }
