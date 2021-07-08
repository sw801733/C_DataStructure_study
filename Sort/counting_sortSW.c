#include<stdio.h>
# define max 30

void counting_sort(int* arr, int size) {

	int count[max];
	for (int i = 0; i < max; i++) {
		count[i] = 0; // 초기화 
	}

	for (int i = 0; i < size; i++) {
		int val = arr[i];
		count[val]++; // 개수 세기 
	}

	for (int i = 0; i < max; i++) {
		for (int j = 0; j < count[i]; j++) {
			printf("%d ", i);
		}
	}
}

int main() {

	int arr[] = { 1,3,2,4,1,23,12,12,3,12,3,23,23 };
	int size = sizeof(arr) / sizeof(arr[0]);

	counting_sort(arr, size);

	return 0;
}
