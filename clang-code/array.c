#include <stdio.h>
#define SIZE 10

int main()
{
    int arr[SIZE] = {};
    for (int i = 0; i < SIZE; i++)
    {
        printf("\narr[%d] = ", i);
        scanf("%d", &arr[i]);
    }
    printf("\narr[%d] = ", SIZE);
    for (int i = 0; i < SIZE; i++)
    {
        printf(i == 0 ? "{ " : " ");
        printf("%d", arr[i]);
        printf(i == SIZE - 1 ? " }\n" : ",");
    }
    return 0;
}