#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"linkstack.h"


typedef struct BiNode
{
	int data;
	struct BiNode *lchild, *rchild;
}BiTNode, *BiTree;


BiTNode* goLeft(BiTNode *T,LinkStack *s)
{
	if (T == NULL)
	{
		return NULL;
	}
	while (T->lchild != NULL)
	{
		LinkStack_Push(s, (void *)T);
		T = T->lchild;
	}
	return T;
}

void inOrder(BiTNode *T)
{
	BiTNode *t = NULL;
	LinkStack *s = LinkStack_Create();

	t = goLeft(T, s);

	while (t)
	{
		printf("%d", t->data);

		//如果有右子树  重复步骤1
		if (t->rchild != NULL)
		{
			t = goLeft(t->rchild, s);
		}
		else if (LinkStack_Size(s) > 0)
		{
			t = (BiTNode *)LinkStack_Pop(s);
		}
		else
		{
			t = NULL;
		}
	}
}

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

	inOrder(&t1);

	system("pause");
	return;
}