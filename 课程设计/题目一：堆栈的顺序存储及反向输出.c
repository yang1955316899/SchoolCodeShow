//程序名称:堆栈的顺序存储及反向输出
//作者:杨建文
//最后修改:2020-12-7

#include<stdio.h>
#include<stdlib.h>
#define false 0
#define true 1
#define ERROR '#'
#define Max 100

typedef char ElementType;
typedef int bool;
typedef int Position;
struct SNode
{
	ElementType *Data;
	Position Top;
	int MaxSize;
};
typedef struct SNode *Stack;
Stack CreateStack(int MaxSize)
{
	Stack S = (Stack)malloc(sizeof(struct SNode));
	S->Data = (ElementType *)malloc(MaxSize * sizeof(ElementType));
	S->Top = -1;
	S->MaxSize = MaxSize;
	return S;
}

bool IsFull(Stack S )
{
	return (S->Top == S->MaxSize-1);
}

bool Push(Stack S, ElementType X )
{
	if ( IsFull(S) )
		{
			printf("堆栈满");
			return false;
		}
	else
		{
			S->Data[++(S->Top)] = X;
			return true;
		}
}

bool IsEmpty( Stack S )
{
	return (S->Top == -1);//判断栈顶是否指向-1
}

ElementType Pop( Stack S )
{
	if( IsEmpty(S) )
		{
			printf("堆栈空");
			return ERROR;
		}
	else
		return (S->Data[(S->Top)--]);
}

int main()
{
	Stack S;
	char letter;
	S = CreateStack(Max);
    while ((letter = getchar()) != '\n')
        if (letter != ' ')
            Push(S, letter);
	while(!IsEmpty(S)) printf("%c ",Pop(S));
	return 0;
}
