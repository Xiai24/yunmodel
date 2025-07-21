#include <stdio.h>
void get(int arr[], int len, int *max, int *min);

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 2, 52};
    int len = sizeof(arr) / sizeof(int); // sizeof(arr) / sizeof(arr[0])也可以这样

    int max = arr[0];
    int min = arr[0];

    get(arr, len, &max, &min);

    printf("数组的最大值为：%d\n", max);
    printf("数组的最小值为：%d\n", min);
    return 0;
}

void get(int arr[], int len, int *max, int *min)
{

    *max = arr[0];
    *min = arr[0];

    for (int i = 1; i < len; i++)
    {
        if (arr[i] > *max)
        {
            *max = arr[i];
        }
    }

    for (int i = 1; i < len; i++)
    {
        if (arr[i] < *min)
        {
            *min = arr[i];
        }
    }
}