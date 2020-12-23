//��������:���Ա��˳��洢��ʵ��
//���뻷��:Dev-C++ 5.5.3
//����:���
//����޸�:2020-9-26
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
		return ERROR; /*���û�ҵ�,���ش�����Ϣ��*/
	else
		return i; /*�ҵ��󷵻ص��Ǵ洢λ��*/
}
bool Insert(List L, ElementType x, int i)
{
	Position j;
	if (L->Last == MAXSIZE - 1)
	{
		/*��ռ�����,���ܲ���*/
		printf("����");
		return false;
	}
	if (i < 1 || i > L->Last + 2)
	{
		printf("λ�򲻺Ϸ�");
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
	/*��L��ɾ��ָ��λ��i��Ԫ��,��Ԫ�������±�Ϊi-1 */
	Position j;
	if (i < 1 || i > L->Last + 1)
		printf("λ��%d������Ԫ��", i);
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
	printf("\n���Ա���Ϊ��%d\t", Length(L));
	printf("λ��Ϊ3��ֵΪ��%d", FindKth(L, 3));
	return 0;
}
