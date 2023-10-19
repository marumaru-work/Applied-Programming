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

int countNeighborMines(int yp, int xp)
{
    int sumMine = 0;
    for (int y = -1; y <= 1; y++)
    {
        for (int x = -1; x <= 1; x++)
        {
            int map_y = yp + y;
            int map_x = xp + x;
            if (map[map_y][map_x] == Mine && map_y >= 0 && map_x >= 0 && map_y < HEIGHT && map_x < WIDTH)
            {
                // printf("map[%d][%d] = %d\n", yp + y, xp + x, map[yp + y][xp + x]);
                sumMine++;
            }
        }
    }
    return sumMine;
}

int checkGameEnd(void)
{
    for (int y = 0; y < HEIGHT; y++)
    {
        for (int x = 0; x < WIDTH; x++)
        {
            if (map[y][x] == Empty)
            {
                return 1;
            }
        }
    }
    return 0;
}

int main(int argc, char const *argv[])
{
    int flagDispalyMine = 1;  // 1 ならマップ上に地雷を表示
    // srand(time(NULL)); // 乱数のシード

    initMap();                  // マップの初期化
    initMine();                 // 地雷の設置
    printMap(flagDispalyMine);  // 配列の表示

    int flagContinuationGame = 1;
    while (flagContinuationGame)
    {
        int yp, xp; // プレイヤーが入力したマスの記録

        // プレイヤーにマスを入力させる機能を実装
        do
        {
            printf("input (y, x): ");
            scanf("%d%d", &yp, &xp);
        } while (0 > yp || 0 > xp || yp >= HEIGHT || xp >= WIDTH);

        // もしも，プレイヤーが入力したマスに地雷があればゲーム終了する機能を実装
        if (map[yp][xp] == Mine)
        {
            printf("Bomb!!\n");
            break;
        }

        // プレイヤーが入力したマスの近傍8マスの地雷数をカウント
        int sumMine = countNeighborMines(yp, xp);

        // プレイヤーが入力したマスに近傍8マスの地雷数を代入
        map[yp][xp] = sumMine;

        // 現在のマップの状態を表示
        printMap(flagDispalyMine);

        // ゲームのクリアを確認
        flagContinuationGame = checkGameEnd();
    }
    return 0;
}
    