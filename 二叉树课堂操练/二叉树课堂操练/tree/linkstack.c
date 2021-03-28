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


//���ջ��ʱ���漰����ջ���������ڹ���
//������ջ�Ľڵ㶼��malloc
//��Ҫ���ջ ��ջ��Ԫ�ص��������ͷŽڵ��ڴ�
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

//��ջ�е���Ԫ���൱�ڴ����Ա��ͷ��ɾ��Ԫ��		
//�����Ա��ҵ��ڵ�ת��Ϊջ��ҵ��ڵ�
void* LinkStack_Pop(LinkStack* stack)
{
	void* item = NULL;  //ջ��ҵ��ڵ�
	TLinkStackNode* tmp = NULL;
	tmp = (TLinkStackNode *)LinkList_Delete(stack, 0);
	if (tmp == NULL)
	{
		return NULL;
	}
	item = tmp->item;
	//��ΪLinkList_Insert��ʱ��������ڴ�  ����LinkList_Delete�ͷ��ڴ�
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