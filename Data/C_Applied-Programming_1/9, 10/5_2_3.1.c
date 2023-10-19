// 選択ソート ver.

#include <stdio.h>

int countSwap = 0;
int countCompare = 0;

void swap(int a[][2], int i, int j)
{
    printf("swap a[%d] = {%d, %d},  a[%d] = {%d, %d}\n", i, a[i][0], a[i][1], j, a[j][0], a[j][1]);
    countSwap += 1;

    int temp[1][2]; // temp配列を初期化
    for (int k = 0; k < 2; k++)
    {
        temp[0][k] = a[i][k]; // [i番目, j番目]の要素を保存
        a[i][k] = a[j][k];    // j 番目の配列を i 番目に代入
        a[j][k] = temp[0][k]; // 保存したtemp配列を j 番目に代入
    }
}

void printArray(int a[][2], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("{%d, %d} ", a[i][0], a[i][1]);
    }
    printf("\n");
}

int compare(int a[][2], int i, int j)
{
    countCompare += 1;
    printf("compare a[%d] = {%d, %d},  a[%d] = {%d, %d}\n", i, a[i][0], a[i][1], j, a[j][0], a[j][1]);
    if (a[i][0] > a[j][0])  // j 番目の要素より i 番目の要素の方が大きい
    {
        return 1;
    }
    else if (a[i][0] == a[j][0])
    {
        if (a[i][1] > a[j][1])
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    else
    {
        return 0;
    }
}

void selectionSort(int a[][2], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int min = i;
        for (int j = i + 1; j < n; j++)
        {
            if (compare(a, min, j))
            {
                min = j;
            }
        }
        swap(a, i, min);
        printArray(a, n);
    }
}

int main(int argc, char const *argv[])
{
    // ソート前の配列
    int a[][2] = {{9, 1}, {7, 1}, {5, 2}, {6, 1}, {8, 3}, {9, 6}, {7, 0}, {5, 3}, {6, 2}, {8, 4}};

    int n = sizeof(a) / sizeof(a[0]); // 配列のサイズ
    
    printArray(a, n);     // ソート前の配列の表示
    selectionSort(a, n);  // 選択ソートの実行
    printArray(a, n);     // ソート後の配列の表示

    printf("比較回数: %d\n", countCompare);  // 比較回数の表示
    printf("交換回数: %d\n", countSwap);     // 交換回数の表示

    return 0;
}
