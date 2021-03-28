#include<stdio.h>
#include<string.h>
#include"linkstack.h"
#include"linklist.h"


typedef void LinkStack;
typedef struct _tag_LinkStack
{
	LinkListNode* node;
	void* item;
}TLinkStackNode;

LinkStack* LinkStack_Create()
{
	return LinkList_Create();
}

void LinkStack_Destroy(LinkStack* stack)
{
	LinkStack_Clear(stack);
	LinkList_Destroy(stack);
	return;
}


//清空栈的时候涉及到了栈的生命周期管理
//所有入栈的节点都是malloc
//若要清空栈 把栈中元素弹出，并释放节点内存
void LinkStack_Clear(LinkStack* stack)
{
	if (stack == NULL)
	{
		return;
	}
	while (LinkStack_Size(stack) > 0)
	{
		LinkStack_Pop(stack);
	}
}

int LinkStack_Push(LinkStack* stack, void* item)
{
	TLinkStackNode* tmp = NULL;
	tmp = (TLinkStackNode*)malloc(sizeof(TLinkStackNode));
	if (tmp == NULL)
	{
		return -1;
	}
	memset(tmp, 0, sizeof(TLinkStackNode));
	tmp->item = item;
	int ret = LinkList_Insert(stack, (LinkListNode*)tmp, 0);
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

//从栈中弹出元素相当于从线性表的头部删除元素		
//把线性表的业务节点转化为栈的业务节点
void* LinkStack_Pop(LinkStack* stack)
{
	void* item = NULL;  //栈的业务节点
	TLinkStackNode* tmp = NULL;
	tmp = (TLinkStackNode *)LinkList_Delete(stack, 0);
	if (tmp == NULL)
	{
		return NULL;
	}
	item = tmp->item;
	//因为LinkList_Insert的时候分配了内存  所以LinkList_Delete释放内存
	free(tmp);
	return item;
	return;
}

void* LinkStack_Top(LinkStack* stack)
{
	TLinkStackNode* tmp = NULL;
	tmp = (TLinkStackNode*)LinkList_Get(stack, 0);
	if (tmp == NULL)
	{
		return NULL;
	}
	return tmp->item;
}

int LinkStack_Size(LinkStack* stack)
{
	return LinkList_Length(stack);
}