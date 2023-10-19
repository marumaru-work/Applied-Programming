#include <stdio.h>
#include <math.h>

#define N 632

typedef struct
{
    int year;
    int month;
    int day;
    int numPatients;
} Data;

void autocorrelation(Data data[], double result[], int h)
{
    // 1. すべての日付の罹患者数から罹患者数の平均値を求める
    double sum = 0, ave = 0;
    for (int i = 0; i < N; i++)
    {
        sum += data[i].numPatients;
    }
    ave = sum / (double) N;

    // 2. すべての日付の罹患者数に対して平均値の値を引いた値を作り，別の配列 temp に保存する
    double temp[N], p = 0;
    for (int i = 0; i < N; i++)
    {
        temp[i] = data[i].numPatients - ave;
        // 3. temp の2乗の総和を求め，p とする
        p += pow(temp[i], 2);
    }
    printf("sum: %f, ave: %f, p: %f\n", sum, ave, p);

    // 4. 日付 d について，日付 d の罹患者数と日付 d + j の罹患者数の積の総和を求め，その総和を p で割る (ただし，j = {0, 1, ..., h - 1} とする)．その結果を result の i 番目の要素とする
    for (int i = 0; i < N; i++)
    {
        double d_sum = 0;
        for (int j = 0; j < h; j++)
        {
            if (i < N - h)
            {
                // printf("%3d: (%d * %d) - %f + %f = ", i, data[i].numPatients, data[i + j].numPatients, ave, d_sum);
                d_sum += temp[i] * temp[i + j];
                // printf("%f\n", d_sum);
            }
        }
        result[i] = d_sum / p;
        printf("%3d: %f / %f = %f\n", i, d_sum, p, result[i]);
    }
}

void plotAutoCorrelation(double data[])
{
    FILE *gp;
    gp = popen("gnuplot -persist", "w");  // gnuplot を起動
    fprintf(gp, "plot '-' u 1:2 t 'The number of patients' w lp\n");
    for (int i = 0; i < N; ++i)
    {
        fprintf(gp, "%d %f\n", i, data[i]);
    }
    fflush(gp);             // バッファのフラッシュ
    fprintf(gp, "exit\n");  // gnuplot を終了
    pclose(gp);
}

int main(void)
{
    FILE *fp;
    char *path_src = "./data/covid19_in_okayama_202108_3.ssv";  // ファイルのパス
    Data data[N]; // 感染者の情報の構造体の配列

    fp = fopen(path_src, "r"); // ファイルを読み込みモードでオープン (失敗するとNULLポインタとして返される.)

    int tempyear, tempmonth, tempday, tempnumPatients;

    int i = 0; // 配列の添字
    // 読み込むファイルがEOFになるまでループ
    while (fscanf(fp, "%d%d%d%d\n", &tempyear, &tempmonth, &tempday, &tempnumPatients) != EOF)
    {
        Data infected_person;
        infected_person.year = tempyear;
        infected_person.month = tempmonth;
        infected_person.day = tempday;
        infected_person.numPatients = tempnumPatients;

        data[i] = infected_person;
        i++;
    }

    fclose(fp); // ファイルのクローズ

    int h = 21;
    double result[N]; // 結果を代入する配列
    autocorrelation(data, result, h);
    plotAutoCorrelation(result);

    return 0;
}
