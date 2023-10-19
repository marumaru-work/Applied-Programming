#include <stdio.h>

#define N 31

typedef struct
{
    int year;
    int month;
    int day;
    int numPatients;
} Data;

int main(void)
{
    FILE *fp;
    char *path_src = "./data/covid19_in_okayama_202108_1.ssv";  // ファイルのパス
    Data infected_persons[N]; // 感染者の情報の構造体の配列

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

        infected_persons[i] = infected_person;
        i++;
    }	

    fclose(fp); // ファイルのクローズ

    FILE *fp_dst;
    char *path_dst = "./data/covid19_in_okayama_202108_2.ssv";

    fp_dst = fopen(path_dst, "w"); // ファイルを書き込みモードでオープン

    for (int i = 0; i < N; i++)
    {
        fprintf(fp_dst, "%d/%d/%d	%d\n", infected_persons[i].year, infected_persons[i].month, infected_persons[i].day, infected_persons[i].numPatients);
    }

    fclose(fp_dst); // ファイルのクローズ

    return 0;
}
