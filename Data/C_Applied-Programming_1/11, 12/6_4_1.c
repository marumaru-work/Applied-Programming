#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_DATA 75  // データ数
#define HEIGHT 10  // マップの横幅
#define WIDTH 10   // マップの縦幅
#define Empty -1   // 空マス
#define k 4        // グループの個数

int data[NUM_DATA][2];  // データ
int group[NUM_DATA];  // それぞれのデータが属するグループの値

void initData()
{
    for (int i = 0; i < NUM_DATA; i++)
    {
        data[i][0] = Empty;
        data[i][1] = Empty;
    }

    for (int i = 0; i < NUM_DATA; i++)
    {
        while (1)
        {
            int y = rand() % HEIGHT;
            int x = rand() % WIDTH;
            int count = -1;

            for (int j = 0; j <= i; j++)
            {
                if (data[j][0] != y || data[j][1] != x)
                {
                    count++;
                }
                else
                {
                    break;
                }
            }
            if (count == i)
            {
                data[i][0] = y;
                data[i][1] = x;
                
                break;
            }
        }
    }
}

void initGroup()
{
    for (int i = 0; i < NUM_DATA; i++)
    {
        int r = rand() % k;
        group[i] = r;
    }
}

void printData()
{
    int print_array[HEIGHT][WIDTH];

    printf("--------------------\n");

    for (int x = 0; x < HEIGHT; x++)
    {
        for (int y = 0; y < WIDTH; y++)
        {
            for (int i = 0; i < NUM_DATA; i++)
            {
                if (data[i][0] == x && data[i][1] == y)
                {
                    print_array[x][y] = group[i];
                    break;
                }
                else if (i == NUM_DATA - 1)
                {
                    print_array[x][y] = Empty;
                }
            }
            if (print_array[x][y] != Empty)
            {
                printf("%2d", print_array[x][y]);
            }
            else
            {
                printf("  ");
            }
        }
        printf("\n");
    }
}

int main(void)
{
    srand(time(NULL));  // 乱数のシード

    initData();   // データの初期化
    initGroup();  // グループの初期化
    printData();  // データの表示
}
