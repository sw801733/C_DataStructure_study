#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>




#if 0
#define print(x) printf("%d\n", x)
#define printp(x) printf("%p\n", x)
#define Line printf("/* ----------------------------- */\n\n") 
#define toString(name) #name

typedef struct stack {
    int top;
    int* data; //배열
    int max; //배열의 최대크기
}Stack;


void StackInitialize(Stack* stk, int size);
void StackPush(Stack* stk, int value);
int StackPop(Stack* stk);
int StackPeek(Stack* stk);
int StackSize(Stack* stk);
int StackIsEmpty(Stack* stk);
int StackShow(Stack* stk);
int getRandomInt(int from, int to);
void deleteStack(Stack* stk);

int main(int argc, char const* argv[])
{
    srand(time(NULL));

    Stack s;
    StackInitialize(&s, 5);

    StackShow(&s);
    Line;

    for (int i = 1; i <= 12; i++)
    {
        int random = getRandomInt(1, 50);
        StackPush(&s, random);
    }

    Line;

    StackPop(&s);
    StackPop(&s);
    StackPop(&s);

    StackShow(&s);
    deleteStack(&s);

    return 0;
}

/* ------------ 함수영역 ------------ */


// 초기화

void StackInitialize(Stack* stk, int size)
{
    stk->data = (int*)malloc(size * sizeof(int));
    stk->top = -1;
    stk->max = size;
}

// Push

void StackPush(Stack* stk, int value)
{
    if (stk->top < stk->max - 1)
    {
        stk->top++;
        stk->data[stk->top] = value;
        printf("-> value pushed: %d\n", value);
    }
    else
    {
        // 스택이 떨어진 경우 사이즈를 2배로 메모리 재할당. Push
        stk->max = stk->max * 2;
        stk->data = (int*)realloc(stk->data, stk->max * sizeof(int));
        printf("[Memory reallocation] ");
        printf("Stack size doubled... size : %d\n", stk->max);
        StackPush(stk, value);
    }
}

// Pop

int StackPop(Stack* stk)
{
    if (stk->top >= 0)
    {
        int value = stk->data[stk->top];
        stk->top--;
        printf("-> value popped: %d\n", value);
        return value;
    }
    printf("*stack is empty...\n");
    return 0;
}

int StackPeek(Stack* stk)
{
    int value = stk->data[stk->top];
    return value;
}

int StackSize(Stack* stk)
{
    return(stk->top + 1);
}

int StackIsEmpty(Stack* stk)
{
    return(stk->top == -1);
}

int StackShow(Stack* stk)
{
    if (StackIsEmpty(stk)) {
        printf("stack is empty...\n");
    }
    else {
        printf("\n[Show Stack]\n");
        printf("*Stack Size: %d, Max Stack Size %d\n", StackSize(stk), stk->max);
        StackIsEmpty(stk) ? printf("(stack is empty)\n") :
            printf("(stack is not empty)\n");
        printf("*top of the Stack : %d\n", StackPeek(stk));

        printf("[ ");
        for (int i = 0; i <= stk->top; i++)
        {
            printf("%d, ", stk->data[stk->top - i]);
        }
        printf(" ]\n");

    }
}

int getRandomInt(int from, int to)
{
    int random = rand() % (to - from + 1) + from;
    return random;
}

void deleteStack(Stack* stk)
{
    free(stk->data);
    Line;
    printf("Stack [%s] is deleted...", toString(stk));
}
#endif
