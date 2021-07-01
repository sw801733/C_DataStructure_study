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

// LL 회전 (오른쪽으로 회전한다)
//     A
//    /                B
//   B        ->      / \
//  /                C   A
// C
//
// ±2를 가지는 A가 부모가 되고 A->left_child인 B가 child가 된다.
// A->left에 B가 가지고 있는 right_child를 대입하고 B의 right_child에 A을 대입한다.
struct node* rotate_RR(struct node* parent)
{
	struct node* child = parent->right ;
	parent->right  = child->left ;
	child->left = parent;
	return child;
}
// RR 회전 (왼쪽으로 회전한다)
//     A
//      \               B
//       B     ->      / \
//        \           A   C
//         C
//
// ±2를 가지는 A가 부모가 되고 A->right_child인 B가 child가 된다.
// A->right에 B가 가지고 있는 left_child를 대입하고 B의 left_child에 A을 대입한다.
struct node* rotate_RL(struct node* parent)
{
	struct node* child = parent->right ;
	parent->right  = rotate_LL(child);
	return rotate_RR(parent);
}
// RL 회전 (오른쪽-왼쪽으로 회전한다)
//     A                A              
//      \                \                C
//       B      ->        C      ->      / \
//      /                  \            A   B
//     C                    B
//
// ±2를 가지는 A가 부모가 되고 A->right_child인 B가 child가 된다.
// A->right_child에 rotate_LL(B)가 반환하는 값을 대입한다. (B,C에 대해 오른쪽 회전)
// rotate_LL(B)호출시 B와 C가 변화가 생기고 다시 rotate_RR(A)을 호출하면 균형트리가 된다. 
struct node* rotate_LR(struct node* parent)
{
	struct node* child = parent->left ;
	parent->left  = rotate_RR(child);
	return rotate_LL(parent);
}
// LR 회전 (왼쪽-오른쪽으로 회전한다)
//     A                 A              
//	  /                 /                  C
//   B         ->      C          ->      / \
//    \               /                  A   B
//     C             B      
//
// ±2를 가지는 A가 부모가 되고 A->left_child인 B가 child가 된다.
// A->left_child에 rotate_RR(B)가 반환하는 값을 대입한다. (B,C에 대해 왼쪽 회전)
// rotate_RR(B)호출시 B와 C가 변화가 생기고 다시 rotate_LL(A)을 호출하면 균형트리가 된다. 

int get_height(struct node* node) //트리의 높이 측정
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

	if (height_diff > 1) // 왼쪽 서브트리의 균형을 맞춘다
	{
		if (get_balance((node)->left ) > 0)
			node = rotate_LL(node);
		else
			node = rotate_LR(node);
	}
	else if (height_diff < -1) // 오른쪽 서브트리의 균형을 맞춘다
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
