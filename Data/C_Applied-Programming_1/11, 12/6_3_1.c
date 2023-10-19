#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define HEIGHT 10      // マップの横幅
#define WIDTH 10       // マップの縦幅
#define NUM_CAT 40     // 猫の数
#define NUM_RABBIT 40  // ウサギの数

int map[HEIGHT][WIDTH];  // マップ
enum Object{Empty, Cat, Rabbit};  // オブジェクト {空，猫，ウサギ}

void printObject(int o)
{
    char s;
    if (o == Cat)
    {
        s = 'C';
    }
    else if (o == Rabbit)
    {
        s = 'R';
    }
    else
    {
        s = ' ';
    }
    printf("%2c", s);
}

void printMap()
{
    for (int y = 0; y < HEIGHT; y++)
    {
        for (int x = 0; x < WIDTH; x++)
        {
            int o = map[y][x];
            printObject(o);
        }
        printf("\n");
    }
    for (int i = 0; i < WIDTH; i++)
    {
        printf("--");
    }
    printf("\n");
}

void initMap()
{
    for (int i = 0; i < HEIGHT; i++)
    {
        for (int j = 0; j < WIDTH; j++)
        {
            map[i][j] = Empty;
        }
    }
}

void placeObjectRandomly(int o)
{
    while (1)
    {
        int i = rand() % HEIGHT;
        int j = rand() % WIDTH;
        if (map[i][j] == Empty)
        {
            map[i][j] = o;
            break;
        }
    }
}

void placeObjects(int o, int num)
{
    for (int i = 0; i < num; i++)
    {
        placeObjectRandomly(o);
    }
}

int main(void)
{
    srand(time(NULL));  // 乱数のシード

    initMap();                   // マップの初期化
    placeObjects(Cat, NUM_CAT);  // マップにネコをランダムに配置
    placeObjects(Rabbit, NUM_RABBIT);  // マップにウサギをランダムに配置
    printMap();                        // 初期状態の描画
}
