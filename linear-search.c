// NOTE : This code is applicable for 0-indexed array.
// In case of 1-indexed array, increment the value of pos by 1 before printing.

#include <stdio.h>

int linear_search(int arr[], int n, int key)
{
    // Loop through the array elements
    for (int i = 0; i < n; i++)
    {
        // If the current element matches the key, return the index
        if (arr[i] == key)
        {
            return i;
        }
    }
    // If the key is not found, return -1
    return -1;
}

int main()
{
    int n, key, pos;

    // Read the size of the array from the user
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    // Taking an n sized array
    int arr[n];

    // Read the array elements from the user
    printf("Enter the array elements: \n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    // Read the key to be searched from the user
    printf("Enter the key to be searched: ");
    scanf("%d", &key);

    // Perform linear search on the array
    pos = linear_search(arr, n, key);

    // Display the search result
    if (pos == -1)
    {
        printf("The key is not found in the array\n");
    }
    else
    {
        printf("The key is found at index %d\n", pos);
    }

    return 0;
}