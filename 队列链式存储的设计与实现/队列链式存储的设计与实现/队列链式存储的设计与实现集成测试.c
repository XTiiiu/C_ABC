#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"LinkQueue.h"



void main()
{
	int i = 0;
	int a[10];
	LinkQueue* queue = NULL;
	queue = LinkQueue_Create();

	for (i = 0;i < 5;i++)
	{
		a[i] = i + 1;
		LinkQueue_Append(queue, &a[i]);
	}

	printf("LinkQueue_Header:%d\n", *((int *)LinkQueue_Header(queue)));
	printf("LinkQueue_Length:%d\n", LinkQueue_Length(queue));

	while (LinkQueue_Length(queue) > 0)
	{
		int tmp = *((int *)LinkQueue_Retrieve(queue));
		printf("tmp:%d\n", tmp);
	}

	LinkQueue_Destroy(queue);
	
	system("pause");
	return;
}