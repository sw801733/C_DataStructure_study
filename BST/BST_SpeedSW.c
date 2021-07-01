#include <stdio.h>
#include <stdlib.h>
#include <time.h> 
struct node {
	int i;
	struct node* left;
	struct node* right;
};

struct node* root = 0;

void addBST(int v)
{
	struct node* new = (struct node*)malloc(sizeof(struct node));
	new->i = v;
	new->left = 0;
	new->right = 0;

	if (root == 0)
		root = new;
	else
	{
		struct node* tm = root;
		while (1)
		{
			if (tm->i > new->i)
			{
				if (tm->left == 0)
				{
					tm->left = new;
					return;
				}
				else
					tm = tm->left;
			}
			else if (tm->i < new->i)
			{
				if (tm->right == 0)
				{
					tm->right = new;
					return;
				}
				else
					tm = tm->right;
			}
			else
			return;

		}
	}
}

struct node* newNode(int k) {
	struct node* p = (struct node*)malloc(sizeof(struct node));
	*p = (struct node){ k, NULL, NULL };
	return p;
}

struct node* insert(struct node* p, int k) {
	if (p == NULL) return newNode(k);

	if (k == p->i) {
		return;
	}
	else if (k < p->i) {
		p->left = insert(p->left, k);
	}
	else if (k > p->i) {
		p->right = insert(p->right, k);
	}
	return p;
}

void inorderTraversal(struct node* node)
{
	if (node == 0)
		return;
	inorderTraversal(node->left);
	printf("%d ", node->i);
	inorderTraversal(node->right);
}



int main() { 
	time_t start, end;
	double result; start = time(NULL); 
// 수행 시간 측정 시작
	int i;
	int a;
	for (i = 0; i < 10000; i++)
	{
		
		//root = insert(root, i);
		addBST(i);
	}

/* 수행시간 측정하고자 하는 코드 */ 
	inorderTraversal(root);
	end = time(NULL); // 시간 측정 끝 
	result = (double)(end - start); 
// 결과 출력
	printf("\n%f", result); 
return 0;
}

