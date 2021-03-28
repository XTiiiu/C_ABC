#include<stdio.h>
#include<string.h>
#include"linkstack.h"
#include"linklist.h"


void main()
{
	int		i = 0;
	int		a[10];
	LinkStack*	stack = NULL;


	stack = LinkStack_Create();
	if (stack == NULL)
	{
		return;
	}

	//添加元素
	for (i = 0;i < 5;i++)
	{
		a[i] = i + 1;
		LinkStack_Push(stack, &a[i]);
	}
	
	//获取栈的基本属性
	printf("length:%d\n", LinkStack_Size(stack));
	printf("top:%d\n", *((int *)LinkStack_Top(stack)));

	while (LinkStack_Size(stack)>0)
	{
		int tmp = *((int *)LinkStack_Pop(stack));
		printf("tmp:%d\n", tmp);
	}

	LinkStack_Destroy(stack);

	system("pause");
	return;
}