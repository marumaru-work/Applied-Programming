#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define HEIGHT 5                            // マップの縦マス数
#define WIDTH 5                             // マップの横マス数
#define NUM_MINE 5                          // 地雷数
enum squareType { Mine = -2, Empty = -1 };  // マスの状態

int map[HEIGHT][WIDTH];  // マップ

void initMap()
{
    for (int y = 0; y < HEIGHT; y++)
    {
        for (int x = 0; x < WIDTH; x++)
        {
            map[y][x] = Empty;
        }
    }
}

void initMine()
{
    for (int i = 0; i < NUM_MINE; i++)
    {
        int flag = 1;
        while (flag)
        {
            int x = rand() % WIDTH;
            int y = rand() % HEIGHT;
            if (map[y][x] == Empty)
            {
                map[y][x] = Mine;
                flag = 0;                
            }
        }
    }
}

void printLine()
{
    printf("  ");
    for (int i = 0; i < WIDTH; i++)
    {
        printf("-");
    }
    printf("\n");
}

void printMap(int flagDisplayMine)
{
    printf("  ");
    for (int i = 0; i < WIDTH; i++)
    {
        printf("%d", i);
    }
    printf("\n");
    printLine();

    for (int y = 0; y < HEIGHT; y++)
    {
        printf("%d|", y);
        for (int x = 0; x < WIDTH; x++)
        {
            int v = map[y][x];
            if (v == Mine)
            {
                if (flagDisplayMine == 1)
                {
                    printf("b");
                }
                else
                {
                    printf(" ");
                }
            }
            else if (v == Empty)
            {
                printf(" ");
            }
            else
            {
                printf("%d", v);
            }
        }
        printf("\n");
    }
    printLine();
}

int main(int argc, char const *argv[])
{
    int flagDispalyMine = 1;  // 1 ならマップ上に地雷を表示
    // srand(time(NULL)); // 乱数のシード

    initMap();                  // マップの初期化
    initMine();                 // 地雷の設置
    printMap(flagDispalyMine);  // 配列の表示
}
