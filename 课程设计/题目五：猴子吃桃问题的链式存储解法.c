#include <stdio.h>
#include <stdlib.h>
typedef struct Number *PtrToNode;
struct Number
{
    int number;
    int days;
    PtrToNode Next;
};

PtrToNode Number(PtrToNode T)
{
    PtrToNode TmpCell;
    T -> Next = T;
    TmpCell = (PtrToNode)malloc(sizeof(struct Number));
    TmpCell -> number = T -> number * 2 + 1;
    TmpCell -> days = T->days - 1;
    return TmpCell;
}

int main()
{
    PtrToNode TmpCell;
    TmpCell = (PtrToNode)malloc(sizeof(struct Number));
    TmpCell -> number = 1;
    TmpCell -> days = 10;
    while (TmpCell -> days > 1)
    {
        TmpCell = Number(TmpCell);
    }
    printf("%d",TmpCell -> number);
    return 0;
}