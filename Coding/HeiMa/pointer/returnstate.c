#include <stdio.h>
int getRemainder(int num1, int num2, int *res);
int main()
{

    int a = 10, b = 3, res = 0;

    int flag = getRemainder(a, b, &res);
    if (!flag)
    {
        printf("获取到的余数为: %d", res);
    }
}

int getRemainder(int num1, int num2, int *res)
{
    if (num2 == 0)
    {
        return 1;
    }

    *res = num1 % num2;

    return 0;
}