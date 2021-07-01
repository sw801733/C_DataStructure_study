#include <stdio.h>
#include <stdlib.h>

struct node
{
	int data;
	struct node* left;
	struct node* right;
};
struct node* root = 0;

#define size 10
int top = -1;
struct node* stack[size];

struct node* createNode(int v)
{
	struct node* new = (struct node*)malloc(sizeof(struct node));
	new->left = new->right = 0;
	new->data = v;
}

addToBST(int v)
{
	struct node* new = createNode(v);
	if (root == 0)
	{
		root = new;
		return;
	}
	else
	{
		struct node* last = root;
		while (1)
		{
			if (v < last->data)
			{
				if (last->left == 0)
				{
					last->left = new;
					return;
				}
				last = last->left;
			}
			else if (v > last->data)
			{
				if (last->right == 0)
				{
					last->right = new;
					return;
				}
				last = last->right;
			}
		}
	}
}

// Ǫ��Ǫ�� BST Ǫ��
void push(struct node* node)
{
	if (top < size - 1) // ���� �ǳ� á�� ����� �Լ� ��µ� �̷��� �ϴ� ����� �־���
	{
		stack[++top] = node;
	}
}

// ���� BST ��
struct node* pop()
{
	struct node* node = NULL;
	if (top >= 0) // ����ī ����
	{
		node = stack[top--];
	}
	return node;
}

void Preorder(struct node* node) // ���� ��ȸ�� �������� ǥ�� �� ����
{
	push(node);
	while (1)
	{
		node = pop();
		if (!node)
		{
			break;
		}
		printf("%d ", node->data);
		push(node->right);
		push(node->left);
	}
}

void Inorder(struct node* node) // ���� ��ȸ��  �������� ǥ���� ���� 
{
	while (1)
	{
		for (; node; node = node->left)
		{
			push(node);
		}
		node = pop();
		if (!node)
		{
			break;
		}
		printf("%d ", node->data);
		node = node->right;
	}
}

void Postorder(struct node* node) // ���� ��ȸ�� �������� ǥ���� ����
{
	while (1)
	{
		do
		{
			if ((node->data != 0) && (node != 0))
			{
				push(node);
				node = node->left;
			}
			else
			{
				break;
			}
		} 		while (node != 0);
		node = pop();
		if (!node)
		{
			break;
		}
		if (node->right != 0)
		{
			if (node->right->data == 0)
			{
				printf("%d ", node->data);
				node->data = 0;
			}
			else
			{
				push(node);
				node = node->right;
			}
		}
		else
		{
			printf("%d ", node->data);
			node->data = 0;
		}


	}
}
int main()
{
	int n;
	for (int i = 0; i < size - 1; i++)
	{
		scanf(" %d", &n);
		addToBST(n);
	}

	Postorder(root);
	return 0;
}