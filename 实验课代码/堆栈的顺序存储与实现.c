//程序名称:堆栈的顺序存储及实现
//编译环境:Dev-C++ 5.5.3
//作者:杨建文
//最后修改:2020-11-1

#include<stdio.h>
#include<stdlib.h>
#define false 0
#define true 1
#define ERROR '#'

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

ElementType GetTop(Stack S)
{
	if(IsEmpty(S))
	{
		printf("堆栈空");
		return ERROR;
	}
	else
		return(S->Data[S->Top]);
} 

int StackLength(Stack S)
{
	return(S->Top + 1);
}
int main()
{
	Stack S;
	char x;
	S=CreateStack(10);
	Push(S,'1');
	Push(S,'2');
	Push(S,'3');
	printf("栈顶元素为：%c\n",GetTop(S));
	printf("栈长为：%d\n",StackLength(S));
	while(!IsEmpty(S))
		{
			x=Pop(S);
			printf("%c\n",x);
		}
	return 0;
}
