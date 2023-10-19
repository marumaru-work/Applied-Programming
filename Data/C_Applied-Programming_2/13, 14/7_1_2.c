#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// ノードの構造体
typedef struct node
{
    char name[64];
    int score;
    struct node *left;   // 左の子ノード
    struct node *right;  // 右の子ノード
} Node;

// ノードを生成する関数
Node *makeNode(char name[], int score)
{
    Node *node = malloc(sizeof(Node));
    node->score = score;
    strcpy(node->name, name);
    node->left = NULL;   // 左の子ノードを NULL にする
    node->right = NULL;  // 右の子ノードを NULL にする
    return node;
}

// テスト名を表示する関数
void printTest(char *line)
{
    printf("-------------\n");
    printf("test: %s\n", line);
}

// 二分探索木のノードの高さをカウントする関数 (再帰関数) (課題7_1_2)
int getNodeHeight(Node *node)
{
    if (node == NULL) // もしも，ノードが NULL ならば，
    {
        return 0; // 0 を返す．
    }
    else // さもなくば，
    {
        int left_c = getNodeHeight(node->left); // 左の子ノードに再帰して返り値を得る． (left count)
        int right_c = getNodeHeight(node->right); // 右の子ノードに再帰して返り値を得る． (right count)
        if (left_c >= right_c) // もしも，左の返り値が右の返り値以上ならば，
        {
            return ++left_c; // 1 を足して左の返り値を返す． //letf_c += 1
        }
        else // さもなくば， (右の返り値が左の返り値以上ならば，)
        {
            return ++right_c; // 1 を足して右の返り値を返す． // right_c += 1
        }
    }
}

// 二分探索木のノードの高さを取得する関数
int getHeight(Node *node)
{
    return getNodeHeight(node) - 1;
}

// 二分探索木のノードの高さを表示する関数
void printHeight(Node *node)
{
    printf("height: %d\n", getHeight(node));
}

// 2つのノードの大小関係を比較する関数
int compareNodesByScore(Node *a, Node *b)
{
    if (a->score > b->score)
    {
        return 1;
    }
    else if (a->score < b->score)
    {
        return -1;
    }
    else
    {
        return 0;
    }
}

// ノードを挿入するための関数 (再帰関数) (課題7_1_1)
Node *insertNode(Node *newNode, Node *node)
{
    if (node == NULL)
    {
        return newNode;
    }
    else
    {
        int flag = compareNodesByScore(node, newNode);
        if (flag == -1)
        {
            node->right = insertNode(newNode, node->right);
        }
        else if (flag == 1)
        {
            node->left = insertNode(newNode, node->left);
        }
        return node;
    }
}

// 二分探索木にノードを挿入するテスト関数
Node *insertTestData(int scores[], int n)
{
    Node *root = NULL;
    char names[][10] = {"adam",  "bob",     "chris", "daniel",  "edgar",
                        "floyd", "gabriel", "haris", "isabell", "jack"};
    for (int i = 0; i < n; i++)
    {
        Node *node = makeNode(names[i], scores[i]);
        root = insertNode(node, root);
    }
    return root;
}

// テスト関数
void testGetHeight()
{
    printTest("insert test data 1");
    int scores1[] = {3, 6, 5, 1, 4, 8, 2, 0, 9, 7};
    size_t n1 = sizeof(scores1) / sizeof(scores1[0]);
    Node *root = insertTestData(scores1, n1);
    printHeight(root);

    printTest("insert test data 2");
    int scores2[] = {0, 3, 6, 9, 1, 4, 7, 2, 5, 8};
    size_t n2 = sizeof(scores2) / sizeof(scores2[0]);
    root = insertTestData(scores2, n2);
    printHeight(root);

    printTest("insert test data 3");
    int scores3[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    size_t n3 = sizeof(scores3) / sizeof(scores3[0]);
    root = insertTestData(scores3, n3);
    printHeight(root);

    printTest("insert test data 4");
    int scores4[] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
    size_t n4 = sizeof(scores4) / sizeof(scores4[0]);
    root = insertTestData(scores4, n4);
    printHeight(root);
}

// main 関数
int main(void)
{
    testGetHeight();
}
