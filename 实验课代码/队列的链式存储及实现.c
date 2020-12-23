//�������ƣ����е���ʽ�洢��ʵ��
//���뻷����Dev-c++ 5.11
//��	��:���
//����޸ģ�2020-11-22
#include <stdio.h>
#include <stdlib.h>

#define false 0
#define true 1
#define ERROR 0

typedef int ElementType;
typedef int bool;
typedef struct Node *PtrToNode;
struct Node
{ /*�����еĽ��*/
	ElementType Data;
	PtrToNode Next;
};
typedef PtrToNode Position;

struct QNode
{
	Position Front, Rear; /*���е�ͷ��βָ��*/
};
typedef struct QNode *Queue;

Queue CreatQueue()
{
	Queue Q;
	Q = (Queue)malloc(sizeof(struct QNode));
	Q->Front = Q->Rear = NULL;
	return Q;
}

bool IsEmpty(Queue Q)
{
	return (Q->Front == NULL);
}

bool AddQ(Queue Q, ElementType X)
{
	PtrToNode TmpCell;
	TmpCell = (PtrToNode)malloc(sizeof(struct Node));
	TmpCell->Data = X;
	TmpCell->Next = NULL;
	if (IsEmpty(Q))
		Q->Front = TmpCell;
	else
		Q->Rear->Next = TmpCell;
	Q->Rear = TmpCell;
	return true;
}

ElementType DeleteQ(Queue Q)
{
	Position FrontCell;
	ElementType FrontElem;

	if (IsEmpty(Q))
	{
		printf("���п�");
		return ERROR;
	}
	else
	{
		FrontCell = Q->Front;
		if (Q->Front == Q->Rear) /*������ֻ��һ��Ԫ��*/
			Q->Front = Q->Rear = NULL;
		else
			Q->Front = Q->Front->Next;
		FrontElem = FrontCell->Data;

		free(FrontCell);
		return FrontElem;
	}
}

bool ClearQueue(Queue Q)
{
	Q->Rear=Q->Front = NULL;
	return true;
}

ElementType GetHead(Queue Q)
{
	return Q->Front->Data;
}

int QueueLength(Queue Q)
{
	int sum = 0;
	Position i = Q->Front;
	while (i != NULL)
	{
		i = i->Next;
		sum++;
	}

	return sum;
}

int main()
{
	Queue Q;
	Q = CreatQueue();
	for (int temp = 1; temp < 4; temp++)AddQ(Q,temp);
	printf("����ͷ���Ϊ��%d",GetHead(Q));
	printf("���еĳ���Ϊ��%d\n", QueueLength(Q));
	while (!IsEmpty(Q))
		printf("%d\n", DeleteQ(Q));
	for (int temp = 1; temp < 4; temp++)AddQ(Q,temp);
	if(ClearQueue(Q))printf("������гɹ�");	
	return 0;
}
