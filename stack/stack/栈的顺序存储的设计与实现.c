#include<stdlib.h>
#include<string.h>
#include<stdio.h>
#include"seqstack.h"


void main()
{
	int		i = 0;
	int		a[10];
	SeqStack*	stack = NULL;


	stack = SeqStack_Create(10);

	if (stack == NULL)
	{
		return;
	}


	for (i = 0;i < 5;i++)
	{
		a[i] = i + 1;
		SeqStack_Push(stack, &a[i]);
	}


	printf("Capacity:%d\n", SeqStack_Capacity(stack));
	printf("Length:%d\n", SeqStack_Size(stack));
	printf("top:%d\n",*((int *) SeqStack_Top(stack)));


	while (SeqStack_Size(stack) > 0)
	{
		int tmp = *((int *)SeqStack_Pop(stack));
		printf("tmp:%d\n", tmp);
	}

	printf("\n");

	system("pause");
	return;
}