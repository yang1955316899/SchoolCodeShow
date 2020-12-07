//程序名称:二叉树的链式存储及实现
//编译环境:Dev-C++ 5.5.3
//作者:杨建文 
//最后修改:2020-11-29
#include <stdio.h>
#include <stdlib.h>

#define NoInfo 0 /*用0表示没有结点*/
#define false 0
#define true 1
#define ERROR 0

typedef int ElementType; /*假设结点数据是整数*/
typedef int bool;

typedef struct TNode *BinTree; /*二叉树类型*/
struct TNode
{                     /*树结点定义*/
    ElementType Data; /*结点数据*/
    BinTree Left;     /*指向左子树*/
    BinTree Right;    /*指向右子树*/
};

typedef struct Node *PtrToNode;
struct Node
{ /*队列中的结点*/
    BinTree Data;
    PtrToNode Next;
};
typedef PtrToNode Position;

struct QNode
{
    Position Front, Rear; /*队列的头、尾指针*/
};
typedef struct QNode *Queue;

Queue CreateQueue()
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

bool AddQ(Queue Q, BinTree X)
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

BinTree DeleteQ(Queue Q)
{
    Position FrontCell;
    BinTree FrontElem;
    if (IsEmpty(Q))
    {
        printf("队列空");
        return ERROR;
    }
    else
    {
        FrontCell = Q->Front;
        if (Q->Front == Q->Rear)       /*若队列只有一个元紊*/
            Q->Front = Q->Rear = NULL; /*删除后队列置为空*/
        else
            Q->Front = Q->Front->Next;
        FrontElem = FrontCell->Data;
        free(FrontCell); /*释放被删除结点空间*/
        return FrontElem;
    }
}

BinTree CreatBinTree()
{
    ElementType Data;
    BinTree BT, T;
    Queue Q = CreateQueue(); /*创建空队列*/
    /*建立第1个结点,即根结点*/
    scanf("%d", &Data);
    if (Data != NoInfo)
    {
        /*分配根结点单元,并将结点地址入队*/
        BT = (BinTree)malloc(sizeof(struct TNode));
        BT->Data = Data;
        BT->Left = BT->Right = NULL;
        AddQ(Q, BT);
    }
    else
        return NULL; /*若第1个数据就是0,返回空树*/
    while (!IsEmpty(Q))
    {
        T = DeleteQ(Q);     /*从队列中取出一结点地址*/
        scanf("%d", &Data); /*读入T的左孩子*/
        if (Data == NoInfo)
            T->Left = NULL;
        else
        { /*分配新结点,作为出队结点左孩子;新结点入队*/
            T->Left = (BinTree)malloc(sizeof(struct TNode));
            T->Left->Data = Data;
            T->Left->Left = T->Left->Right = NULL;
            AddQ(Q, T->Left);
        }
        scanf("%d", &Data); /*读入T的右孩子*/
        if (Data == NoInfo)
            T->Right = NULL;
        else
        { /*分配新结点,作为出队结点右孩子;新结点入队*/
            T->Right = (BinTree)malloc(sizeof(struct TNode));
            T->Right->Data = Data;
            T->Right->Left = T->Right->Right = NULL;
            AddQ(Q, T->Right);
        }
    } /*结束whiLe */
    return BT;
}

void InorderTraversal(BinTree BT)
{
    if (BT)
    {
        InorderTraversal(BT->Left);
        /*此处假设对BT结点的访问就是打印数据*/
        printf("%d ", BT->Data); /*假设数据为整型*/
        InorderTraversal(BT->Right);
    }
}

void PreorderTraversal(BinTree BT)
{
    if (BT)
    {
        printf("%d ", BT->Data);
        PreorderTraversal(BT->Left);
        PreorderTraversal(BT->Right);
    }
}

void PostorderTraversal(BinTree BT)
{
    if (BT)
    {
        PostorderTraversal(BT->Left);
        PostorderTraversal(BT->Right);
        printf("%d ", BT->Data);
    }
}
void PreorderPrintLeaves(BinTree BT)
{
    if (BT)
    {
        PreorderPrintLeaves(BT->Left);
        PreorderPrintLeaves(BT->Right);
        if (BT->Left == NULL&& BT->Right == NULL)
            printf("%d ", BT->Data);
    } 
}
int GetHight(BinTree BT)
{
    int HL,HR,MaxH;
    if (BT)
    {
        HL = GetHight(BT->Left);
        HR = GetHight(BT->Right);
        MaxH = HL>HR?HL:HR;
        return (MaxH +1);
    }
    else return 0;
}
int main()
{
    BinTree T;
    printf("Create binary tree: ");
    T = CreatBinTree();
    printf("PreorderTraversal: \n");
    PreorderTraversal(T);
    printf("\nInorder traversal: \n");
    InorderTraversal(T);
    printf("\nPostorder traversal : \n");
    PostorderTraversal(T);
    printf("\nPreorderPrintLeaves:\n");
    PreorderPrintLeaves(T);
    printf("\nGetHight:%d",GetHight(T));
    return 0;
}
