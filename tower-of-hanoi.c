// NOTE : We are considering 3 towers; Source, Auxiliary and Destination with n no. of discs.

#include <stdio.h>

void towerOfHanoi(int n, char from, char to, char aux)
{
    if (n == 1)
    {
        printf("Move disk 1 from %c to %c\n", from, to);
        return;
    }
    towerOfHanoi(n - 1, from, aux, to);
    printf("Move disk %d from %c to %c\n", n, from, to);
    towerOfHanoi(n - 1, aux, to, from);
}

int main()
{
    printf("Enter the no. of disks : ");
    int n;
    scanf("%d", &n);
    towerOfHanoi(n, 'A', 'B', 'C');
    return 0;
}