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

    for (int i = 0; i < N; i++)
    {
        Data infected_person = infected_persons[i];
        printf("%d %d %d: %d\n", infected_person.year, infected_person.month, infected_person.day, infected_person.numPatients);
    }

    return 0;
}
