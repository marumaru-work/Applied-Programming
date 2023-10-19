#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define HEIGHT 2
#define WIDTH 3
int a[HEIGHT][WIDTH] = {{1, 2, 3}, {4, 5, 6}};  // 行列 A
int r[WIDTH][HEIGHT];  // 計算結果の行列 R

void transpose()
{
    for (int i = 0; i < HEIGHT; i++)
    {
        for (int j = 0; j < WIDTH; j++)
        {
            r[j][i] = a[i][j];
        }
    }
}

void printMatrix()
{
    for (int i = 0; i < WIDTH; i++)
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
    transpose();  // 行列 A の転置行列を求める (結果は，行列 R とする)
    printMatrix();  // 計算結果を表示 (行列 R を表示)
    return 0;
}
