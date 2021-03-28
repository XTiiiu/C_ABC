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
		//current�����׽ڵ�ĵ�ַ
		CircleListNode * current = (CircleListNode*)clist;

		//current->next  ����0�Žڵ�ĵ�ַ
		for(i = 0;(i < pos) && current->next != NULL;i++)
		{
			current = current->next;
		}
		node->next = current->next;
		current->next = node;

		//��һ�β���ڵ�
		if (clist->length == 0)
		{
			clist->slider = node;
		}
		clist->length++; 

		//��ͷ�巨  current��Ȼָ��ͷ��
		//ԭ��:��0��  û������
		if (current == (CircleListNode*)clist)
		{
			//�Լ�ָ���Լ�
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
		//CircleListNode* current = (CircleListNode*)(clist->header);  ������ʽ�����
		CircleListNode* current = (CircleListNode*)clist;
		CircleListNode* last = NULL;
		for (int i = 0;i < pos;i++)
		{
			current = current->next;
		}

		//��ɾ����һ��Ԫ�أ�ͷ��㣩
		if (current == (CircleListNode*)clist)
		{
			last = (CircleListNode*)(CircleList_Get(clist, clist->length - 1)); 
		}

		//��Ҫɾ��Ԫ��
		ret = current->next;
		current->next = ret->next;

		clist->length--;


		//�ж������Ƿ�Ϊ��
		if (last != NULL)
		{
			clist->header.next = ret->next;
			last->next = ret->next;
		}

		//��ɾ����Ԫ��Ϊ�α���ָ��Ԫ��
		if (clist->slider == ret)
		{
			clist->slider = ret->next;
		}

		//��ɾ��Ԫ�غ�������Ϊ0
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

		//����node��ѭ�����е�λ��
		for (i = 0;i < clist->length;i++)
		{
			if (current->next == node)
			{
				ret = current->next;
				break;
			}
			current = current->next;
		}


		//���ret���ҵ�  ����iȥɾ��
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