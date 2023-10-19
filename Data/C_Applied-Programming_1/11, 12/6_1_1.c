#include <stdio.h>

#define HEIGHT 3
#define WIDTH 2

int a[HEIGHT][WIDTH] = {{3, 2}, {1, 3}, {5, 8}};  // 行列 A
int b[HEIGHT][WIDTH] = {{1, 3}, {5, 4}, {3, 1}};  // 行列 B
int r[HEIGHT][WIDTH] = {{0, 0}, {0, 0}, {0, 0}};  // 計算結果の行列 R

void sum()
{
    for (int i = 0; i < HEIGHT; i++)
    {
        for (int j = 0; j < WIDTH; j++)
        {
            r[i][j] = a[i][j] + b[i][j];
        }
    }
}

void printMatrix()
{
    for (int i = 0; i < HEIGHT; i++)
    {
        for (int j = 0; j < WIDTH; j++)
        {
            printf("%d ", r[i][j]);
        }
        printf("\n");
    }
}

int main(int argc, char const *argv[])
{
    sum();  // 行列 A と B の和を計算して，その結果を行列 R に代入する
    printMatrix();  // 計算結果を表示 (行列 R を表示)
    return 0;
}
