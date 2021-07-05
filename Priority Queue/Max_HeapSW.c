#include <stdio.h>
#include <stdlib.h>
/*
* 매크로 함수의 장단점
매크로 함수의 장점은 다음과 같습니다.



1. 매크로 함수는 단순 치환만을 해주므로, 인수의 타입을 신경 쓰지 않습니다.

2. 매크로 함수를 사용하면 여러 개의 명령문을 동시에 포함할 수 있습니다.

3. 함수 호출에 의한 성능 저하가 일어나지 않으므로, 프로그램의 실행속도가 향상됩니다.



매크로 함수의 단점은 다음과 같습니다.



1. 원하는 결과를 얻는 정확한 매크로 함수의 구현은 어려우며, 따라서 디버깅 또한 매우 어렵습니다.

2. 매크로 함수의 크기가 증가하면 증가할수록 사용되는 괄호 또한 매우 많아져서 가독성이 떨어집니다.



따라서 매크로 함수는 크기가 큰 함수보다는 간단한 함수를 대체하는 데 사용하는 것이 좋습니다.
*/

// 우선 순위 큐를 구현할 때 그냥 배열과 연결리스트를 쓰지 않는 이유
//https://angry-tomato.tistory.com/42
typedef int Hnode;
#define Key(n) (n) 
#define Parent(i) (heap[i/2])
#define Left(i) (heap[i*2])
#define Right(i) (heap[i*2+1])
#define MAX_HEAP_NODE 200
Hnode heap[MAX_HEAP_NODE];
int heap_size;

void init_heap() { heap_size = 0; }
int is_empty_heap() { return heap_size == 0; }
int is_full_heap() { return (heap == MAX_HEAP_NODE - 1); }

void insert_heap(Hnode n)
{
	int i;
	if (is_full_heap()) return;
	i = ++(heap_size);
	while (i > 1 && Key(n) > Key(Parent(i))) {
		heap[i] = Parent(i);
		i /= 2;
	}
	heap[i] = n;
}


int main()
{
	printf("%d", Key(3));
}
