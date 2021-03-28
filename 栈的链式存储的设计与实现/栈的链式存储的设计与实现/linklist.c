#include<stdlib.h>
#include<string.h>
#include<stdio.h>
#include"linklist.h"


//�����������߼������͸���ָ�����֮��Ĺ�ϵ


typedef struct _tag_LinkList
{
	LinkListNode header;
	int length;
}TLinkList;


LinkList* LinkList_Create()
{
	TLinkList * ret = NULL;
	ret = (TLinkList *)malloc(sizeof(TLinkList));
	memset(ret, 0, sizeof(TLinkList));
	ret->length = 0;
	ret->header.next = NULL;
	return ret;
}

void LinkList_Destroy(LinkList* list)
{
	if (list != NULL)
	{
		free(list);
		list = NULL;
	}
	return;
}


//������ָ�����ʼ��״̬
void LinkList_Clear(LinkList* list)
{
	TLinkList* tLink;
	if (list == NULL)
	{
		return;
	}
	tLink = (TLinkList *)list;
	tLink->length = 0;
	tLink->header.next = NULL;
	return;
}

int LinkList_Length(LinkList* list)
{
	TLinkList* tLink;
	if (list == NULL)   
	{
		return -1;
	}
	tLink = (TLinkList *)list;
	return tLink->length;
}

int LinkList_Insert(LinkList* list, LinkListNode* node, int pos)
{
	TLinkList* tLink = NULL;
	LinkListNode *current = NULL;
	int ret;
	if (list == NULL || pos < 0 || node == NULL)
	{
		ret = 0;
		printf("func LinkList_Insert err %d \n", ret);
		return ret;
	}
	tLink = (TLinkList *)list;
	current = &(tLink->header);
	for (int i = 0;i < pos && (current->next != NULL);i++)
	{
		current = current->next;
	}
	//��node���Ӻ�������;
	node->next = current->next;
	//��ǰ�����������node;
	current->next = node;
	tLink->length++;
	return 0;
}

LinkList* LinkList_Get(LinkList* list, int pos)
{
	TLinkList* tLink;
	LinkListNode *current = NULL;
	int ret;
	if (list == NULL || pos < 0 )
	{
		ret = 0;
		printf("func LinkList_Insert err %d \n", ret);
		return NULL;
	}
	tLink = (TLinkList *)list;
	current = &(tLink->header);  //�ø���ָ�����ָ�������ͷ��

	for (int i = 0;i < pos && (current->next != NULL);i++)
	{
		current = current->next;
	}
	return current->next;
}

LinkList* LinkList_Delete(LinkList* list, int pos)
{
	TLinkList* tLink;
	LinkListNode *current = NULL;
	LinkListNode *ret = NULL;
	if (list == NULL || pos < 0)
	{
		printf("func LinkList_Insert err %d \n", ret);
		return NULL;
	}
	tLink = (TLinkList *)list;
	current = &(tLink->header);  //�ø���ָ�����ָ�������ͷ��

	for (int i = 0;i < pos && (current->next != NULL);i++)
	{
		current = current->next;
	}
	//���汻ɾ���ڵ��λ��
	ret = current->next;
	current->next = ret->next;
	tLink->length--;
	return ret;
}