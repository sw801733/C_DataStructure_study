#include <stdio.h>

void swap(int arr[], int a, int b)
{
	int temp = arr[a];
	arr[a] = arr[b];
	arr[b] = temp;
}

void findLocation(int arr[], int cur, int last)
{
	int left = cur * 2;
	int right = left + 1;
	int biggest = cur;
	if ((left <= last) && (arr[left] > arr[cur]))
	{
		biggest = left;
	}
	if ((right <= last) && (arr[right] > arr[biggest]))
	{
		biggest = right;
	}
	if (biggest == cur)
	{
		return;
	}
	else
	{
		swap(arr, biggest, cur);
		findLocation(arr, biggest, last);
	}
}

void heapify(int arr[], int last)
{
	int cur = last / 2;
	while (cur >= 1)
	{
		findLocation(arr, cur, last);
		cur--;
	}
}

void del(int arr[], int del, int last)
{
	arr[1] = arr[last];
	arr[last] = -999;
	findLocation(arr, 1, last - 1);
}

int main()
{
	int n, d, i;
	int arr[100] = { 0 };
	scanf("%d", &n);
	for (i = 1; i <= n; i++)
	{
		scanf(" %d", &d);
		arr[i] = d;
		heapify(arr, i);
	}
	scanf(" %d", &d);
	for (i = 0; i < d; i++)
	{
		del(arr, 1, n - i);
	}

	for (i = 0; i < n; i++)
	{
		if (arr[i] == -999)
		{
			break;
		}
		printf("%d ", arr[i]);
	}
}
