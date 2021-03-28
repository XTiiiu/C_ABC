#include<stdio.h>
#include<stdlib.h>


typedef struct BiNode
{
	int data;
	struct BiNode *lchild, *rchild;
}BiNode,*BiTree;

//typedef struct BiNode		BiNode;
//typedef struct BiNode*	BiTree;



//二叉链表示法
void main_01()
{
	BiNode t1, t2, t3, t4, t5;
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
	system("pause");
	return;
}

typedef struct BPNode
{
	int data;
	int parentPosition;  //指向双亲的指针
	char LRTag;  //左右孩子标志域
}BPNode;

typedef struct BPtree
{
	BPNode nodes[100];  //因为节点是分散的，需要把节点存储在数组中
	int num_node;  //节点数目
	int root;  //根节点的位置
}BPtree;

void main()
{
	BPtree tree;
	tree.nodes[0].parentPosition = 10000;

	tree.nodes[1].data = 'A';
	tree.nodes[1].LRTag = 1;
	tree.nodes[1].parentPosition = 0;

	tree.nodes[2].data = 'B';
	tree.nodes[2].LRTag = 2;
	tree.nodes[2].parentPosition = 0;


	system("pause");
	return;
}