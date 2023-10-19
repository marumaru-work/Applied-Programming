#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUCKET_SIZE 10  // ハッシュテーブルのバケットのサイズ
#define N 20            // テストデータの数

// セルの構造体
typedef struct cell
{
    char data[64];
    int score;
    struct cell *next;  // 次のセルへのポインタ
} Cell;

Cell *table[BUCKET_SIZE];  // ハッシュテーブル

char data[N][10] = {"one",       "two",      "three",    "four",
                    "five",      "six",      "seven",    "eight",
                    "nine",      "ten",      "eleven",   "twelve",
                    "thirteen",  "fourteen", "fifteen",  "sixteen",
                    "seventeen", "eighteen", "nineteen", "twenty"};  // データ

// 新しいセルを作成するための関数
Cell *newCell(char data[], int score)
{
    Cell *cell = malloc(sizeof(Cell));
    cell->score = score;
    strcpy(cell->data, data);
    return cell;
}

void printTest(char *line)
{
    printf("-------------\n");
    printf("test: %s\n", line);
}

// セルを表示するための関数
void printCell(Cell *cell)
{
    if (cell == NULL)
    {
        printf("cell is NULL");
    }
    else
    {
        printf("(%s, %d)", cell->data, cell->score);
    }
}

// ハッシュ値を求める関数
int toHash(char *word)
{
    int sum = 0;
    while (*word)
    {
        sum += *word++;
    }
    return sum % BUCKET_SIZE;
}

// ハッシュテーブルを初期化する関数
void initHashTable()
{
    printf("initialize hash table\n");
    for (int i = 0; i < BUCKET_SIZE; i++)
    {
        table[i] = NULL;
    }
}

// ハッシュテーブルに含まれるすべての値を整形して表示する関数
void printHashTable()
{
    printf("print hash table\n");
    for (int i = 0; i < BUCKET_SIZE; i++)
    {
        printf("%d: ", i);
        for (Cell *h = table[i]; h != NULL; h = h->next)
        {
            printf("(%s, %d)", h->data, h->score);
            if (h->next != NULL)
            {
                printf(" → ");
            }
        }
        printf("\n");
    }
}

// ハッシュテーブルに値を挿入する関数
void insert(char *word, int score)
{
    // printf("insert: %s\n", word);
    int hash_value = toHash(word);
    // printf("hash: %d\n", hash_value);
    Cell *cell = newCell(word, score);
    cell->next = table[hash_value];
    table[hash_value] = cell;
}

void insertItems(int n)
{
    // 引数個のデータをハッシュテーブルに挿入
    for (int i = 0; i < n; i++)
    {
        insert(data[i], i + 1);
    }
}

void insertAllItems()
{
    // N 個の全てのデータをハッシュテーブルに挿入
    insertItems(N);
}

// 名前でセルを削除する関数
int deleteItem(char *word)
{
    int hash_value = toHash(word);
    if (table[hash_value] == NULL)
    {
        printf("bucket is empty\n");
        return -1;
    }
    if (strcmp(word, table[hash_value]->data) == 0)
    {
        table[hash_value] = table[hash_value]->next;
        return 1;
    }
    else
    {
        for (Cell *p = table[hash_value]->next, *q = table[hash_value]; p != NULL; p = p->next, q = q->next)
        {
            if (strcmp(word, p->data) == 0)
            {
                q->next = p->next;
                return 1;
            }
        }
    }
    printf("not found: %s\n", word);
    return -1;
}

// 名前でセルを得る関数
Cell *getItemByName(char *word)
{
    int hash_value = toHash(word);
    for (Cell *h = table[hash_value]; h != NULL; h = h->next)
    {
        if (strcmp(word, h->data) == 0)
        {
            return h;
        }
    }
    return NULL;
}

void testDelete()
{
    printTest("insert items");
    insertAllItems();
    printHashTable();
    char testdata[6][10] = {"six",    "one",   "fourteen",
                            "eleven", "eight", "five"};
    printTest("get stored item by name");
    for (int i = 0; i < 5; i++)
    {
        char *d = testdata[i];
        Cell *cell = getItemByName(d);
        printf("find %s: ", d);
        printCell(cell);
        printf("\n");
    }

    printTest("get unstored item");
    Cell *cell = getItemByName("tanq");
    printf("find tanq: ");
    printCell(cell);
    printf("\n");

    printTest("delete all items");
    for (int i = 0; i < N; i++)
    {
        char *word = data[i];
        printf("delete %s: %d\n", word, deleteItem(word));
    }

    printTest("print empty hash table");
    printHashTable();

    printTest("insert five items");
    insertItems(5);
    printHashTable();

    printTest("delete unstored item");
    deleteItem("nine");
}

int main(void)
{
    initHashTable();  // チェイン法のハッシュテーブルの初期化
    testDelete();     // ハッシュテーブルの値を削除するテスト
}
