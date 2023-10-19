#include <stdio.h>

enum SignalColor {red, yellow, blue};  // 信号色の列挙体

enum SignalColor inputSignalColor(void)
{
    int tmp;
    do
    {
        printf("0: red, 1: yellow, 2: blue\n");
        scanf("%d", &tmp);
    } while (tmp < red || tmp > blue);
    return tmp;
}

void printSignalType(enum SignalColor sc)
{
    switch (sc)
    {
        case red:
            printf("止まれ\n");
            break;
        case yellow:
            printf("止まれ\n");
            break;
        case blue:
            printf("進め\n");
            break;
    }
}

int main(int argc, char const *argv[])
{
    enum SignalColor sc = inputSignalColor();
    printSignalType(sc);
    return 0;
}
