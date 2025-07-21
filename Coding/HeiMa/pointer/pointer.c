#include <stdio.h>

int main()
{
    int a = 10;

    int *p = &a;

    printf("%d\n", *p);

    *p = 290;

    printf("%d\n", *p);
    printf("%d\n", a);
}