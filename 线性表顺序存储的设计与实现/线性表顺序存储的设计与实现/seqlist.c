#include<stdlib.h>
#include<string.h>
#include<stdio.h>
#include"seqlist.h"



//在结构体套一级指针
typedef struct _tag_SeqList
{
	int length;
	int capacity;
	unsigned int *node;    //指针地址大于0
}TSeqList;

SeqList* SeqList_Create(int capacity)
{
	int ret = 0;
	TSeqList *tmp = NULL;
	tmp = (TSeqList *)malloc(sizeof(TSeqList));
	if (tmp == NULL)
	{
		ret = -1;
		printf("func SeqList_Create() err:%d \n", ret);
		return NULL;
	}

	memset(tmp, 0, sizeof(TSeqList));

	//根据capacity的大小分配节点的空间
	tmp->node = (unsigned int *)malloc(sizeof(unsigned int *) * capacity);
	if (tmp->node == NULL)
	{
		ret = -2;
		printf("func SeqList_Create() err:%d \n", ret);
		return NULL;
	}
	tmp->capacity = capacity;
	tmp->length = 0;
}

void SeqList_Destroy(SeqList* list)
{
	TSeqList *tlist = NULL;
	if (list == NULL)
	{
		return ;
	}
	tlist = (TSeqList *)list;
	if (tlist->node != NULL)
	{
		free(tlist->node);
	}
	free(tlist);
	return;
}

//清空链表
void SeqList_Clear(SeqList *list)
{
	TSeqList *tlist = NULL;
	if (list == NULL)
	{
		return;
	}
	tlist = (TSeqList *)list;
	tlist->length = 0;
	return;
}


int SeqList_Length(SeqList *list)
{
	TSeqList * tlist = NULL;
	if (list == NULL)
	{
		return -1;
	}
	tlist = (TSeqList *)list;
	return tlist->length;
}

int SeqList_Capacity(SeqList *list)
{
	TSeqList * tlist = NULL;
	if (list == NULL)
	{
		return -1;
	}
	tlist = (TSeqList *)list;
	return tlist->capacity;
}


int SeqList_Insert(SeqList* list, SeqListNode * node, int pos)
{
	int i = 0, ret = 0;
	TSeqList *tlist = NULL;

	if (list == NULL || node == NULL || pos < 0)
	{
		ret = -1;
		printf("func SeqList_Insert() err:%d \n", ret);
		return ret;
	}
	tlist = (TSeqList *)list;

	//判断链表是不是满了.....
	if (tlist->length >= tlist->capacity)
	{
		ret = -2;
		printf("func SeqList_Insert() err：tlist->length >= tlist->capacity %d \n", ret);
		return ret;
	}

	//容错修正  6个长度 容量20  用户在10的位置插入元素
	if (pos > tlist->length)
	{
		pos = tlist->length;
	}

	//元素后移
	for (i = tlist->length;i > pos;i--)
	{
		tlist->node[i] = tlist->node[i - 1];
	}
	tlist->node[i] = (unsigned int)node;
	tlist->length++;
	return 0;
}

SeqListNode* SeqList_Get(SeqList* list, int pos)
{
	int ret = 0;
	TSeqList *tlist = NULL;
	if (list == NULL || pos < 0)
	{
		ret = -1;
		printf("func SeqList_Get() err %d \n", ret);
	}
	tlist = (TSeqList *)list;
	return tlist->node[pos];
}

SeqListNode* SeqList_Delete(SeqList* list, int pos)
{
	int i = 0;
	SeqListNode *ret = 0;
	TSeqList * tlist = NULL;
	if (list == NULL || pos < 0)
	{
		printf("func SeqList_Delete() err %d \n", ret);
		return NULL;
	}
	tlist = (TSeqList *)list;
	ret = (SeqListNode *)tlist->node[pos];
	for (i = pos;i < tlist->length;i++)
	{
		//tlist->node[i] = tlist->node[i + 1];
		tlist->node[i - 1] = tlist->node[i];
	}
	tlist->length--;
	return ret;
}