#include <stdio.h>

void merge(int arr[], int lowerBound, int mid, int upperBound)
{
    int tempArr[upperBound + 1];
    int i = lowerBound;
    int j = mid + 1;
    int k = lowerBound;
    while (i <= mid && j <= upperBound)
    {
        if (arr[i] <= arr[j])
        {
            tempArr[k] = arr[i];
            i++;
        }
        else
        {
            tempArr[k] = arr[j];
            j++;
        }
        k++;
    }
    if (i > mid)
    {
        while (j <= upperBound)
        {
            tempArr[k] = arr[j];
            k++;
            j++;
        }
    }
    else
    {
        while (i <= mid)
        {
            tempArr[k] = arr[i];
            k++;
            i++;
        }
    }

    int it;
    for (it = lowerBound; it <= upperBound; it++)
    {
        arr[it] = tempArr[it];
    }
}

void mergeSort(int arr[], int lowerBound, int upperBound)
{
    if (lowerBound < upperBound)
    {
        int mid = (lowerBound + upperBound) / 2;
        mergeSort(arr, lowerBound, mid);
        mergeSort(arr, mid + 1, upperBound);
        merge(arr, lowerBound, mid, upperBound);
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

    mergeSort(arr, lowerBound, upperBound);
    printf("\nThe sorted array is : \n");
    for (it = 0; it < arraySize; it++)
    {
        printf("%d ", arr[it]);
    }
    printf("\n");

    return 0;
}