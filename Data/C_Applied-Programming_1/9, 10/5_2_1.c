#include <stdio.h>

int countSwap = 0;
int countCompare = 0;

void swap(int a[], int i, int j)
{
    printf("swap a[%d] = %d,  a[%d] = %d\n", i, a[i], j, a[j]);
    countSwap += 1;
    int temp = a[i];  // i 番目の要素を保存
    a[i] = a[j];      // j 番目の要素を i 番目に代入
    a[j] = temp;      // 保存した値を j 番目に代入
}

void printArray(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
}

int compare(int a[], int i, int j)
{
    countCompare += 1;
    printf("compare a[%d] = %d,  a[%d] = %d\n", i, a[i], j, a[j]);
    if (a[i] > a[j])  // j 番目の要素より i 番目の要素の方が大きい
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void selectionSort(int a[], int n)
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
    int a[] = {9, 7, 5, 6, 8};  // ソート前の配列
    // int a[] = {9, 8, 7, 6, 5};  // ソート前の配列
    // int a[] = {5, 6, 7, 8, 9};         // ソート前の配列
    // int a[] = {5, 6, 8, 7, 9};         // ソート前の配列

    int n = sizeof(a) / sizeof(a[0]);  // 配列のサイズ

    printArray(a, n);     // ソート前の配列の表示
    selectionSort(a, n);  // 選択ソートの実行
    printArray(a, n);     // ソート後の配列の表示

    printf("比較回数: %d\n", countCompare);  // 比較回数の表示
    printf("交換回数: %d\n", countSwap);     // 交換回数の表示
}
