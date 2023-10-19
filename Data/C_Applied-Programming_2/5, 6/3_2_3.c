#include <stdio.h>
#include <stdlib.h> // malloc 用
#include <string.h>

typedef struct cell
{
    char name[64];      // 名前
    int score;          // 点数
    struct cell *next;  // 次のセルを表すポインタ
} Cell;

Cell *newCell(char name[], int score)
{
    Cell *cell = malloc(sizeof(Cell)); // メモリの確保
    cell->score = score;
    strcpy(cell->name, name);
    return cell;
}

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

Cell *deleteCellByName(char name[], Cell *head)
{
    if (head == NULL)
    {
        printf("list is empty\n");
        return NULL;
    }
    if (strcmp(name, head->name) == 0)
    {
        return head->next;
    }
    Cell *h = head;
    while (h->next != NULL)
    {
        if (strcmp(name, h->next->name) == 0)
        {
            h->next = h->next->next;
            return head;
        }
        else
        {
            h = h->next;
        }
    }
    printf("not found: %s\n", name);
    return head;
}

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
