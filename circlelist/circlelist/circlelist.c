#include"stdio.h"
#include<malloc.h>
#include"circlelist.h"


typedef struct _tag_CircleList
{
	CircleListNode header;
	CircleListNode* slider;
	int length;
}TCircleList;




CircleList* CircleList_Create()
{
	TCircleList* ret = (TCircleList*)malloc(sizeof(TCircleList));
	if (ret == NULL)
	{
		return NULL;
	}
	ret->length = 0;
	ret->header.next = NULL;
	ret->slider = NULL;
	return ret;
}

void CircleList_Destroy(CircleList* list)
{
	if (list == NULL)
	{
		return;
	}
	free(list);
	return;
}

void CircleList_Clear(CircleList* list)
{
	TCircleList* clist = (TCircleList*)list;
	if (clist == NULL)
	{
		return;
	}
	clist->header.next = NULL;
	clist->slider = NULL;
	clist->length = 0;
	return;
}

int CircleList_Length(CircleList* list)
{
	TCircleList* clist = (TCircleList*)list;
	int ret = -1;
	if (list == NULL)
	{
		return;
	}
	ret = clist->length;
	return ret;
}

int CircleList_Insert(CircleList* list, CircleListNode* node, int pos)
{
	int ret = 1;
	int i = 0;
	TCircleList* clist = (TCircleList*)list;
	if (list == NULL || node == NULL || pos < 0)
	{
		ret = -1;
		return ret;
	}
	if (ret)
	{
		//current链表首节点的地址
		CircleListNode * current = (CircleListNode*)clist;

		//current->next  链表0号节点的地址
		for(i = 0;(i < pos) && current->next != NULL;i++)
		{
			current = current->next;
		}
		node->next = current->next;
		current->next = node;

		//第一次插入节点
		if (clist->length == 0)
		{
			clist->slider = node;
		}
		clist->length++; 

		//若头插法  current仍然指向头部
		//原因:跳0步  没有跳步
		if (current == (CircleListNode*)clist)
		{
			//自己指向自己
			CircleListNode* last = CircleList_Get(clist, clist->length - 1);
			last->next = current->next;
		}
	}

	return 0;
}

CircleList* CircleList_Get(CircleList* list, int pos)
{
	int ret = 0, i = 0;
	TCircleList* clist = (TCircleList*)list;

	if (clist == NULL || pos < 0)
	{
		ret = -1;
		printf("func CircleList_Get() err %d\n", ret);
		return NULL;
	}
	CircleListNode* current = (CircleListNode*)clist;
	CircleListNode* zlist = NULL;
	for (i = 0;i < pos;i++)
	{
		current = current->next;
	}
	zlist = current->next;
	return zlist;
}

CircleList* CircleList_Delete(CircleList* list, int pos)
{
	TCircleList* clist = (TCircleList*)list;
	CircleListNode* ret = NULL;
	if ((clist != NULL) && (pos >= 0) && (clist->length > 0))
	{
		//CircleListNode* current = (CircleListNode*)(clist->header);  与下面式子相等
		CircleListNode* current = (CircleListNode*)clist;
		CircleListNode* last = NULL;
		for (int i = 0;i < pos;i++)
		{
			current = current->next;
		}

		//若删除第一个元素（头结点）
		if (current == (CircleListNode*)clist)
		{
			last = (CircleListNode*)(CircleList_Get(clist, clist->length - 1)); 
		}

		//求要删的元素
		ret = current->next;
		current->next = ret->next;

		clist->length--;


		//判断链表是否为空
		if (last != NULL)
		{
			clist->header.next = ret->next;
			last->next = ret->next;
		}

		//若删除的元素为游标所指的元素
		if (clist->slider == ret)
		{
			clist->slider = ret->next;
		}

		//若删除元素后，链表长度为0
		if (clist->length == 0)
		{
			clist->header.next = NULL;
			clist->slider = NULL;
		}

	}
}

//add

CircleListNode* CircleList_DeleteNode(CircleList* list, CircleListNode* node)
{
	TCircleList*clist = (TCircleList*)list;
	CircleListNode* ret = NULL;
	int i = 0;

	if (clist != NULL)
	{
		CircleListNode* current = (CircleListNode*)clist;

		//查找node在循环表中的位置
		for (i = 0;i < clist->length;i++)
		{
			if (current->next == node)
			{
				ret = current->next;
				break;
			}
			current = current->next;
		}


		//如果ret被找到  根据i去删除
		if (ret != NULL)
		{
			CircleList_Delete(clist, i);
		}
	}
	return ret;
}


CircleListNode* CircleList_Reset(CircleList* list)
{
	TCircleList* clist = (TCircleList*)list;
	CircleListNode* ret = NULL;

	if (clist != NULL)
	{
		clist->slider = clist->header.next;
		ret = clist->slider;
	}
	return ret;
}


CircleListNode* CircleList_Current(CircleList* list)
{
	TCircleList* clist = (TCircleList*)list;
	CircleListNode* ret = NULL;
	if (clist != NULL)
	{
		ret = clist->slider;
	}
	return ret;
}


CircleListNode* CircleList_Next(CircleList* list)
{
	TCircleList*clist = (TCircleList*)list;
	CircleListNode* ret = NULL;
	if (clist != NULL && (clist->slider != NULL))
	{
		ret = clist->slider;
		clist->slider = ret->next;
	}
	return ret;
}