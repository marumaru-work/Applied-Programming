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
    Cell *cell = malloc(sizeof(Cell)); // メモリの確保
    cell->score = score;
    strcpy(cell->name, name);
    return cell;
}

// 単方向リストの最後尾に新しいセルを追加する関数
Cell *addCellToTail(char name[], int score, Cell *head)
{
    Cell *c = newCell(name, score); // 新しいセルを作成
    c->next = NULL;
    if (head == NULL)
    {
        return c;
    }
    else
    {
        Cell *h = head;
        while (h->next != NULL)
        {
            h = h->next;
        }
        h->next = c;
        return head;
    }
}

// セルを表示する関数
void print(Cell *header)
{
    Cell *h = header;
    while (h != NULL) // h が NULL でないなら ループ
    {
        printf("%s: %d\n", h->name, h->score);
        h = h->next; // h が h の次を指すようにする
    }
    printf("-------\n");
}

// main 関数
int main(void)
{
    Cell *header = NULL;
    int scores[] = {5, 4, 3, 1, 2};
    char names[][10] = {"daniel", "edgar", "adam", "chris", "bob"};
    size_t n = sizeof(scores) / sizeof(scores[0]);
    for (int i = 0; i < n; i++)
    {
        header = addCellToTail(names[i], scores[i], header);
        print(header);
    }
    return 0;
}
