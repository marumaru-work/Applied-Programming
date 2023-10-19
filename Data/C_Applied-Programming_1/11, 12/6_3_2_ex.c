#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define HEIGHT 20      // マップの横幅
#define WIDTH 20       // マップの縦幅
#define NUM_CAT 80     // 猫の数
#define NUM_RABBIT 80  // ウサギの数
#define NUM_MOUSE 80   // マウスの数
#define NUM_DOG 80     // 犬の数

int map[HEIGHT][WIDTH];  // マップ
enum Object{Empty, Cat, Rabbit, Mouse, Dog};  // オブジェクト {空，猫，ウサギ，ネズミ，犬}

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
    else if (o == Mouse)
    {
        s = 'M';
    }
    else if (o == Dog)
    {
        s = 'D';
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

int countOtherObjectInNeighborhood(int y, int x, int o)
{
    int count = 0;
    for (int i = -1; i <= 1; i++)
    {
        for (int j = -1; j <= 1; j++)
        {
            if (map[y + i][x + j] != o && map[y + i][x + j] != Empty && y + i >= 0 && x + j >= 0 && y + i < HEIGHT && x + j < WIDTH)
            {
                count++;
            }
        }
    }
    return count;
}

void moveToAnotherPlace(int y, int x)
{
    placeObjectRandomly(map[y][x]);
    map[y][x] = Empty;
}

// 自作関数 ( 何匹配置されてるかを再度確認するための関数 )
/*
void countobject(int o)
{
    int count = 0;
    for (int i = 0; i < HEIGHT; i++)
    {
        for (int j = 0; j < WIDTH; j++)
        {
            if (map[i][j] == o)
            {
                count++;
            }
        }
    }
    printObject(o);
    printf(" は%d匹います\n", count);
}
*/

int main(void)
{
    srand(time(NULL));  // 乱数のシード

    initMap();                         // マップの初期化
    placeObjects(Cat, NUM_CAT);        // マップにネコをランダムに配置
    placeObjects(Rabbit, NUM_RABBIT);  // マップにウサギをランダムに配置
    placeObjects(Mouse, NUM_MOUSE);    // マップにマウスをランダムに配置
    placeObjects(Dog, NUM_DOG);        // マップに犬をランダムに配置
    printMap();                        // 初期状態の描画

    // 自作関数 ( 何匹配置されてるかを再度確認するための関数 ) -----
    /*
    countobject(Cat);
    countobject(Rabbit);
    countobject(Mouse);
    countobject(Dog);
    printf("\n");
    */
    // ----------------------------------------------------------

    int MovementCountInLoop = 0;  // 1回のループの中での引っ越し数のカウンタ
    int loopThreshold = 1000;     // ループ数の上限 (無限ループ対策)
    int LoopCount = 0;            // ループ数のカウンタ
    int neighborThreshold = 3;    // 隣接する8マスにおける他の動物の数に対する許容数の閾値

    do
    {
        MovementCountInLoop = 0;  // ループ内の引っ越し数のリセット
        for (int y = 0; y < HEIGHT; y++)
        {
            for (int x = 0; x < WIDTH; x++)
            {
                // もしも，座標 (y, x) が空白でなければ
                if (map[y][x] != Empty)
                {
                    // 隣接する8マスに存在する他の動物を数える
                    int count = countOtherObjectInNeighborhood(y, x, map[y][x]);
                    // もしも，隣接する8マスに存在する他の動物の数が閾値以上なら，引っ越す
                    if (neighborThreshold <= count)
                    {
                        // 動物の引っ越し
                        moveToAnotherPlace(y, x);
                        // 引っ越し数のインクリメント
                        MovementCountInLoop++;
                    }
                }
            }
        }
        LoopCount += 1;  // ループ数のインクリメント
    } while (MovementCountInLoop != 0 && LoopCount <= loopThreshold);  // このループで引っ越しがある，かつ，ループ数が閾値以下ならループ続行

    printMap();  // 最終的な結果の描画
    printf("loop: %d", LoopCount);
}
