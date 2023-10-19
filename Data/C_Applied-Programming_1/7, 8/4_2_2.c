#include <stdio.h>

void swap(char a[], int i, int j)
{
    printf("swap a[%d] = %c,  a[%d] = %c\n", i, a[i], j, a[j]);

    int temp = a[i];  // i 番目の要素を保存
    a[i] = a[j];      // j 番目の要素を i 番目に代入
    a[j] = temp;      // 保存した値を j 番目に代入
}

void printArray(char a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%c ", a[i]);
    }
    printf("\n");
}

int compare(char a[], int i, int j)
{
    printf("compare a[%d] = %c,  a[%d] = %c\n", i, a[i], j, a[j]);

    if (a[i] > a[j])  // j 番目の要素より i 番目の要素の方が大きい
    { 
        return 1;
    }
    else
    {
        return 0;
    }
}

void bubbleSort(char a[], int n)
{
    for (int i = 0; i < n - 1; i++)     // 0 番目から n - 1 番目までループ
    {  
        for (int j = n - 1; j > i; j--) // n - 1 番目から， i 番目までループ
        {
            if (compare(a, j - 1, j))   // j - 1 番目と j 番目を比較
            {
                swap(a, j - 1, j);      // j - 1 番目と j 番目を交換
            }
            printArray(a, n);
        }
    }
}

int main(int argc, char const *argv[])
{
    char a[] = "tanq";      // ソート前の配列
    int n = sizeof(a) - 1;  // 配列のサイズ

    printArray(a, n);  // ソート前の配列の表示
    bubbleSort(a, n);  // バブルソートの実行
    printArray(a, n);  // ソート後の配列の表示
}

/* n = 4 一番小さいものが、0番目に来る
for (int i = 0; i < 3; i++)     // 0 番目から n - 1 番目までループ
{  
    for (int j = 3; j > 0; j--) // n - 1 番目から， i 番目までループ
    {
        if (compare(a, 2, 3))   // j - 1 番目と j 番目を比較
        {
            swap(a, 2, 3);      // j - 1 番目と j 番目を交換
        }
    }
}
*/
