#include <stdio.h>
#include <stdlib.h>


/*
결론적으로 Dummy Node 를 쓰는 이유는 head를 항상 Null인 상태로 만들어
함수나 동작을 구현할 때 head == Null 인 조건을 생략하기 위해서이다.
*/

// 노드 데이터
typedef struct node {
    char data[3];
    struct node* next;
} node;

// 연결 리스트 메타데이터
// head와 tail ,size를 계속해서 갱신하여 만들어지는 연결리스트의 접근을 편하게 한다.
// tail이라는 꼬리노드를 통해 마지막 노드를 매번 갱신하여 마지막 노드를 사용할 때 유용하다.
typedef struct LinkedList {
    node* head; // 머리 노드
    node* tail; // 꼬리 노드
    int size; // 연결리스트 크기
} LinkedList;


/* 더미 노드를 사용하지 않을 때.
* LinkedList* new(){
    LinkedList * lk = (LinkedList*)malloc(sizeof(LinkedList));
    lk->head = NULL;
    lk->tail = NULL;
    lk->size = 0;
    puts("-------------------------------------------------------");
    printf("%40s\n", "Linked List Initiated.");
    puts("-------------------------------------------------------");
    return lk;
}
*/

// 더미노드를 갖는 새로운 연결리스트를 생성할 때
LinkedList* new(){
    LinkedList * lk = (LinkedList*)malloc(sizeof(LinkedList));
    lk->head = lk->tail = (node*)malloc(sizeof(node)); // 더미 노드 생성
    lk->head->next = NULL; // 더미 노드가 NULL을 가리키도록 초기화
    lk->size = 0;
    puts("-------------------------------------------------------");
    printf("%40s\n", "Linked List Initiated.");
    puts("-------------------------------------------------------");
    return lk;
}

/* 더미 노드를 사용하지 않을 때.
* void add(LinkedList* lk, char data[]) {
    node* tmp = (node*)malloc(sizeof(node));
    strcpy(tmp->data, data);
    tmp->next = NULL;

    if (lk->head == NULL)
        lk->head = tmp;
    else
        lk->tail->next = tmp;
    lk->tail = tmp;
    ++lk->size;
}
*/

// add 함수로 dummy Node를 사용하기 문에 항상 head는 비어있어서
// head == NULL이라는 조건을 가질 필요가 없다.
void add(LinkedList* lk, char data[]) {
    node* tmp = (node*)malloc(sizeof(node));
    strcpy(tmp->data, data);
    tmp->next = NULL;

    lk->tail->next = tmp;
    lk->tail = tmp;
    ++lk->size;
}

/* 더미노드를 사용하지 않을 때.
*
* void insert(LinkedList* lk, int n, char data[]) {
    if (n == size(lk) + 1) // 맨 끝에 삽입한다면 그냥 add()를 호출한다
        add(lk, data);
    else if (n < 1 || n > size(lk) + 1) // 리스트 범위 밖이라면
        printf("해당 위치(%d)에 노드를 삽입할 수 없습니다.\n", n);
    else { // 맨 끝이 아닌 리스트 범위 내의 다른 곳이라면
        node* tmp = (node*)malloc(sizeof(node));
        strcpy(tmp->data, data);

        if (n == 1) { // 그런데 하필 맨 앞이라면
            tmp->next = lk->head; // head 포인터가 가리키는 맨 처음 노드를 tmp 다음에 연결
            lk->head = tmp; // head 포인터가 tmp를 가리키도록 갱신
        }
        else { // 맨 앞도 아니라면
            node* cur = lk->head;
            while (--n - 1) // 반복문으로 지정 위치 이전 노드에 접근
                cur = cur->next;

            tmp->next = cur->next; // tmp의 다음에 cur의 다음 노드를 연결
            cur->next = tmp; // cur의 다음 노드를 tmp로 갱신
        }
        ++lk->size;
    }
}
*/

