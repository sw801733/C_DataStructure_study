#ifndef DEQUE_H_ // ifndef ~ #define ~ #endif의 의미는 만약 아래 DEQUE_H_가 정의되지 않은 처음 상태라면 즉, #include "deque.h"
//을 한번 만 참조하면 define을 하지만 그 이상 #include "deque.h"을 하면 더이상 define을 즉, 재정의를 하지 않는다는 소리
// 만약 #ifndef와 #endif를 사용하지 않는다면 재정의에 대한 error가 발생한다.
#define DEQUE_H_


//deque.h로 헤더 파일, 코드의 내용이 길어지고 함수의 사용이 많아진다면 h파일을 이용하자.

#include <stdio.h>
#include <stdlib.h>        // malloc, free 함수를 사용하기 위함

// 출처: https://yahma.tistory.com/15


#define    TRUE     1
#define    FALSE    0

typedef struct _node        // 노드
{
    int data;               // 사용자에게 입력 받은 데이터를 저장
    struct _node* prev;    // 노드가 이전 노드를 가리킬 포인터 변수
    struct _node* next;    // 노드가 다음 노드를 가리킬 포인터 변수
} Node;

typedef struct _dlDque      // 양방향 연결 리스트 덱
{
    Node* head;            // 앞 노드를 가리킬 포인터 변수
    Node* tail;            // 뒤 노드를 가리킬 포인터 변수
} DLDeque;

typedef DLDeque Deque;

void DequeInit(Deque* pdeq);               // 덱을 초기화
int DQIsEmpty(Deque* pdeq);                // 덱에 데이터가 비워져 있는지 확인

void DQAddFirst(Deque* pdeq, int data);    // 덱의 앞에 노드를 추가
void DQAddLast(Deque* pdeq, int data);     // 덱의 뒤에 노드를 추가

int DQRemoveFirst(Deque* pdeq);            // 덱의 앞에 있는 노드를 삭제
int DQRemoveLast(Deque* pdeq);             // 덱의 뒤에 있는 노드를 삭제

int DQGetFirst(Deque* pdeq);               // 덱의 앞에 있는 노드의 데이터를 조회
int DQGetLast(Deque* pdeq);                // 덱의 뒤에 있는 노드의 데이터를 조회


//

#endif
