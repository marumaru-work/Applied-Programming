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

// テスト名を表示する関数
void printTest(char *line)
{
    printf("-------------\n");
    printf("test: %s\n", line);
}

// ノードを表示させる関数
void printNode(Node *node)
{
    if (node == NULL)
    {
        printf("NULL");
    }
    else
    {
        printf("%d %s\n", node->score, node->name);
    }
}

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

// 二分探索木の小さなラベルから表示させていく関数 (再帰関数)
void printTreeInorder(Node *node)
{
    if (node != NULL)
    {
        printTreeInorder(node->left);  // 左のノードを見に行く
        printNode(node); // ノード (ラベル情報) を表示
        printTreeInorder(node->right);  // 右のノードを見に行く
    }
    else {}
}

// 二分探索木を表示させる関数
void printTree(Node *node)
{
    if (node != NULL)
    {
        printf("print tree\n");
        printTreeInorder(node);
    }
    else
    {
        printf("tree is empty\n");
    }
}

// 2つのノードの大小関係を比較する関数
int compareNodesByScore(Node *a, Node *b)
{
    if (a->score > b->score) // a (node) のノード値が大きい [a > b] (左の子ノードへ)
    {
        return 1;
    }
    else if (a->score < b->score) // b (newNode) のノード値が大きい [a < b] (右の子ノードへ)
    {
        return -1;
    }
    else // a と b のノード値が等しい [a == b] (移動不可)
    {
        return 0;
    }
}

// ノードを挿入するための関数 (再帰関数) (課題7_1_1)
Node *insertNode(Node *newNode, Node *node) // (挿入しようとしている新しいノード, 現在着目しているノード)
{
    if (node == NULL) // 現在着目しているノードが NULL のとき，
    {
        return newNode; // newNode を返す．
    }
    else // 二分探索木のノード (ルート) が NULL ではないとき，
    {
        int flag = compareNodesByScore(node, newNode); // node と newNode を引数とし，compareNodesByScore 関数を呼び出し，返り値を得る．
        if (flag == -1) // その返り値が新たに挿入されるノードの値が現在着目しているノードの値より大きいことを意味するなら，
        {
            node->right = insertNode(newNode, node->right); // 右の子ノードについて，再帰する．
        }
        else if (flag == 1) // その返り値が新たに挿入されるノードの値が現在着目しているノードの値より小さいことを意味するなら，
        {
            node->left = insertNode(newNode, node->left); // 左の子ノードについて，再帰する．
        }
        else
        {
            return node; // node を返す．
        }
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
        Node *node = makeNode(names[i], scores[i]); // 新しくノードを作成
        root = insertNode(node, root); // 挿入後，ルートのポインタを格納．
    }
    return root;
}

// テスト関数
void testInsert()
{
    printTest("insert test data 1");
    int scores1[] = {3, 6, 5, 1, 4, 8, 2, 0, 9, 7};
    size_t n1 = sizeof(scores1) / sizeof(scores1[0]);
    Node *root = insertTestData(scores1, n1);
    printTree(root);

    printTest("insert test data 2");
    int scores2[] = {0, 3, 6, 9, 1, 4, 7, 2, 5, 8};
    size_t n2 = sizeof(scores2) / sizeof(scores2[0]);
    root = insertTestData(scores2, n2);
    printTree(root);

    printTest("insert test data 3");
    int scores3[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    size_t n3 = sizeof(scores3) / sizeof(scores3[0]);
    root = insertTestData(scores3, n3);
    printTree(root);

    printTest("insert test data 4");
    int scores4[] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
    size_t n4 = sizeof(scores4) / sizeof(scores4[0]);
    root = insertTestData(scores4, n4);
    printTree(root);
}

// main 関数
int main(void)
{
    testInsert();
}
