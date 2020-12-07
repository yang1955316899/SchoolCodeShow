//�������ƣ����е���ʽ�洢���������
//��	��:���
//����޸ģ�2020-12-7
#include <stdio.h>
#include <stdlib.h>

#define false 0
#define true 1
#define ERROR 0

typedef char ElementType;
typedef int bool;
typedef struct Node *PtrToNode;
struct Node/*�����еĽ��*/
{ 
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
    Position FrontCell, tem;
    FrontCell = Q->Front;
    if (FrontCell->Next == NULL)
    {
        tem = FrontCell;
        Q->Front = NULL;
        return tem->Data;
    }
    else
    {
        while (FrontCell->Next->Next != NULL)
            FrontCell = FrontCell->Next;
        tem = FrontCell->Next;
        FrontCell->Next = NULL;
        Q->Rear = FrontCell;
        return tem->Data;
    }
}
int main()
{
    Queue Q;
    ElementType letter;
    Q = CreatQueue();
    while ((letter = getchar()) != '\n')
        if (letter != ' ')
            AddQ(Q, letter);
    while (!IsEmpty(Q))
        printf("%c ", DeleteQ(Q));
    return 0;
}
