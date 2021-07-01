#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define max(a,b)    (((a) > (b)) ? (a) : (b))
struct node
{
	int i;
	struct node* left;
	struct node* right;
};
struct node* root = 0;
struct node* rotate_LL(struct node* parent)
{
	struct node* child = parent->left;
	parent->left = child->right;
	child->right = parent;
	return child;
}

// LL ȸ�� (���������� ȸ���Ѵ�)
//     A
//    /                B
//   B        ->      / \
//  /                C   A
// C
//
// ��2�� ������ A�� �θ� �ǰ� A->left_child�� B�� child�� �ȴ�.
// A->left�� B�� ������ �ִ� right_child�� �����ϰ� B�� right_child�� A�� �����Ѵ�.
struct node* rotate_RR(struct node* parent)
{
	struct node* child = parent->right ;
	parent->right  = child->left ;
	child->left = parent;
	return child;
}
// RR ȸ�� (�������� ȸ���Ѵ�)
//     A
//      \               B
//       B     ->      / \
//        \           A   C
//         C
//
// ��2�� ������ A�� �θ� �ǰ� A->right_child�� B�� child�� �ȴ�.
// A->right�� B�� ������ �ִ� left_child�� �����ϰ� B�� left_child�� A�� �����Ѵ�.
struct node* rotate_RL(struct node* parent)
{
	struct node* child = parent->right ;
	parent->right  = rotate_LL(child);
	return rotate_RR(parent);
}
// RL ȸ�� (������-�������� ȸ���Ѵ�)
//     A                A              
//      \                \                C
//       B      ->        C      ->      / \
//      /                  \            A   B
//     C                    B
//
// ��2�� ������ A�� �θ� �ǰ� A->right_child�� B�� child�� �ȴ�.
// A->right_child�� rotate_LL(B)�� ��ȯ�ϴ� ���� �����Ѵ�. (B,C�� ���� ������ ȸ��)
// rotate_LL(B)ȣ��� B�� C�� ��ȭ�� ����� �ٽ� rotate_RR(A)�� ȣ���ϸ� ����Ʈ���� �ȴ�. 
struct node* rotate_LR(struct node* parent)
{
	struct node* child = parent->left ;
	parent->left  = rotate_RR(child);
	return rotate_LL(parent);
}
// LR ȸ�� (����-���������� ȸ���Ѵ�)
//     A                 A              
//	  /                 /                  C
//   B         ->      C          ->      / \
//    \               /                  A   B
//     C             B      
//
// ��2�� ������ A�� �θ� �ǰ� A->left_child�� B�� child�� �ȴ�.
// A->left_child�� rotate_RR(B)�� ��ȯ�ϴ� ���� �����Ѵ�. (B,C�� ���� ���� ȸ��)
// rotate_RR(B)ȣ��� B�� C�� ��ȭ�� ����� �ٽ� rotate_LL(A)�� ȣ���ϸ� ����Ʈ���� �ȴ�. 

int get_height(struct node* node) //Ʈ���� ���� ����
{
	int height = 0;
	if (node != NULL)
		height = 1 + max(get_height(node->left ), get_height(node->right ));
	return height;
}

int get_balance(struct node* node) 
{
	if (node == NULL) return 0;
	return get_height(node->left ) - get_height(node->right );
}

struct node* balance_tree(struct node* node)
{
	int height_diff = get_balance(node);

	if (height_diff > 1) // ���� ����Ʈ���� ������ �����
	{
		if (get_balance((node)->left ) > 0)
			node = rotate_LL(node);
		else
			node = rotate_LR(node);
	}
	else if (height_diff < -1) // ������ ����Ʈ���� ������ �����
	{
		if (get_balance((node)->right ) < 0)
			node = rotate_RR(node);
		else
			node = rotate_RL(node);
	}
	return node;
}



void add(int a)
{
	struct node* b = (struct node*)malloc(sizeof(struct node));
	b->i = a;
	b->left = b->right = 0;

	if (root == 0)
	{
		root = b;
		return;
	}
	struct node* c = root;

	while (1)
	{
		if (c->i < b->i)
		{
			if (c->right == 0)
			{
				c->right = b;
				root = balance_tree(root);
				return;
			}
			else
			{
				c = c->right;
			}
		}
		else if (c->i > b->i)
		{
			if (c->left == 0)
			{
				c->left = b;
				root = balance_tree(root);
				return;
			}
			else
			{
				c = c->left;
			}
		}
		else if (c->i == b->i)
		{
			return;
		}
	}
}


struct node* inorder(struct node* root)
{
	if (root == 0)return 0;
	inorder(root->left);
	printf("%d ", root->i);
	inorder(root->right);
}

int main()
{
	add(7);
	add(5);
	add(4);
	add(3);
	add(6);
	printf("%d ", root->i);


}
