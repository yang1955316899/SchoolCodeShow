#include <stdio.h>
int fun(int number,int days)
{
	if(days != 1)
		return fun(number * 2 + 1,days - 1);
	else
		return number;
}
int main()
{
	printf("%d",fun(1,10));
}
