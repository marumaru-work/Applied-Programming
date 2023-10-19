#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char const *argv[])
{
    int values[10];  // 配列 values の宣言
    int nValues = sizeof(values) / sizeof(values[0]);  // 配列 values の要素数

    srand(time(NULL));  // 乱数のシード

    // 配列 values の初期化
    for (int i = 0; i < nValues; i++) 
    {
        values[i] = i;
    }

    // 配列 values を表示 (前)
    printf("before shuffle\n");
    for (int i = 0; i < nValues; i++)
    {
        printf(" %d", values[i]);
    }
    printf("\n");

    // 配列の最後尾から1番目の要素までループする (0番目では無い，ループ変数を i とする)
    for (int i = nValues - 1; i > 0; i--)
    {
        // 0 以上 i 以下の int 型の乱数を1つ得る (変数 j とする)
        int j = rand() % i;

        // 配列の i 番目の要素と j 番目の要素を入れ替える
        int temp = values[i];
        values[i] = values[j];
        values[j] = temp;

        // printf("values[%d] = %d ←→ values[%d] = %d\n", i, values[i], j, values[j]);
    }

    // 配列 values を表示 (後)
    printf("after shuffle\n");
    for (int i = 0; i < nValues; i++)
    {
        printf(" %d", values[i]);
    }
    printf("\n");

    return 0;
}
