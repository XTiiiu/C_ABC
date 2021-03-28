#ifndef __MY_SEQLIST_H__
#define __MY_SEQLIST_H__

typedef void SeqStack;
typedef void SeqStackNode;

SeqStack* SeqStack_Create(int capacity);

void SeqStack_Destroy(SeqStack* stack);

void SeqStack_Clear(SeqStack* stack);

int SeqStack_Push(SeqStack* stack, void* item);

void* SeqStack_Pop(SeqStack* stack);

void* SeqStack_Top(SeqStack* stack);

int  SeqStack_Size(SeqStack* stack);

int SeqStack_Capacity(SeqStack* stack);

#endif

