#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define N 10

// スタック構造体
typedef struct stack
{
    int data[N];
    int head;
} Stack;

// テスト名を表示する関数
void printTest(char *line)
{
    printf("-------------\n");
    printf("test: %s\n", line);
}

// スタックを初期化する関数
Stack *initStack()
{
    printf("initialize stack\n");
    Stack *stack = malloc(sizeof(Stack));
    stack->head = 0;
    return stack;
}

// スタックへデータを挿入する関数 (課題8_1_1)
void push(Stack *stack, int v)
{
    if (stack->head == N) // もし，head が指す番号が，定数 N (スタック (data[N]) の長さ) と同じならば，(スタック (data[N]) が満杯ならば，)
    {
        printf("push: stack is full\n"); // その旨を表示する．
    }
    else // さもなければ， (スタック (data[N]) にまだ空データがあるならば，)
    {
        stack->data[stack->head++] = v; // head が指す番号に，データを挿入する．
        // "stack->head++" は，"ポストインクリメント" と言う．"stack->data[stack->head++] = v;" という処理の'後'に，head の値を 1 足して，処理を終える．
    }
}

// スタックからデータの取り出す関数 (課題8_1_1)
int pop(Stack *stack)
{
    if (stack->head == 0) // head が 0 ならば， (スタック (data[N]) が空ならば，)
    {
        printf("pop: stack is empty\n"); // その旨を表示して，
        return 0; // pop 処理を終了する．
    }
    else // さもなければ， (スタック (data[N]) にデータが格納されているのならば，)
    {
        return stack->data[--stack->head]; // スタック (data[N]) の，head が指す番号 - 1 番目にあるデータを返す．
        // "--stack->head" は，"プリデクリメント" と言う．"stack->data[--stack->head];" という処理の'前'に，head の値を 1 引いて，処理を実行する．
    }
}

// スタックを表示する関数
void printStack(Stack *stack)
{
    printf("print: all stacked data\n");
    for (int i = 0; i < stack->head; i++)
    {
        printf(" %d", stack->data[i]);
    }
    printf("\n");
}

// テスト関数
void testStack()
{
    Stack *stack = initStack();
    printTest("pop empty stack");
    pop(stack);

    printTest("push 4 items");
    for (int i = 0; i < 4; i++)
    {
        push(stack, i);
    }

    printStack(stack);
    printTest("pop 2 items");
    for (int i = 0; i < 2; i++)
    {
        printf("pop: %d\n", pop(stack));
    }
    printStack(stack);

    printTest("push 8 items");
    for (int i = 3; i < 11; i++)
    {
        push(stack, i);
    }
    printStack(stack);

    printTest("push a item to full stack");
    push(stack, 20);
}

// main 関数
int main(void)
{
    testStack();
}
