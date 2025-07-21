#include <stdio.h>
int main()
{
    int arr1[3] = {1, 2, 3};
    int arr2[5] = {1, 2, 3, 4, 5};
    int arr3[8] = {1, 2, 3, 4, 5, 13, 24, 12};
    int len1 = sizeof(arr1) / sizeof(arr1[0]);
    int len2 = sizeof(arr2) / sizeof(arr2[0]);
    int len3 = sizeof(arr3) / sizeof(arr3[0]);

    int *arr[3] = {arr1, arr2, arr3};
    int lenarr[3] = {len1,
                     len2,
                     len3};

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < lenarr[i]; j++)
        {
            printf("%d", arr[i][j]);
        }
        printf("\n");
    }

    return 0;
}