#include <stdio.h>

#define HEIGHT 2
#define WIDTH 3
int a[HEIGHT][WIDTH] = {{1, 2, 3}, {4, 5, 6}};    // 行列 A
int b[WIDTH][HEIGHT] = {{6, 5}, {4, 3}, {2, 1}};  // 行列 B
int r[HEIGHT][HEIGHT] = {{0, 0}, {0, 0}};         // 計算結果の行列 R

void multiplication()
{
    for (int i = 0; i < HEIGHT; i++)
    {
        for (int j = 0; j < HEIGHT; j++)
        {
            for (int k = 0; k < WIDTH; k++)
            {
                r[i][j] += a[i][k] * b[k][j];
                // printf("a[%d][%d]_(%d) * b[%d][%d]_(%d) = r[%d][%d]_(%d)\n", i, k, a[i][k], k, j, b[k][j], i, j, r[i][j]);
            }
        }
    }
    // printf("\n");
}

void printMatrix()
{
    for (int i = 0; i < HEIGHT; i++)
    {
        for (int j = 0; j < HEIGHT; j++)
        {
            printf("%d ", r[i][j]);
        }
        printf("\n");
    }
}

int main(int argc, char const *argv[])
{
    multiplication();  // 行列 A と Bの積を計算して,その結果を行列 R に代入する
    printMatrix();  // 計算結果を表示 (行列 R を表示)
    return 0;
}