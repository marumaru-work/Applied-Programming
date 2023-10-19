#include <stdio.h>
#include <stdlib.h> // malloc 用
#include <string.h>

// 単方向リスト (構造体)
typedef struct cell
{
    char name[64];      // 名前
    int score;          // 点数
    struct cell *next;  // 次のセルを表すポインタ
} Cell;

// 新しいセルをポインタで作成するための関数
Cell *newCell(char name[], int score)
{
    Cell *cell = malloc(sizeof(Cell)); // メモリの確保 (動的にヒープ領域に)
    cell->score = score;
    strcpy(cell->name, name);
    return cell;
}

// 単方向リストの先頭にセルを追加する関数 
Cell *addCellToHead(char name[], int score, Cell *head)
{
    Cell *c = newCell(name, score); // 新しいセルを作成
    c->next = head; // 最後に指しているポインタはNULL (... → アドレス → アドレス → NULL)
    return c;
}

// 単方向リストにおいてある名前の点数を得るための関数
int getScore(char name[], Cell *head)
{
    // strcmp 関数とは？ → 第 1 引数と第 2 引数 が完全一致していたら 0 を返す関数、それ以外なら ASCII の並び順による比較演算子処理が行われる。
    // 【第1引数 < 第2引数】の場合はマイナスの値,【第1引数 > 第2引数】の場合はプラスの値,【第1引数 = 第2引数】の場合は 0.
    // 再帰関数を使って処理する
    if (strcmp(name, head->name) == 0) // 完全一致
    {
        return head->score;
    }
    else if (head->next == NULL) // 該当するものが見つからなかったときの処理
    {
        return -1;
    }
    else
    {
        return getScore(name, head->next);
    }
}

// main 関数
int main(void)
{
    Cell *head = NULL;
    int scores[] = {5, 4, 3, 1, 2};
    char names[][10] = {"daniel", "edgar", "adam", "chris ", "bob"};
    size_t n = sizeof(scores) / sizeof(scores[0]);
    // 単方向リストの先頭にセルを追加 (構造体によって、 scores と names の組み合わせセルができる)
    for (int i = 0; i < n; i++)
    {
        head = addCellToHead(names[i], scores[i], head);
        // i = 0 : head -> next = (NULL)
        // i = 1 : head -> next = (i = 0 の head を指している)
        // i = 2 : head -> next = (i = 1 の head を指している) .....
    }
    // ここまでの処理で head は現在、 n - 2 番目 の組み合わせセルのアドレスを指している
    printf("adam's score: %d\n", getScore("adam", head)); // 3
    printf("daniel's score: %d\n", getScore("daniel", head)); // 5
    printf("bob's score: %d\n", getScore("bob", head)); // 2
    printf("john's score: %d\n", getScore("john", head)); // -1
    return 0;
}
