#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"LinkQueue.h"
#include"linklist.h"


typedef struct _tag_LinkQueue_
{
	LinkListNode* node;
	void* item;
}TLinkQueue;

LinkQueue* LinkQueue_Create()
{
	return LinkList_Create();
}

void LinkQueue_Destroy(LinkQueue* queue)
{
	LinkQueue_Clear(queue);
	LinkList_Destroy(queue);
}

void LinkQueue_Clear(LinkQueue* queue)
{
	while (LinkQueue_Length(queue) > 0)
	{
		LinkQueue_Retrieve(queue);
	}
	LinkList_Clear(queue);
}

int LinkQueue_Append(LinkQueue* queue, void* item)
{
	int ret = 0;
	TLinkQueue* tmp = NULL;
	tmp = (TLinkQueue*)malloc(sizeof(TLinkQueue));
	if (tmp == NULL)
	{
		ret = -1;
		printf("TLinkQueue malloc err: %d\n", ret);
		return ret;
	}
	memset(tmp, 0, sizeof(TLinkQueue));
	tmp->item = item;
	ret = LinkList_Insert(queue, (LinkListNode*)tmp, LinkList_Length(tmp));
	if (ret != 0)
	{
		printf("func LinkList_Insert() err:%d\n", ret);
		if (tmp != NULL)
		{
			free(tmp);
		}
		return ret;
	}
	return ret;
}

void* LinkQueue_Retrieve(LinkQueue* queue)
{
	TLinkQueue	*tmp = NULL;
	void		*ret = NULL;
	tmp = (TLinkQueue*)LinkList_Delete(queue, 0);
	if (tmp == NULL)
	{
		printf("func LinkList_Delete() err");
		return;
	}
	//É¾³ýÖ®Ç°»º´æ
	ret = tmp->item;
	if (tmp != NULL)
	{
		free(tmp);
	}
	return ret;
}

void* LinkQueue_Header(LinkQueue* queue)
{
	TLinkQueue	*tmp = NULL;
	void		*ret = NULL;
	tmp = (TLinkQueue*)LinkList_Get(queue, 0);
	if (tmp == NULL)
	{
		printf("func LinkList_Get() err");
		return;
	}
	ret = tmp->item;
	return ret;
}

int LinkQueue_Length(LinkQueue* queue)
{
	return LinkList_Length(queue);
}