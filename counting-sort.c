#include <stdio.h>

int upperRange(int arr[], int arraySize)
{
    int max = arr[0];
    int it;
    for (it = 1; it < arraySize; it++)
    {
        if (arr[it] > max)
        {
            max = arr[it];
        }
    }
    return max;
}

void countingSort(int arr[], int arraySize, int max)
{
    int it;
    int count[max + 1];
    int tempArr[arraySize];
    for (it = 0; it <= max; it++)
    {
        count[it] = 0;
    }

    for (it = 0; it < arraySize; it++)
    {
        count[arr[it]]++;
    }

    for (it = 1; it <= max; it++)
    {
        count[it] += count[it - 1];
    }

    for (it = arraySize - 1; it >= 0; it--)
    {
        int temp = arr[it];
        count[temp]--;
        tempArr[count[temp]] = temp;
    }

    for (it = 0; it < arraySize; it++)
    {
        arr[it] = tempArr[it];
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

    int max = upperRange(arr, arraySize);

    countingSort(arr, arraySize, max);

    printf("The sorted array is : \n");
    for (it = 0; it < arraySize; it++)
    {
        printf("%d ", arr[it]);
    }
    printf("\n");

    return 0;
}