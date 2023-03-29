#include <stdio.h>
#include <stdbool.h>

bool interpolationSearch(int arr[], int arraySize, int searchElement)
{
    int lowerBound = 0;
    int upperBound = arraySize - 1;
    while (lowerBound <= upperBound && arr[lowerBound] < searchElement && arr[upperBound] > searchElement)
    {
        int pos = lowerBound + (((double)(upperBound - lowerBound) /
                                 (arr[upperBound] - arr[lowerBound])) *
                                (searchElement - arr[lowerBound]));
        int mid = (lowerBound + upperBound) / 2;
        if (arr[pos] == searchElement)
        {
            return true;
        }
        else if (searchElement < arr[pos])
        {
            upperBound = pos - 1;
        }
        else
        {
            lowerBound = pos + 1;
        }
    }
    return false;
}

int main()
{
    int arraySize, it;
    printf("Enter the size of the array : ");
    scanf("%d", &arraySize);
    int arr[arraySize];

    printf("\n* * * The array should be sorted * * *\n");

    for (it = 0; it < arraySize; it++)
    {
        printf("Enter the %d element of the array : ", it + 1);
        scanf("%d", &arr[it]);
    }
    printf("\n");

    int searchElement;
    printf("Enter the element to be searched for : ");
    scanf("%d", &searchElement);

    if (interpolationSearch(arr, arraySize, searchElement))
    {
        printf("Element is present in the array\n");
    }
    else
    {
        printf("Element is absent in the array\n");
    }

    return 0;
}