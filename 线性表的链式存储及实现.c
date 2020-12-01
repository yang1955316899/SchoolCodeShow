//程序名称:线性表的链式存储及实现
//编译环境:Dev-C++ 5.5.3
//作者：杨建文
//最后修改:2020-10-18
#include <stdio.h>
#include <stdlib.h>

#define ERROR NULL
#define MAXSIZE 100
#define true 1
#define false 0

typedef int ElementType;
typedef int bool;
typedef struct LNode *PtrToLNode;
struct LNode {
	ElementType Data;
	PtrToLNode Next;
};
typedef PtrToLNode Position;
typedef PtrToLNode List;
List MakeEmpty()
{
	List L;
	L = (List)malloc(sizeof(struct LNode));
	L->Next=NULL;
	return L;
}
List Insert(List L,ElementType X,int i)
{
	Position tmp,pre;
	int cnt=0;
	tmp=(Position)malloc(sizeof(struct LNode));
	tmp->Data=X;
	pre=L;
	while(pre&&cnt<i-1) {
		pre=pre->Next;
		cnt++;
	}
	if(pre==NULL||cnt!=i-1) {
		printf("插入位置参数错误\n");
		free(tmp);
		return ERROR;
	}else {
		tmp->Next=pre->Next;
		pre->Next=tmp;
		return L;
	}
}
bool Delete(List L,int i)
{
	Position tmp,pre;
	int cnt=0;
	pre=L;
	while(pre&&cnt<i-1) {
		pre=pre->Next;
		cnt++;
	}
	if(pre==NULL||cnt!=i-1||pre->Next==NULL) {
		printf("删除位置参数错误\n");
		return false;
	}else {
		tmp=pre->Next;
		pre->Next=tmp->Next;
		free(tmp);
		return true;
	}
}
bool Print(List L)
{
	PtrToLNode p;
	p=L->Next;
	while(p){
		printf("%d\t",p->Data);
		p=p->Next;
	}
	return true;
}
int Length(List L)
{
	PtrToLNode p;
	int time = 0;
	p=L->Next;
	while(p){
		time++;
		p=p->Next;
	}
	printf("%d\t",time);
	return time;
}
bool Find(List L,ElementType X)
{
	PtrToLNode p;
	p=L->Next;
	while(p && p->Data == X){
		printf("%d\t",p->Data == X);
		p=p->Next;
	}
	printf("Find Ture!\t");
	return true;
}
bool FindKth(List L,int pos)
{
	PtrToLNode p;
	p=L->Next;
	while(p && pos){
		if(p->Next == NULL && pos > 1)
			return false;
		pos--;
		p=p->Next;
	}
	printf("FindKth Ture!\t");
	return true;
}
int main()
{
	List L;
	int i;
	L=MakeEmpty();
	for(i=1;i<=10;i++)
		Insert(L,i,i);
	Delete(L,3);
	Print(L);
	Length(L);
	Find(L,4);
	FindKth(L,3);
	return 0;
}
