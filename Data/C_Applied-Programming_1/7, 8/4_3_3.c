#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// getDisk 関数 , コマの種類を条件分岐 (if文) で選択
char* getDisk(int t)
{
    if (t == 1)
    {
        return "●";
    }
    else if (t == -1)
    {
        return "○";
    }
    else if (t == 0)
    {
        return "―";
    }
    else
    {
        return "error";
    }
}

// printBlackDisk 関数 , 黒コマを表示 (コマ → "●")
void printBlackDisk()
{
    printf("%4s", getDisk(1));
}

// printWhiteDisk 関数 , 白コマを表示 (コマ → "○")
void printWhiteDisk()
{
    printf("%4s", getDisk(-1));
}

// printEmptyDisk 関数 , 空白コマを表示 (コマ → "-")
void printEmptyDisk()
{
    printf("%4s", getDisk(0));
}

// printDisk 関数 , パラメーターによる条件分岐 (if文) 
void printDisk(int t)
{
    if (t == 1)
    {
        printBlackDisk();
    }
    else if (t == -1)
    {
        printWhiteDisk();
    }
    else if (t == 0)
    {
        printEmptyDisk();
    }
    else
    {
        printf("error");
    }
}

// printDisks 関数 , マスの状態を表示する
void printDisks(int disks[], int n)
{
    // 「 0 1 2 3 4 5 6 7 8 910111213141516171819」を表示
    for (int i = 0; i < n; i++)
    {
        printf("%2d", i);
    }
    printf("\n");

    // コマ (例 : 「 ● ● ― ― ● ― ○ ○ ― ● ● ● ― ○ ― ● ― ● ○ ○」) を表示する printDisk 関数を実行
    for (int i = 0; i < n; i++)
    {
        printDisk(disks[i]);  // diskus[i] には、-1, 0, 1 のどれかが格納されている
    }
    printf("\n");
}

// main 関数
int main(int argc, char const *argv[])
{
    // 1) プログラムの初期化
    int disks[20];     // マス
    int nDisk = sizeof(disks) / sizeof(disks[0]); // マス数
    int turn = 1;      // 手番
    int numDisks = 0;  // 石の置いてある場所の数
    // srand(time(NULL)); // 乱数のシード

    int black = 0, white = 0;  // 各コマの数

    // 2) マスの初期化
    for (int i = 0; i < nDisk; i++)
    {
        disks[i] = rand() % 3 - 1;  // -1, 0, 1 を生成
        if (disks[i] != 0)  // disks 配列の石が置いてある場所の数 (空白を除く)
        {
            numDisks++;
        }
    }

    // 3) 現在の状態の表示
    printf("初期状態\n");
    printDisks(disks, nDisk);

    // 4) ゲームの処理 (全てのマスに石が置かれるまで繰り返し)
    while (numDisks != nDisk)
    {
        int position; // コマを置く位置の値
        int num_piece;   // コマの種類 (黒石 or 白石)

        // 手番による条件分岐
        if (turn % 2) // 変数 turn が奇数なら
        {
            num_piece = 1;
        }
        else // 変数 turn が偶数なら
        {
            num_piece = -1;
        }

        // 5) ユーザによる石を配置したい場所の入力 (条件を満たさないとdo-while文を抜けれない)
        do
        {
            printf("%s の手番です．石を置く位置を入力してください: ", getDisk(num_piece));
            scanf("%d", &position);
            if (position < 0)
            {
                printf("0 以上を入力してください．\n");
            }
            else if (position >= 20)
            {
                printf("20 未満を入力して下さい．\n");
            }
            else if (disks[position] != 0)
            {
                printf("その位置には既に石があります．\n");
            }
        } while (position < 0 || position >= 20 || disks[position] != 0);

        // 6) 石を配置する処理
        printf("%sを%dに置きます．\n", getDisk(num_piece), position);
        disks[position] = num_piece;  // 石を配列に格納

        // 7) 石をひっくり返す処理
        // 負の方向ベクトル
        // コマを置いたマスの1つ左のマスに自分のコマ、または空白ではないとき、(相手のコマのとき)
        if (disks[position - 1] != num_piece && disks[position - 1] != 0)
        {
            // position - 1 : 自分が置いたコマを除く、インデックス(位置) → 負の方向へ調べていく  (左へ)
            for (int i = position - 1, count = 1; i >= 0; i--, count++)
            {
                // 自分のコマに到達する前に一度でも空白があるなら、breakする
                if (disks[i] == 0)
                {
                    break;
                }
                // i番目に自分のコマがあるのなら、↓
                else if (disks[i] == num_piece)
                {
                    // i + 1番目(count - 1)からposition - 1番目(count = 1)が連続する相手のコマなので、↓ (右へ戻る)
                    for (int j = 1; j <= count - 1; j++)
                    {
                        // それらをひっくり返す
                        disks[i + j] = num_piece;
                        printf("%2d を %s にする\n", i + j, getDisk(num_piece));
                    }
                    break;
                }
            }
        }
        // 正の方向ベクトル
        // コマを置いたマスの1つ右のマスに自分のコマ、または空白ではないとき、(相手のコマのとき)
        if (disks[position + 1] != num_piece && disks[position + 1] != 0)
        {
            // position + 1 : 自分が置いたコマを除く、インデックス(位置) → 正の方向へ調べていく (右へ)
            for (int i = position + 1, count = 1; i < nDisk; i++, count++) // nDisk = 配列のサイズ
            {
                // 自分のコマに到達する前に一度でも空白があるなら、breakする
                if (disks[i] == 0)
                {
                    break;
                }
                // i番目に自分のコマがあるのなら、↓
                else if (disks[i] == num_piece)
                {
                    // i - 1番目(count - 1)からposition + 1番目(count = 1)が連続する相手のコマなので、↓ (左へ戻る)
                    for (int j = 1; j <= count - 1; j++)
                    {
                        // それらをひっくり返す
                        disks[i - j] = num_piece;
                        printf("%2d を %s にする\n", i - j, getDisk(num_piece));
                    }
                    break;
                }
            }
        }

        // 8) ターン終了処理
        // コマの総数を更新するため、ターン終了時に0にする
        black = 0;
        white = 0;
        numDisks = 0;

        // コマの総数を更新
        for (int i = 0; i < nDisk; i++)
        {
            if (disks[i] == 1)
            {
                black++;
                numDisks++;
            }
            else if (disks[i] == -1)
            {
                white++;
                numDisks++;
            }
        }

        // ターンを変更
        turn++;

        printDisks(disks, nDisk); // マスを表示
        printf("num disk: %d\n", numDisks);
        printf("=====================================================\n");
    }

    // 9) ゲーム終了処理
    printf("ゲーム終了\n");
    printf("先行:%3d, 後攻:%3d\n", black, white);

    return 0;
}
