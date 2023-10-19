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
    printf("insert: %s\n", word);
    int hash_value = toHash(word);
    printf("hash: %d\n", hash_value);
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

void testInsert()
{
    printTest("print empty hash table");
    printHashTable();
    printTest("insert items");
    insertAllItems();
    printTest("print hash table");
    printHashTable();
}

int main(void)
{
    initHashTable();  // チェイン法のハッシュテーブルの初期化
    testInsert();  // ハッシュテーブルへのデータの挿入のテスト
}
