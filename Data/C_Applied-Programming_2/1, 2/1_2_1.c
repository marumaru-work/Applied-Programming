#include <stdio.h>

#define NUM_CELL 31 // 横幅 (文字数)
#define NUM_LOOP 10 // 縦幅 (ループ回数)

void show(char *p)
{
    for (int i = 0; i < NUM_CELL; i++)
    {
        printf("%c", p[i] ? '@' : '-');
    }
    printf("\n");
}

int main(void)
{
    char cell[2][NUM_CELL] = {{0}};  // 2次元配列
    char *curp = cell[0];            // 現在の状態
    char *nextp = cell[1];           // 次の状態

    curp[NUM_CELL / 2] = 1;  // 初期状態の設定
    show(curp);              // 現在の状態の表示

    for (int i = 0; i < NUM_LOOP; i++)
    {
        // 現在の状態の両端を0にする
        *curp = 0;
        *(curp + (NUM_CELL - 1)) = 0;
        // 両端の要素以外についてそれぞれの要素についてループ
        for (int j = 1; j < NUM_CELL - 1; j++)
        {
            // 現在の状態の j 番目から，次の状態の j 番目の要素を決定する
            if (*(curp + j - 1) && *(curp + j) && !*(curp + j + 1) || *(curp + j - 1) && !*(curp + j) && !*(curp + j + 1)
             || !*(curp + j - 1) && *(curp + j) && *(curp + j + 1) || !*(curp + j - 1) && !*(curp + j) && *(curp + j + 1))
            {
                *(nextp + j) = 1;
            }
            else
            {
                *(nextp + j) = 0;
            }
        }
        // 現在の状態と次の状態を入れ替え
        for (int j = 0; j < NUM_CELL; j++)
        {
            char num = *(curp + j);
            *(curp + j) = *(nextp + j);
            *(nextp + j) = num;
        }
        show(curp);
    }
}
