#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

//힙정렬(찾은것)
#if 0
void heapify(int* arr, int size) {
	for (int i = 1; i < size; ++i) {
		int child = i;
		do {
			//자식 노드가 부모 노드보다 크면 교환
			int root = (child - 1) / 2;
			if (arr[root] < arr[child]) {
				int temp = arr[root];
				arr[root] = arr[child];
				arr[child] = temp;
			}
			child = root;
		} while (child != 0);	//최상단 노드까지 점검
	}
}

//최상단 노드와 최하단 노드 교체
void heap(int* arr, int* size) {
	int temp = arr[0];
	arr[0] = arr[*size - 1];
	arr[*size - 1] = temp;
	--(*size);
}

int main() {

	int size = 10;
	//무작위 배열
	int arr[10] = { 5, 6, 10, 4, 3, 8, 7, 1, 2, 9 };

	//힙정렬
	for (int i = 0; i < 10; ++i) {
		heapify(arr, size);
		heap(arr, &size);
	}

	//출력 
	for (int i = 0; i < 10; ++i) {
		printf("%d ", arr[i]);
	}

	return 0;
}
#endif

//힙정렬(배운것)
#if 1
int data[11] = {0, 5, 6, 10, 4, 3, 8, 7, 1, 2, 9 };

void swap(int i, int j) {
	int temp = data[i];
	data[i] = data[j];
	data[j] = temp;
}


int findlocation(int curidx, int lastidx) {
	int leftidx = curidx * 2;
	int rightidx = leftidx + 1;
	int big = curidx;

	if (leftidx <= lastidx && rightidx <= lastidx && data[leftidx] > data[curidx] && data[rightidx] > data[curidx]) {
		if (data[leftidx] > data[rightidx]) big = leftidx;
		else big = rightidx;
	}

	 {
		if (leftidx <= lastidx && data[leftidx] > data[curidx]) big = leftidx;
		if (rightidx <= lastidx && data[rightidx] > data[curidx]) big = rightidx;
	}

	if (big == curidx) return 0;
	else {
		swap(big, curidx);
		findlocation(big, lastidx);
	}
}

void heapify(int lastidx) {
	int curidx = lastidx / 2;
	while (curidx >= 1) {
		findlocation(curidx, lastidx);
		curidx--;
	}
}

void main() {
	heapify(10);


	for (int i = 10 - 1; i >= 1; i--) {
		swap(1, i + 1);
		heapify(i);
	}

	for (int i = 1; i <= 10; i++) printf("%d ", data[i]);
}
#endif
