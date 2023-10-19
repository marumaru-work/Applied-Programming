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

// 二分探索木の最小値を持つノードを削除する関数 (課題7_1_4)
Node *removeMinScoreNode(Node *node)
{
    if (node == NULL) // もしも，ノードが NULL ならば
    {
        return NULL; // NULL を返す
    }
    else if (node->left == NULL) // さもなくば，もしも，ノードの左の子ノードが NULL ならば
    {
        return node->right; // 右の子ノードを返す
    }
    else // さもなくば，
    {
        Node *node_l = removeMinScoreNode(node->left); // 左の子ノードに再帰して，返り値を受け取る
        node->left = node_l; // その返り値を左の子ノードとする
        return node; // ノードを返す
    }
}

// 二分探索木の最小値を持つノードを削除させる関数
void testRemoveMinNodes(Node *root, int n)
{
    for (int i = 0; i < n; i++)
    {
        root = removeMinScoreNode(root);
        printTree(root);
    }
}

// テスト関数
void testRemove()
{
    printTest("remove min node in test data 1");
    int scores1[] = {3, 6, 5, 1, 4, 8, 2, 0, 9, 7};
    size_t n1 = sizeof(scores1) / sizeof(scores1[0]);
    Node *root = insertTestData(scores1, n1);
    testRemoveMinNodes(root, n1);

    printTest("remove min node in test data 2");
    int scores2[] = {3, 4};
    size_t n2 = sizeof(scores2) / sizeof(scores2[0]);
    root = insertTestData(scores2, n2);
    testRemoveMinNodes(root, n2);

    printTest("remove min node in empty tree");
    root = NULL;
    testRemoveMinNodes(root, 1);
}

// main 関数
int main(void)
{
    // srand((unsigned)time(NULL));
    testRemove();
}
