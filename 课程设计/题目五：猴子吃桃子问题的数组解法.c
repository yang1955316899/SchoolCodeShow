#include <stdio.h>
int main()
{
    long int Number[100] = {1};
    for (int days = 1; days < 10; days++) Number[days] = Number[days - 1] * 2 + 1;
    printf("%d",Number[9]);
    return 0;
}