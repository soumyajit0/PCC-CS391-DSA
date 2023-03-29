#include <stdio.h>

int partition(int arr[], int lowerBound, int upperBound)
{
    int pivot = arr[lowerBound];
    int start = lowerBound;
    int end = upperBound;
    while (start < end)
    {
        while (arr[start] <= pivot)
        {
            start++;
        }
        while (arr[end] > pivot)
        {
            end--;
        }
        if (start < end)
        {
            int temp = arr[start];
            arr[start] = arr[end];
            arr[end] = temp;
        }
    }
    arr[lowerBound] = arr[end];
    arr[end] = pivot;
    return end;
}

void quickSort(int arr[], int lowerBound, int upperBound)
{
    if (lowerBound < upperBound)
    {
        int loc = partition(arr, lowerBound, upperBound);
        quickSort(arr, lowerBound, loc - 1);
        quickSort(arr, loc + 1, upperBound);
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

    int lowerBound = 0;
    int upperBound = arraySize - 1;
    quickSort(arr, lowerBound, upperBound);

    printf("The sorted array is : \n");
    for (it = 0; it < arraySize; it++)
    {
        printf("%d ", arr[it]);
    }
    printf("\n");

    return 0;
}