#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_QUEUE_LENGTH 11  // キューに用いる配列の長さ
#define N 100                //乱数の範囲

typedef struct queue
{
    int array[MAX_QUEUE_LENGTH];  // キューに用いる配列
    int front;                    // キューの先頭を指す添字
    int rear;                     // キューの最後尾を指す添字
} Queue;

Queue *initQueue()
{
    printf("initialize queue\n");
    Queue *queue = malloc(sizeof(Queue));
    queue->front = 0;
    queue->rear = 0;
    return queue;
}

void printTest(char *line)
{
    printf("-------------\n");
    printf("test: %s\n", line);
}

// キューの front と rear を表示する関数
void printFrontAndRear(Queue *queue)
{
    printf("front:%2d, rear:%2d\n", queue->front, queue->rear);
}

// キューを出力する関数
void printQueue(Queue *queue)
{
    if (queue->front == queue->rear)
    {
        printf("queue is empty\n");
    }
    else
    {
        for (int h = queue->front; h != queue->rear; h = (h + 1) % MAX_QUEUE_LENGTH)
        {
            printf("queue[%2d]: %2d\n", h, queue->array[h]);
        }
    }
}

// リングバッファにおけるエンキューを行うための関数
void enqueue(Queue *queue, int value)
{
    int rear_num = (queue->rear + 1) % MAX_QUEUE_LENGTH; // 現在の rear の位置から，1つ次の位置を取得
    if (queue->front == rear_num) // エンキュー失敗
    {
        printf("queue is full\n");
    }
    else // エンキュー成功
    {
        queue->array[queue->rear] = value;
        queue->rear = rear_num;
        // printf("enqueue: %2d\n", value);
    }
}

// リングバッファにおけるデキューを行うための関数
int dequeue(Queue *queue)
{
    if (queue->front == queue->rear) // デキュー失敗
    {
        printf("queue is empty\n");
        return -1;
    }
    else // デキュー成功
    {
        int front_item = queue->array[queue->front];
        queue->front = (queue->front + 1) % MAX_QUEUE_LENGTH;
        printf("dequeue: %2d\n", front_item);
        return front_item;
    }
}

// エンキューする要素 (乱数) を生成する関数
void enqueueTestItems(Queue *queue, int n)
{
    for (int i = 0; i < n; i++)
    {
        int score = rand() % N;
        enqueue(queue, score);
    }
}

// n 個分、キューの要素をデキューさせる関数
void dequeueMultipleItems(Queue *queue, int n)
{
    for (int i = 0; i < n; i++)
    {
        dequeue(queue);
    }
}

void testDequeue(Queue *queue)
{
    printTest("dequeue empty queue");
    dequeue(queue);
    printTest("enqueue 10 items");
    enqueueTestItems(queue, 10);
    printTest("print queue");
    printQueue(queue);
    printTest("dequeue all items");
    dequeueMultipleItems(queue, 10);
    printTest("dequeue empty queue");
    dequeue(queue);
    printTest("print empty queue");
    printQueue(queue);
    printTest("enqueue 10 items");
    enqueueTestItems(queue, 10);
    printQueue(queue);
    printTest("dequeue 8 items");
    dequeueMultipleItems(queue, 8);
    printTest("print queue");
    printQueue(queue);
    printTest("enqueue 9 items");
    enqueueTestItems(queue, 9);
    printTest("print queue");
    printQueue(queue);
}

int main(void)
{
    // srand((unsigned)time(NULL));
    Queue *queue = initQueue();
    testDequeue(queue);
}