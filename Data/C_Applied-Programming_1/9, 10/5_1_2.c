#include <stdio.h>

enum week {日曜日, 月曜日, 火曜日, 水曜日, 木曜日, 金曜日, 土曜日};

int convertDateToDay(int date)
{
        int day = (date % 7 + 4) % 7;
        return day;
}

void printDay(enum week day)
{
    switch (day)
    {
        printf("%d\n", day);
        case 日曜日:
            printf("sunday\n");
            break;
        case 月曜日:
            printf("monday\n");
            break;
        case 火曜日:
            printf("tuesday\n");
            break;
        case 水曜日:
            printf("wednesday\n");
            break;
        case 木曜日:
            printf("thursday\n");
            break;
        case 金曜日:
            printf("friday\n");
            break;
        case 土曜日:
            printf("saturday\n");
            break;
    }
}

int main(int argc, char const *argv[])
{
    for (int date = 1; date < 32; date++)    // 1日から31日までをループ
    {
        int day = convertDateToDay(date);    // 日を曜日に変換
        printf("%d ", date);                 // 日付を改行せずに表示
        printDay(day);                       // 曜日の英語を表示
    }
    return 0;
}
