#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"seqqueue.h"

void main()
{
	int i = 0;
	int a[10];
	SeqQueue* queue = NULL;
	queue = SeqQueue_Create(10);
	if (queue == NULL)
	{
		printf("func SeqQueue_Create() err");
		return;
	}
	for (i = 0;i < 5;i++)
	{
		a[i] = i + 1;
		SeqQueue_Append(queue, &a[i]);
	}

	printf("Capacity:%d\n", SeqQueue_Capacity(queue));
	printf("Length:%d\n", SeqQueue_Length(queue));
	printf("Header:%d\n", *((int *)SeqQueue_Header(queue)));


	while (SeqQueue_Length(queue) > 0)
	{
		int tmp = *((int *)SeqQueue_Retrieve(queue));
		printf("tmp:%d\n", tmp);
	}

	SeqQueue_Destroy(queue);
	
	system("pause");
	return;
}

/*

SeqQueue* SeqQueue_Create(int capacity);

void SeqQueue_Destroy(SeqQueue* queue);

void SeqQueue_Clear(SeqQueue* queue);

int SeqQueue_Append(SeqQueue* queue, void* item);

void* SeqQueue_Retrieve(SeqQueue* queue);

void* SeqQueue_Header(SeqQueue* queue);

int SeqQueue_Length(SeqQueue* queue);

int SeqQueue_Capacity(SeqQueue* queue);

*/