// 더미노드를 사용할 때 insert를 한번에 처리하는 함수로 
// head는 항상 NULL을 가리키기 때문에 head를 새로 갱신할 필요가 없어서 조건이 단순해진다.
void insert(LinkedList* lk, int n, char data[]) {
    if (n == size(lk) + 1) // 맨 끝에 삽입한다면 그냥 add()를 호출한다
        add(lk, data);
    else if (n < 1 || n > size(lk) + 1) // 리스트 범위 밖이라면
        printf("해당 위치(%d)에 노드를 삽입할 수 없습니다.\n", n);
    else { // 맨 끝이 아닌 리스트 범위 내의 다른 곳이라면
        node* tmp = (node*)malloc(sizeof(node));
        strcpy(tmp->data, data);

        node* cur = lk->head;
        while (--n) // 반복문으로 지정 위치 이전 노드에 접근
            cur = cur->next;

        tmp->next = cur->next; // tmp의 다음에 cur의 다음 노드를 연결
        cur->next = tmp; // cur의 다음 노드를 tmp로 갱신
        ++lk->size;
    }
}


/* 더미노드를 사용하지 않을 때
* void delete(LinkedList* lk, int n) {
    if (n < 1 || n > size(lk)) // 리스트 범위 밖이라면
        printf("해당 위치(%d)의 노드를 삭제할 수 없습니다.\n", n);
    else { // 리스트 범위 안이라면
        node* tmp;
        if (n == 1) { // 맨 앞 노드를 삭제할거라면
            tmp = lk->head; // 맨 앞 노드 주소를 tmp에 저장
            lk->head = lk->head->next; // head 포인터가 맨 앞 노드 다음을 가리키도록 갱신
            if (n == size(lk)) lk->tail = NULL; // 마지막 남은 노드면 tail 포인터를 NULL로 갱신
        }
        else { // 맨 앞이 아니라면
            node* cur = lk->head; // cur을 맨 처음 노드로 맞춰놓고
            int i = n;
            while (--i - 1) // 삭제할 노드 직전까지 찾아간다
                cur = cur->next;

            tmp = cur->next; // 삭제할 노드는 cur 다음의 노드이므로 이를 tmp에 저장
            cur->next = cur->next->next; // cur의 next 포인터에 cur의 다음 다음 노드를 연결
            if (n == size(lk)) lk->tail = cur; // 꼬리 노드 삭제이면 tail 포인터를 갱신한다
        }
        free(tmp); // 삭제하려는 노드는 메모리를 해제시킨다
        --lk->size;
    }
}

*/


void delete(LinkedList* lk, int n) {
    if (n < 1 || n > size(lk)) // 리스트 범위 밖이라면
        printf("해당 위치(%d)의 노드를 삭제할 수 없습니다.\n", n);
    else { // 리스트 범위 안이라면
        node* tmp;
        node* cur = lk->head; // cur을 맨 처음 노드로 맞춰놓고
        int i = n;
        while (--i) // 삭제할 노드 직전까지 찾아간다
            cur = cur->next;

        tmp = cur->next; // 삭제할 노드는 cur 다음의 노드이므로 이를 tmp에 저장
        cur->next = cur->next->next; // cur의 next 포인터에 cur의 다음 다음 노드를 연결
        if (n == size(lk)) lk->tail = cur; // 맨 끝 노드 삭제이면 tail 포인터를 갱신한다

        free(tmp); // 삭제하려는 노드는 메모리를 해제시킨다
        --lk->size;
    }
}

void print(LinkedList* lk) {
    node* cur = lk->head->next;
    printf("리스트 구조: ");
    if (cur != NULL) { // 현재의 노드 포인터가 NULL을 가리키지 않는다면
        for (;;) {
            printf("%s", cur->data);
            if (cur->next == NULL) { // 마지막 노드라면
                printf("\n"); // 개행 출력
                break;
            }
            else printf(" -> "); // 마지막 노드가 아니라면 화살표 출력
            cur = cur->next;
        }
    }
    else puts("NO DATA"); // 현재의 노드 포인터가 NULL을 가리킨다면
}
