#include<stdio.h>
#include<stdlib.h>

typedef struct BiNode
{
	int data;
	struct BiNode *lchild, *rchild;
}BiTNode, *BiTree;

//typedef struct BiNode		BiNode;
//typedef struct BiNode*	BiTree;



void preOrder(BiTNode *root)
{
	if (root == NULL)
	{
		return;
	}
	printf("%d\t", root->data);
	preOrder(root->lchild);
	preOrder(root->rchild);
}

void inOrder(BiTNode *root)
{
	if (root == NULL)
	{
		return;
	}
	inOrder(root->lchild);
	printf("%d\t", root->data);
	inOrder(root->rchild);
}

void postOrder(BiTNode *root)
{
	if (root == NULL)
	{
		return;
	}
	postOrder(root->lchild);
	postOrder(root->rchild);
	printf("%d\t", root->data);
}


//二叉链表示法
void main()
{
	BiTNode t1, t2, t3, t4, t5;
	memset(&t1, 0, sizeof(BiTNode));
	memset(&t2, 0, sizeof(BiTNode));
	memset(&t3, 0, sizeof(BiTNode));
	memset(&t4, 0, sizeof(BiTNode));
	memset(&t5, 0, sizeof(BiTNode));
	t1.data = 1;
	t2.data = 2;
	t3.data = 3;
	t4.data = 4;
	t5.data = 5;

	//建立关系
	t1.lchild = &t2;
	t1.rchild = &t3;
	t2.lchild = &t4;
	t3.lchild = &t5;

	postOrder(&t1);
	printf("\n");
	inOrder(&t1);
	printf("\n");
	preOrder(&t1);
	printf("\n");
	system("pause");
	return;
}