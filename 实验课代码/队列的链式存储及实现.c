//程序名称：队列的链式存储及实现
//编译环境：Dev-c++ 5.11
//作	者:杨建文
//最后修改：2020-11-22
#include <stdio.h>
#include <stdlib.h>

#define false 0
#define true 1
#define ERROR 0

typedef int ElementType;
typedef int bool;
typedef struct Node *PtrToNode;
struct Node
{ /*队列中的结点*/
	ElementType Data;
	PtrToNode Next;
};
typedef PtrToNode Position;

struct QNode
{
	Position Front, Rear; /*队列的头、尾指针*/
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
		printf("队列空");
		return ERROR;
	}
	else
	{
		FrontCell = Q->Front;
		if (Q->Front == Q->Rear) /*若队列只有一个元素*/
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
	printf("队列头结点为：%d",GetHead(Q));
	printf("队列的长度为：%d\n", QueueLength(Q));
	while (!IsEmpty(Q))
		printf("%d\n", DeleteQ(Q));
	for (int temp = 1; temp < 4; temp++)AddQ(Q,temp);
	if(ClearQueue(Q))printf("清除队列成功");	
	return 0;
}
