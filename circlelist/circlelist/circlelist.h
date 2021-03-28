#ifndef _MYLINKLIST_H_
#define _MYLINKLIST_H_

typedef void CircleList;

typedef struct _tag_CircleListNode
{
	struct _tag_CircleListNode* next;
}CircleListNode;

CircleList* CircleList_Create();

void CircleList_Destroy(CircleList* list);

void CiecleList_Clear(CircleList* list);

int CircleList_Length(CircleList* list);

int CircleList_Insert(CircleList* list, CircleListNode* node, int pos);

CircleList* CircleList_Get(CircleList* list, int pos);

CircleList* CircleList_Delete(CircleList* list, int pos);

//add

CircleListNode* CircleList_DeleteNode(CircleList* list, CircleListNode* node);

CircleListNode* CircleList_Reset(CircleList* lsit);

CircleListNode* CircleList_Current(CircleList* list);

CircleListNode* CircleList_Next(CircleList* list);

#endif
