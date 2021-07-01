#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#if 1


typedef struct _node {
	int data;
	struct _node* leftChild;
	struct _node* rightChild;
}node;

node* root;

node* Create(int data) {
	node* nd;
	nd = (node*)malloc(sizeof(node));
	nd->leftChild = NULL;
	nd->rightChild = NULL;
	nd->data = data;

	return nd;
}


node* add(node* root, int data) {
	if (root == 0) {
		root = Create(data);
		return root;
	}
	else if (data < root->data) {
		root->leftChild = add(root->leftChild, data);
	}
	else {
		root->rightChild = add(root->rightChild, data);
	}
	return root;
}

#define MAX_QUEUE_SIZE 100
node* Queue[MAX_QUEUE_SIZE];
int front = 0; int rear = 0; // 전역변수 선언

void Enqueue(node* ptr) {
	Queue[++rear] = ptr;
}

node* Dequeue() {
	return Queue[++front];
}

void levelOrder(node* ptr) {
	if (!ptr)
		return;
	Enqueue(ptr);

	while (1) {
		ptr = Dequeue();
		if (ptr)
		{
			printf("%d ", ptr->data);

			if (ptr->leftChild)
				Enqueue(ptr->leftChild);
			if (ptr->rightChild)
				Enqueue(ptr->rightChild);
		}
		else
			break;
	}
}

int main(void)
{
	/* 예시를 위한 트리 생성 */
	int i = 0;
	while (1) {

		scanf("%d", &i);
		if (i == 0) break;
		root = add(root, i);
	}

	printf("[구현 결과] level order : ");
	levelOrder(root);

	return 0;
}
#endif

#if 0
typedef struct node {
	int data;
	struct node* left;
	struct node* right;
}A;

A* root;

int heap[100];

A* add(A* root, int v) {
	if (root == 0) {
		root = (A*)malloc(sizeof(A));
		root->left = root->right = 0;
		root->data = v;
		return root;
	}
	else {
		if (v < root->data) root->left = add(root->left, v);
		else root->right = add(root->right, v);
	}
	return root;
}

A* fmin(A* min) {
	//A* min = root;
	while (min->left != 0) min = min->left;
	return min;
}

A* del(A* root, int v) {
	A* tmp = 0;
	if (root == 0) return 0;
	
	if (v < root->data) root->left = del(root->left, v);
	else if (v > root->data) root->right = del(root->right, v);

	else {
		if (root->left != 0 && root->right != 0) {
			tmp = fmin(root->right);
			root->data = tmp->data;
			root->right = del(root->right, tmp->data);
		}
		else {
			tmp = (root->left == 0) ? root->right : root->left;
			free(root);
			return tmp;
		}
	}
	return root;
}

int j = 0;

int heapadd(A* root,int i) {
	if (root == 0) return;
	j++;
	heap[i] = root->data;
	i *= 2;
	heapadd(root->left,i);
	i += 1;
	heapadd(root->right,i);
}

void printall(A* root) {
	if (root == 0) return ;
	printall(root->left);
	printf("%d ", root->data);
	printall(root->right);
}

void main() {
	int i = 0;
	while(1) {

		scanf("%d", &i);
		if (i == 0) break;
		root=add(root,i);
	}

	heapadd(root, 1);

	for (int i = 1; i <= 100; i++) printf("%d ", heap[i]);

	j = 0;

	/*printf("root : %d \n",root->data);
	scanf("%d", &i);
	del(root, i);
	printf("root : %d \n", root->data);
	printall(root);*/
}

#endif
