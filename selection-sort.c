#include <stdio.h>

void selectionSort(int arr[], int arraySize)
{
    int i, j;
    for (i = 0; i < arraySize - 1; i++)
    {
        int min = i;
        for (j = i + 1; j < arraySize; j++)
        {
            if (arr[j] < arr[min])
            {
                min = j;
            }
        }
        if (min != i)
        {
            int temp = arr[i];
            arr[i] = arr[min];
            arr[min] = temp;
        }
    }
}

int main()
{
    int arraySize, it;
    printf("Enter the size of the array : ");
    scanf("%d", &arraySize);
    int arr[arraySize];
    for (it = 0; it < arraySize; it++)
    {
        printf("Enter the %d element of the array : ", it + 1);
        scanf("%d", &arr[it]);
    }

    selectionSort(arr, arraySize);

    printf("The sorted array is : \n");
    for (it = 0; it < arraySize; it++)
    {
        printf("%d ", arr[it]);
    }
    printf("\n");

    return 0;
}