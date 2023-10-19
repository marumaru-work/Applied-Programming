#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct cell
{
    char name[64];
    int score;
    struct cell *next;  // 次のセルへのポインタ
} Cell;

Cell *newCell(char name[], int score) 
{
    Cell *cell = malloc(sizeof(Cell));
    cell->score = score;
    strcpy(cell->name, name);
    return cell;
}

void printTest(char line[])
{
    printf("--------------------------------\n");
    printf("test: %s\n", line);
}

void printCell(Cell *cell)
{
    printf("(%s, %d)\n", cell->name, cell->score);
}

void printAddCell(Cell *cell, char line[])
{
    printf("add new cell to %s: ", line);
    printCell(cell);
}

void printAddCellToHead(Cell *cell)
{
    printAddCell(cell, "head");
}

void printAddCellToTail(Cell *cell)
{
    printAddCell(cell, "tail");
}

void printAllCells(Cell *head)
{
    if (head == NULL || head->next == head)
    {
        printf("list is empty\n");
    }
    else
    {
        int lc = 0;  // 無限ループの回避用のループのカウンタ
        int thLc = 10;  // 無限ループと判定する閾値
        for (Cell *h = head->next; h != head; h = h->next)
        {
            printCell(h);
            lc += 1;
            if (lc >= thLc)
            {
                // 10回ループしたら無限ループと判断してプログラムを落とす
                printf("infinite loop\n");
                exit(EXIT_FAILURE);  // 異常終了
            }
        }
    }
}

// 循環リストの末尾にセルを追加する関数
void addCellToTail(char name[], int score, Cell *head)
{
    Cell *h = head;
    Cell *cell = newCell(name, score);
    while (h->next != head)
    {
        h = h->next;
    }
    h->next = cell;
    cell->next = head;
    printAddCellToTail(cell);
}

// 循環リストを初期化する関数
Cell *initList() 
{
    printf("initialize circularly-linked list\n");
    Cell *head = newCell("head", -1);
    head->next = head;
    return head;
}

int main(void)
{
    Cell *head = initList();  // 循環リストの初期化
    int scores[] = {0, 1, 2, 3, 4};
    char names[][10] = {"daniel", "edgar", "adam", "chris", "bob"};
    size_t n = sizeof(scores) / sizeof(scores[0]);

    printTest("print empty list");
    printAllCells(head);

    printTest("add cell to tail");
    for (int i = 0; i < n; i++)
    {
        addCellToTail(names[i], scores[i], head);
        printAllCells(head);
    }
}
