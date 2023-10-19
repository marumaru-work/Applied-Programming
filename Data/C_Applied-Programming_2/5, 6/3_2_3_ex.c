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

// 単方向リストの中で，引数で与えられた名前と等しいセルの削除する関数
Cell *deleteCellByName(char name[], Cell *head)
{
    int i = 0;
    printf("-------\n");
    printf("%s を調べています。\n", name);
    // ヘッダが NULL ならば，その旨を表示して，NULLを返す
    if (head == NULL)
    {
        printf("list is empty\n");
        return NULL;
    }
    // 最初のセルが探している名前ならば，最初のセルの次のセルのポインタを返す
    if (strcmp(name, head->name) == 0)
    {
        printf("%d: %s = %s, headerが %s に変更されました。\n", i, name, head->name, head->next->name);
        return head->next;
    }
    Cell *h = head;
    // h の次のセルが NULL になるまでループ
    while (h->next != NULL)
    {
        // h の次のセルの名前が探している名前ならば，ポインタをつけ直し，ヘッダを返す
        if (strcmp(name, h->next->name) == 0)
        {
            // h の次のセルを，h の次の次のセルとする
            printf("%d: %s = %s, %s の次のセルを %s に繋ぎ直しました。\n", i, name, h->next->name, h->name, h->next->next->name);
            h->next = h->next->next;
            return head;
        }
        // さもなくば，h を次のセルとする
        else
        {
            printf("%d: ターゲット(h)を %s から %s へ変更します。\n", i, h->name, h->next->name);
            i++;
            h = h->next;
        }
    }
    //単方向リストに探している名前が見つからなかった場合は，その旨を表示して，ヘッダを返す
    printf("%d: not found: %s\n", i, name);
    return head;
}

// セルを表示する関数
void print(Cell *header)
{
    printf("-------\n");
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
    
    // 単方向リストが空の場合の削除
    header = deleteCellByName("tanq", header);
    
    for (int i = 0; i < n; i++)
    {
        header = addCellToTail(names[i], scores[i], header);
    }
    print(header);
    header = deleteCellByName("edgar", header);
    header = deleteCellByName("bob", header);
    header = deleteCellByName("daniel", header);
    header = deleteCellByName("tanq", header); // 単方向リストに含まれない値の削除
    print(header);
}
