#include <stdio.h>

void bubbleSort(int arr[], int arraySize)
{
    int i, j;
    for (i = 0; i < arraySize - 1; i++)
    {
        for (j = i + 1; j < arraySize; j++)
        {
            if (arr[j] < arr[i])
            {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
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

    bubbleSort(arr, arraySize);

    printf("The sorted array is : \n");
    for (it = 0; it < arraySize; it++)
    {
        printf("%d ", arr[it]);
    }
    printf("\n");

    return 0;
}