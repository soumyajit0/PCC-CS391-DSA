#include <stdio.h>

void linearProbing(int arr[], int arraySize)
{
    int it, hashTableFillSize = 0;
    int hashTableSize;
    printf("Enter the size of the Hash Table : ");
    scanf("%d", &hashTableSize);
    int hashTable[hashTableSize];
    for (it = 0; it < hashTableSize; it++)
    {
        hashTable[it] = -99999;
    }
    for (it = 0; it < arraySize; it++)
    {
        if (hashTableFillSize < hashTableSize)
        {
            if (hashTable[arr[it] % hashTableSize] == -99999)
            {
                hashTable[arr[it] % hashTableSize] = arr[it];
                hashTableFillSize++;
            }
            else
            {
                int tempit = (arr[it] % hashTableSize) + 1;
                tempit = tempit % hashTableSize;
                while (hashTable[tempit] != -99999)
                {
                    tempit++;
                    tempit = tempit % hashTableSize;
                }
                hashTable[tempit] = arr[it];
                hashTableFillSize++;
            }
        }
        else
        {
            printf("\nThe Hash Table is too small to store all the values\n");
            return;
        }
    }

    printf("\n\nThe Hash Table is : \n");
    for (it = 0; it < hashTableSize; it++)
    {
        if (hashTable[it] == -99999)
        {
            printf("_____\n");
        }
        else
        {
            printf("%d\n", hashTable[it]);
        }
    }
    printf("\n");
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

    linearProbing(arr, arraySize);

    return 0;
}