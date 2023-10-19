#include <stdio.h>
#define N 10

int data[N][N] =
{
    {-1, -1, 0, 0, 0, 0, 0, 0, 0, 0},    {0, -1, 0, 0, 0, -1, -1, -1, 0, 0},
    {0, 0, -1, 0, 0, -1, 0, -1, 0, 0},   {0, 0, 0, -1, 0, 0, -1, -1, -1, 0},
    {0, -1, 0, 0, 0, 0, -1, -1, 0, 0},   {-1, 0, -1, -1, 0, 0, 0, 0, -1, -1},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},      {0, 0, -1, -1, 0, 0, 0, -1, -1, -1},
    {-1, -1, 0, 0, -1, 0, 0, -1, 0, -1}, {-1, -1, 0, 0, 0, -1, 0, -1, -1, -1}
};

void printData()
{
    for (int x = 0; x < N; x++)
    {
        printf("---");
    }
    printf("\n");
    for (int y = 0; y < N; y++)
    {
        for (int x = 0; x < N; x++)
        {
            printf(" %2d", data[y][x]);
        }
        printf("\n");
    }
}

// 自作関数 (この問題において、自作関数と再帰関数の使用は禁止事項に記載されていない)
// main 関数に処理をコーディングするよりも自作関数(再帰関数)に処理をコーディングした方が楽である。
void blockcheck(int y, int x, int group)
{
    for (int i = -1; i <= 1; i += 2)
    {
        if (data[y + i][x] == -1 && y + i >= 0 && y + i < N)
        {
            data[y + i][x] = group;
            // printf("data[%d][%d]: %d\n", y + i, x, group);
            blockcheck(y + i, x, group); // 再帰関数
        }
        if (data[y][x + i] == -1 && x + i >= 0 && x + i < N)
        {
            data[y][x + i] = group;
            // printf("data[%d][%d]: %d\n", y, x + i, group);
            blockcheck(y, x + i, group); // 再帰関数
        }
    }
}

int main(void)
{
    printData();  // 初期状態の表示

    int group = 1;
    // printf("------------------------------\n");
    for (int y = 0; y < N; y++)
    {
        for (int x = 0; x < N; x++)
        {
            if (data[y][x] == -1)
            {
                data[y][x] = group;
                // printf("data[%d][%d]: %d\n", y, x, group);
                blockcheck(y, x, group);
                group++;
            }
        }
    }

    printData();  // 結果の表示

    return 0;
}

/*
詳しい処理が見たい場合は、コメントアウトしてある printf 関数 も一緒に実行してあげると処理内容が見れる。
*/
