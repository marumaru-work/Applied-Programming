#include <stdio.h>

#define N 632

typedef struct
{
    int year;
    int month;
    int day;
    int numPatients;
} Data;

void plotMovingAverage(Data data[], int w)
{
    Data SMA[N]; // numPatients を SMA の値にする配列
    
    for (int i = 0; i < N; i++)
    {
        SMA[i] = data[i]; // 配列をコピー
        if (i < w)
        {
            // 「0日目から6日目は，移動平均値を計算することはできないので，計算しなくて良いとする．」の部分
            // ↓ おそらく、この処理は要らないと思うけど、何か気持ち悪いから 0 でも代入しておきたいですよね？
            SMA[i].numPatients = 0;
        }
        else
        {
            int sum = 0; // 合計値: P(d) + P(d-1) + P(d-2) + P(d-3) + ... + P(d-(w-1))
            for (int j = 0; j < w; j++)
            {
                sum += data[i - j].numPatients;
            }
            SMA[i].numPatients = sum / w; // 平均値: 合計値 / w
        }
        // printf("%d %d %d: %d\n", SMA[i].year, SMA[i].month, SMA[i].day, SMA[i].numPatients);
    }

    FILE *gp;
    gp = popen("gnuplot -persist", "w");  // gnuplot を起動
    fprintf(gp, "plot '-' u 1:2 t 'The number of patients' w lp\n");
    for (int i = w; i < N; ++i) // 「i = 0」→「i = w」にすることで、計算していない値を非表示にする．
    {
        Data d = SMA[i];
        fprintf(gp, "%d %d\n", i, d.numPatients);
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

    int w = 7;
    plotMovingAverage(data, w);

    return 0;
}
