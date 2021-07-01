#include "deque.h"

// 함수만 만드는 소스 코드를 따로 만들어서 보관하면 main함수나 다른 소스코드에서 사용할 때 h파일만 참조하면 되므로 알아두자.


// 덱은 원형 큐의 동작에서 front에서도 add와 delete가 가능하다는 점. 




// 덱을 초기화 //
void DequeInit(Deque* pdeq)
{
    pdeq->head = NULL;
    pdeq->tail = NULL;
}

// 덱에 데이터가 비워져 있는지 확인 //
int DQIsEmpty(Deque* pdeq)
{
    if (pdeq->head == NULL)
        return TRUE;

    else
        return FALSE;
}

// 덱의 앞에 노드를 추가 //
// 만약 dll이 아닌 배열로 구현하게 되면 front는 index 0으로 고정이 아닌 뒤로 저장하기 때문에 큐의 제일 마지막 index로 이동하여
// 뒤로 실행할 수로 front 값은 계속 변하게 된다. 마치 rear가 계속 증가하는 것 처럼
/* void add_front(Deque *p, int data)
    {
        if(isFull(q))
            error("큐가 공백상태입니다");
        q->data[q->front] = data;
        q->front = (q->front - 1 + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE; // 큐의 사이즈를 더해주는 이유는 음수 값을 방지하기 위해


    }
*/
void DQAddFirst(Deque* pdeq, int data)
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;

    newNode->next = pdeq->head;

    if (DQIsEmpty(pdeq))
        pdeq->tail = newNode;

    else
        pdeq->head->prev = newNode;

    newNode->prev = NULL;
    pdeq->head = newNode;
}


// 덱의 뒤에 노드를 추가 //
void DQAddLast(Deque* pdeq, int data)
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;

    newNode->prev = pdeq->tail;

    if (DQIsEmpty(pdeq))
        pdeq->head = newNode;

    else
        pdeq->tail->next = newNode;

    newNode->next = NULL;
    pdeq->tail = newNode;
}

// 덱의 앞에 있는 노드를 삭제 //
int DQRemoveFirst(Deque* pdeq)
{
    Node* rnode = pdeq->head;
    int rdata;

    if (DQIsEmpty(pdeq))
    {
        printf("Deque Memory Empty!!");

        exit(-1);
        /*
        * exit() 함수 외에도 _exit() 함수와 _Exit() 함수가 있습니다. 이 둘 함수가 exit() 함수와 다른점은 exit()함수는

        atexit() 함수로 등록한 종료 핸들러가 있다면 이 핸들러를 모두 처리하고, 표준 입출력 스트림을 닫는 작업을 수행한

        후 커널의 종료 작업을 실행하지만 _exit(), _Exit() 함수는 바로 커널에서 종료작업을 실행한다는 것입니다.

        커널 종료 작업이라고 하면 프로세스가 사용하던 메모리를 해제하고 열어놓았던 파일의 descriptor등 을 닫는 작업 등 을 말합니다.

        유닉스 계열 시스템에서 _exit() 함수와 _Exit() 함수는 같은 함수라고 생각해도 좋습니다.
        */
    }

    rdata = pdeq->head->data;

    pdeq->head = pdeq->head->next;
    free(rnode);

    if (pdeq->head == NULL)
        pdeq->tail = NULL;

    else
        pdeq->head->prev = NULL;

    return rdata;
}

// 덱의 뒤에 있는 노드를 삭제 //
int DQRemoveLast(Deque* pdeq)
{
    Node* rnode = pdeq->tail;
    int rdata;

    if (DQIsEmpty(pdeq))
    {
        printf("Deque Memory Empty!!");
        exit(-1);
    }

    rdata = pdeq->tail->data;

    pdeq->tail = pdeq->tail->prev;
    free(rnode);

    if (pdeq->tail == NULL)
        pdeq->head = NULL;

    else
        pdeq->tail->next = NULL;

    return rdata;
}

// 덱의 앞에 있는 노드의 데이터를 조회 //
int DQGetFirst(Deque* pdeq)
{
    if (DQIsEmpty(pdeq))
    {
        printf("Deque Memory Empty!!");
        exit(-1);
    }

    return pdeq->head->data;
}


// 덱의 뒤에 있는 노드의 데이터를 조회 //
int DQGetLast(Deque* pdeq)
{
    if (DQIsEmpty(pdeq))
    {
        printf("Deque Memory Empty!!");
        exit(-1);
    }

    return pdeq->tail->data;
}

#include "deque.h"
#include <stdio.h>
#include <stdio.h>
// main 함수만 따로 소스코드를 만들어서 저장하여 실제 동작하는 모습만을 보여주어 가독성을 높일 수 있겠다.

int main(void)
{
    // 덱 생성 및 초기화 //
    Deque deq;
    DequeInit(&deq);

    /* [데이터 넣기 1차] */
    // 데이터 넣기(앞) //
    DQAddFirst(&deq, 3); DQAddFirst(&deq, 2); DQAddFirst(&deq, 1);

    // 데이터 넣기(뒤) //
    DQAddLast(&deq, 4); DQAddLast(&deq, 5); DQAddLast(&deq, 6);

    // 데이터 꺼내기(앞부터) //
    printf("[데이터 앞에서부터 꺼내기]\n");
    while (!DQIsEmpty(&deq))
        printf("%d ", DQRemoveFirst(&deq));

    printf("\n\n");

    /* [데이터 넣기 2차] */
    // 데이터 넣기(앞) //
    DQAddFirst(&deq, 3); DQAddFirst(&deq, 2); DQAddFirst(&deq, 1);

    // 데이터 넣기(뒤) //
    DQAddLast(&deq, 4); DQAddLast(&deq, 5); DQAddLast(&deq, 6);

    // 데이터 꺼내기(뒤부터) //
    printf("[데이터 뒤에서부터 꺼내기]\n");
    while (!DQIsEmpty(&deq))
        printf("%d ", DQRemoveLast(&deq));

    return 0;
}

