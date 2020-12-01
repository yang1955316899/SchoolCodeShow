//程序名称:线性表的顺序存储及实现
//编译环境:Dev-C++ 5.5.3
//作者:杨建文
//最后修改:2020-9-26
#include <stdio.h>
#include <stdlib.h>
#define ERROR -1
#define MAXSIZE 100
#define true 1
#define false 0

typedef int bool;
typedef int ElementType;
typedef int Position;
typedef struct LNode *List;
struct LNode
{
	ElementType Data[MAXSIZE];
	Position Last;
};

List MakeEmpty()
{
	List L;
	L = (List)malloc(sizeof(struct LNode));
	L->Last = -1;
	return L;
}
Position Find(List L, ElementType x)
{
	Position i = 0;
	while (i <= L->Last && L->Data[i] != x)
		i++;
	if (i > L->Last)
		return ERROR; /*如果没找到,返回错误信息、*/
	else
		return i; /*找到后返回的是存储位置*/
}
bool Insert(List L, ElementType x, int i)
{
	Position j;
	if (L->Last == MAXSIZE - 1)
	{
		/*表空间已满,不能插入*/
		printf("表满");
		return false;
	}
	if (i < 1 || i > L->Last + 2)
	{
		printf("位序不合法");
		return false;
	}
	for (j = L->Last; j >= i - 1; j--)
		L->Data[j + 1] = L->Data[j];
	L->Data[i - 1] = x;
	L->Last++;
	return true;
}
bool Delete(List L, int i)
{
	/*从L中删除指定位序i的元素,该元素数组下标为i-1 */
	Position j;
	if (i < 1 || i > L->Last + 1)
		printf("位序%d不存在元素", i);
	return false;
	for (j = i; j <= L->Last; j++)
		L->Data[j - 1] = L->Data[j];
	L->Last--;
	return true;
}
bool Print(List L)
{
	int i;
	for (i = 0; i <= L->Last; i++)
		printf("%d\t", L->Data[i]);
	return true;
}
int FindKth(List L, ElementType Kth)
{
	return (L->Data[Kth - 1]);
}
Position Length(List L)
{
	return L->Last + 1;
}
int main()
{
	List L;
	int i;
	L = MakeEmpty();
	for (i = 1; i <= 10; i++)
		Insert(L, i, i);

	Delete(L, 3);
	Insert(L, 100, 10);
	Print(L);
	printf("\n线性表长度为：%d\t", Length(L));
	printf("位置为3的值为：%d", FindKth(L, 3));
	return 0;
}
