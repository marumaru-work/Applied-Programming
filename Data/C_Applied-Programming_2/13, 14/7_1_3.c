#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_QUEUE_LENGTH 11  // キューに用いる配列の長さ

// ノードの構造体
typedef struct node
{
    char name[64];
    int score;
    struct node *left;   // 左の子ノード
    struct node *right;  // 右の子ノード
} Node;

// キューの構造体 (課題6 改変)
typedef struct queue
{
    Node *array[MAX_QUEUE_LENGTH];  // キューに用いる配列 (ダブルポインタ)
    int front;                      // キューの先頭を指す添字
    int rear;                       // キューの最後尾を指す添字
} Queue;

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

// キューを生成する関数 (課題6)
Queue *initQueue() 
{
    // printf("initialize queue\n");
    Queue *queue = malloc(sizeof(Queue));
    queue->front = 0;
    queue->rear = 0;
    return queue;
}

// テスト名を表示する関数
void printTest(char *line)
{
    printf("-------------\n");
    printf("test: %s\n", line);
}

// リングバッファにおけるエンキューを行うための関数 (課題6 改変)
void enqueue(Queue *queue, Node *node) // (queue pointer, node pointer)
{
    int rear_num = (queue->rear + 1) % MAX_QUEUE_LENGTH; // 現在の rear の位置から，次の位置を取得
    if (queue->front == rear_num) // エンキュー失敗
    {
        // printf("queue is full\n");
    }
    else // エンキュー成功
    {
        queue->array[queue->rear] = node; // node のアドレス値をキューに代入
        queue->rear = rear_num;
    }
}

// リングバッファにおけるデキューを行うための関数 (課題6 改変)
Node *dequeue(Queue *queue) // (Return value: node pointer / Parameters: queue pointer)
{
    if (queue->front == queue->rear) // デキュー失敗
    {
        // printf("queue is empty\n");
        return NULL; // キューが空ならば，NULL を返す
    }
    else // デキュー成功
    {
        Node *front_item = queue->array[queue->front]; // front を指しているノードをポインタ変数に代入
        queue->front = (queue->front + 1) % MAX_QUEUE_LENGTH;
        return front_item; // デキューに成功したならば，ノードのポインタ変数を返す
    }
}

// 二分探索木を幅優先探索で表示する関数 (課題7_1_3)
void printTreeByBFS(Node *root, int n) // (root pointer, array length)
{
    printf("print tree by BFS\n");
    if (root == NULL) // もしも，ルートが NULL ならば，
    {
        printf("tree is empty\n"); // その旨を表示する → 処理終了 (exit 関数は使わない)
    }
    else
    {
        Queue *queue = initQueue(); // キューの初期化
        enqueue(queue, root); // ルートをエンキュー
        while (queue->front != queue->rear) // キューが空になるまでループ (要素数 (ノードの数) <= キューの長さ)
        {
            Node *node = dequeue(queue); // ノードをデキュー (*1: キューが空や満杯だという判定は，数値 (front & rear) で判定しているため，実際にはメモリ上にキューが残っている (デキュー == front を1つずらしている))
            if (node != NULL) // もしも，そのノードが NULL でないなら (ノードの数が，キューの長さより少ない場合による条件分岐)
            {
                if (node->left != NULL) // もしも，そのノードの左の子ノードが NULL でないなら
                {
                    enqueue(queue, node->left); // そのノードの左の子ノードをエンキュー
                }
                if (node->right != NULL) // もしも，そのノードの右の子ノードが NULL でないなら
                {
                    enqueue(queue, node->right); // そのノードの右の子ノードをエンキュー
                }
            }
        }
        queue->front = 0; // デキューを開始する位置を先頭にする (*2: '*1' より，強制的にキューの先頭に front を指すようにする．この時，rear は front の1つ前を指している状態)
        while (queue->front != queue->rear) // キューの全ての要素を順番にデキューして表示する
        {
            Node *node = dequeue(queue);
            printf("%d %s\n", node->score, node->name);
        }

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

// テスト関数
void testPrintByBFS()
{
    printTest("print test data 1 by BFS");
    int scores1[] = {3, 6, 5, 1, 4, 8, 2, 0, 9, 7};
    size_t n1 = sizeof(scores1) / sizeof(scores1[0]);
    Node *root = insertTestData(scores1, n1);
    printTreeByBFS(root, n1);

    printTest("print test data 2 by BFS");
    int scores2[] = {0, 3, 6, 9, 1, 4, 7, 2, 5, 8};
    size_t n2 = sizeof(scores2) / sizeof(scores2[0]);
    root = insertTestData(scores2, n2);
    printTreeByBFS(root, n2);

    printTest("print test data 3 by BFS");
    int scores3[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    size_t n3 = sizeof(scores3) / sizeof(scores3[0]);
    root = insertTestData(scores3, n3);
    printTreeByBFS(root, n3);

    printTest("print test data 4 by BFS");
    int scores4[] = {9, 8, 7, 6};
    size_t n4 = sizeof(scores4) / sizeof(scores4[0]);
    root = insertTestData(scores4, n4);
    printTreeByBFS(root, n4);

    printTest("print test data 5 by BFS");
    root = NULL;
    printTreeByBFS(root, n4);
}

// main 関数
int main(void)
{
    testPrintByBFS();
}
