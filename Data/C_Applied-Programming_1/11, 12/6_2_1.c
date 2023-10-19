#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_DATA 30000  // データ数
int a[NUM_DATA];        // ソートされるデータ

// 交換関数
void swap(int a[], int i, int j)
{
    int temp = a[i];
    a[i] = a[j];
    a[j] = temp;
}

// 比較関数
int compare(int a[], int i, int j)
{
    if (a[i] > a[j])
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

// バブルソート
void bubbleSort(int a[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = n - 1; j > i; j--)
        {
            if (compare(a, j - 1, j))
            {
                swap(a, j - 1, j);
            }
        }
    }
}

// 選択ソート
void selectionSort(int a[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int m = i;
        for (int j = i + 1; j < n; j++)
        {
            if (compare(a, m, j))
            {
                m = j;
            }
        }
        swap(a, i, m);
    }
}

// 挿入ソート
void insertionSort(int a[], int n)
{
    for (int i = 1; i < n; i++)
    {
        for (int j = i; j > 0 && compare(a, j - 1, j); j--)
        {
            swap(a, j, j - 1);
        }
    }
}

// クイックソート
void quickSort(int a[], int left, int right)
{
    int i, j;   // 交換するデータの添字を記録する変数
    i = left;   // ソートする配列の一番小さい要素の添字
    j = right;  // ソートする配列の一番大きい要素の添字
    int pivot = a[(left + right) / 2];  // ソートする範囲の添字の中央値

    while (1)
    {
        // pivot より大きい値が出現するまで i をインクリメント
        while (a[i] < pivot)
        {
            i++;
        }
        // pivot より小さい値が出現するまで j をデクリメント
        while (pivot < a[j])
        {
            j--;
        }
        // i >= j なら無限ループから抜ける
        if (i >= j)
        {
            break;
        }
        swap(a, i, j);  // a[i] と a[j]を交換
        // ソートする範囲を縮める
        i++;
        j--;
    }
    // 基準値よりも左に 2 つ以上の要素があれば，基準値よりも左をクイックソート
    if (left < i - 1)
    {
        quickSort(a, left, i - 1);
    }
    // 基準値の右に 2 つ以上の要素があれば，基準値よりも右をクイックソート
    if (j + 1 < right)
    {
        quickSort(a, j + 1, right);
    }
}

void initData()
{
    for (int i = 0; i < NUM_DATA; i++)
    {
        a[i] = rand();
    }
}

int main(int argc, char const* argv[])
{
    int loop = 5;       // ソートの実行回数
    int numMethod = 4;  // アルゴリズムの数
    for (int i = 0; i < numMethod; i++)
    {
        // 手法名の表示 (実装する)
        if (i == 0)
        {
            printf("bubbleSort\n");
        }
        else if (i == 1)
        {
            printf("selectionSort\n");
        }
        else if (i == 2)
        {
            printf("insertionSort\n");
        }
        else
        {
            printf("quickSort\n");
        }

        for (int j = 0; j < loop; j++)
        {
            initData();
            int n = sizeof(a) / sizeof(a[0]);  // 配列のサイズ

            // 開始時間の記録
            clock_t cpu_time_start = clock();
            double sec_start = (double)cpu_time_start / CLOCKS_PER_SEC;

            // i の値に従ってソートアルゴリズムを実行 (実装する)
            if (i == 0)
            {
                bubbleSort(a, n);
            }
            else if (i == 1)
            {
                selectionSort(a, n);
            }
            else if (i == 2)
            {
                insertionSort(a, n);
            }
            else
            {
                quickSort(a, 0, n - 1);
            }

            // 終了時間の記録
            clock_t cpu_time_end = clock();
            double sec_end = (double)cpu_time_end / CLOCKS_PER_SEC;
            double result_time = sec_end - sec_start;
            printf("%f sec\n", result_time);
        }
    }

    return 0;
}
