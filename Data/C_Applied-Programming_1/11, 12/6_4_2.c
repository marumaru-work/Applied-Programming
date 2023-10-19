#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define NUM_DATA 75  // データ数
#define HEIGHT 10  // マップの横幅
#define WIDTH 10   // マップの縦幅
#define Empty -1   // 空マス
#define k 4        // グループの個数

int data[NUM_DATA][2];  // データ
int group[NUM_DATA];  // それぞれのデータが属するグループの値
double centroid[k][2];  // グループの重心

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

    for (int y = 0; y < HEIGHT; y++)
    {
        for (int x = 0; x < WIDTH; x++)
        {
            for (int i = 0; i < NUM_DATA; i++)
            {
                if (data[i][0] == y && data[i][1] == x)
                {
                    print_array[y][x] = group[i];
                    break;
                }
                else if (i == NUM_DATA - 1)
                {
                    print_array[y][x] = Empty;
                }
            }
            if (print_array[y][x] != Empty)
            {
                printf("%2d", print_array[y][x]);
            }
            else
            {
                printf("  ");
            }
        }
        printf("\n");
    }
}

void calculateCentroid()
{
    // printf("--------------------\n");

    for (int i = 0; i < k; i++)
    {
        double y_sum = 0, x_sum = 0, group_count = 0;

        for (int j = 0; j < NUM_DATA; j++)
        {
            if (group[j] == i)
            {
                y_sum += data[j][0];
                x_sum += data[j][1];
                group_count++;
            }
        }
        centroid[i][0] = y_sum / group_count;
        centroid[i][1] = x_sum / group_count;
        
        // printf("%d: %f %f\n", i, centroid[i][0], centroid[i][1]);
    }
}

double euclidean(double y_i, double x_i, double y_j, double x_j)
{
    return sqrt(pow(y_i - y_j, 2) + pow(x_i - x_j, 2));
}

void assignDataToNearestCentroid()
{
    for (int i = 0; i < NUM_DATA; i++)
    {
        double min_distance;
        int nearest;
        for (int j = 0; j < k; j++)
        {
            double distance = euclidean(data[i][0], data[i][1], centroid[j][0], centroid[j][1]);
            if (min_distance > distance || j == 0)
            {
                min_distance = distance;
                nearest = j;
            }
        }
        group[i] = nearest;
    }
}

int main(void)
{
    srand(time(NULL));  // 乱数のシード

    initData();   // データの初期化
    initGroup();  // グループの初期化
    printData();  // データの表示

    int loop_threshold = 10;  // ループ数の閾値
    int loop_count = 0;       // ループ数のカウンタ

    while (loop_count < loop_threshold)
    {
        calculateCentroid();  // グループの重心の計算
        assignDataToNearestCentroid();  // それぞれのデータを最近傍の重心に割り当てる
        loop_count += 1;
    }
    printData();  //グルーピングの結果の表示
}
