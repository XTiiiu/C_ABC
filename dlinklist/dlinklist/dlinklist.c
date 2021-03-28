#include<stdio.h>
#include<malloc.h>
#include"dlinklist.h"

typedef struct _tag_DLinkList
{
	DLinkListNode header;
	DLinkListNode* slider;
	int length;
}TDLinkList;



DLinkList* DLinkList_Create()
{
	int ret = 0;
	TDLinkList* tlist = (TDLinkList*)malloc(sizeof(TDLinkList));
	if (tlist == NULL)
	{
		int ret = -1;
		printf("func DLinkList_Create() err %d\n", ret);
	}
	tlist->header.next = NULL;
	tlist->header.pre = NULL;
	tlist->slider = NULL;
	tlist->length = 0;
	return tlist;
}

void DLinkList_Destroy(DLinkList* list)
{
	if (list == NULL)
	{
		return;
	}
	free(list);
	return;
}

void DLinkList_Clear(DLinkList* list)
{
	if (list != NULL)
	{
		TDLinkList* tlist = (TDLinkList*)list;
		tlist->header.next = NULL;
		tlist->header.pre = NULL;
		tlist->length = 0;
		tlist->slider = NULL;
	}
	return;
}

int DLinkList_Length(DLinkList* list)
{
	TDLinkList* tlist = (TDLinkList*)list;
	int ret = 0;
	if (list == NULL)
	{
		return -1;
	}
	ret = tlist->length;
	return ret;
}

int DLinkList_Insert(DLinkList* list, DLinkListNode* node, int pos)
{
	int i = 0, ret = 0;
	TDLinkList* tlist = (TDLinkList*)list;
	if (list == NULL || node == NULL || pos < 0)
	{
		return -1;
	}

	{
		DLinkListNode* current = (DLinkListNode*)tlist;
		DLinkListNode* next = NULL;    //需要添加一个next指针

		for (i = 0;i < pos&&current->next != NULL;i++)
		{
			current = current->next;
		}

		next = current->next;


		current->next = node;
		node->next = next;

		if (next != NULL)   //当插入第一个元素的时候需要特殊处理 
		{
			next->pre = node;
		}
		node->pre = current;

		if (tlist->length == 0)
		{
			tlist->slider = node;
		}

		if (current == (DLinkListNode*)tlist)  //当插入第一个元素时候需要特殊处理
		{
			node->pre = NULL;
		}

		tlist->length++;
	}
	return 0;
}

DLinkListNode* DLinkList_Get(DLinkList* list, int pos)
{
	TDLinkList* tlist = (TDLinkList*)list;
	DLinkListNode* ret = NULL;
	int i = 0;
	if (list != NULL && (pos >= 0) && (pos < tlist->length))
	{
		DLinkListNode* current = (DLinkListNode*)tlist;
		for (i = 0;i < pos;i++)
		{
			current = current->next;
		}
		ret = current->next;
	}
	return ret;
}

DLinkListNode* DLinkList_Delete(DLinkList* list, int pos)
{
	TDLinkList* tlist = (TDLinkList*)list;
	DLinkListNode* ret = NULL;
	int i = 0;
	if (tlist == NULL || pos < 0)
	{
		return NULL;
	}
	{
		DLinkListNode* current = (DLinkListNode*)tlist;
		DLinkListNode* next = NULL;

		for (i = 0;i < pos;i++)
		{
			current = current->next;
		}
		ret = current->next;
		next = ret->next;


		current->next = next;

		if (next != NULL)   //判定是不是最后一个元素
		{
			next->pre = current;
			if (current == (DLinkListNode*)tlist)   //如果是在0号节点删除元素
			{
				next->pre = NULL;
			}
		}
		if (tlist->slider == ret)  //游标的处理
		{
			tlist->slider = next;
		}

		tlist->length--;
	}

	return ret;

}

//add

DLinkListNode* DLinkList_DeleteNode(DLinkList* list, DLinkListNode* node)
{
	int i = 0;
	TDLinkList* tlist = (TDLinkList*)list;
	DLinkListNode* ret = NULL;
	DLinkListNode* next = NULL;
	if (list != NULL && node != NULL)
	{
		DLinkListNode* current = (DLinkListNode*)tlist;
		for (i = 0;i < tlist->length;i++)
		{
			if (current->next == node)
			{
				ret = current->next;
				break;
			}
			current = current->next;
		}
		if (ret != NULL)
		{
			DLinkList_Delete(list, i);
		}
	}
	return ret;
}

DLinkListNode* DLinkList_Reset(DLinkList* list)
{
	TDLinkList* tlist = (TDLinkList*)list;
	DLinkListNode* ret = NULL;
	if (list != NULL)
	{
		tlist->slider = tlist->header.next;
		ret = tlist->slider;
	}
	return ret;
}

DLinkListNode* DLinkList_Current(DLinkList* list)
{
	TDLinkList* tlist = (TDLinkList*)list;
	DLinkListNode* ret = NULL;
	if (list != NULL)
	{
		ret = tlist->slider;
	}
	return ret;
}

DLinkListNode* DLinkList_Next(DLinkList* list)
{
	TDLinkList* tlist = (TDLinkList*)list;
	DLinkListNode* ret = NULL;
	if (list != NULL)
	{
		ret = tlist->slider;
		tlist->slider = ret->next;
	}
	return ret;
}

DLinkListNode* DLinkList_Pre(DLinkList* list)
{
	TDLinkList* tlist = (TDLinkList*)list;
	DLinkListNode* ret = NULL;
	if (tlist != NULL)
	{
		ret = tlist->slider;
		tlist->slider = ret->pre;
	}
	return ret;
}