#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>

struct node
{
    int data;
    struct node *next;
};

struct node *push(struct node *top, int value)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = value;
    temp->next = top;
    return temp;
}

struct node *pop(struct node *top)
{
    if (top == NULL)
    {
        printf("Underflow\n");
        return top;
    }
    struct node *temp = top->next;
    free(top);
    return temp;
}

int main()
{
    char prefix[100];
    int n1, n2, s, it;
    printf("Enter the Postfix Expression : ");
    scanf("%s", &prefix);
    struct node *top = NULL;
    for (it = strlen(prefix) - 1; it >= 0; it--)
    {
        if (isdigit(prefix[it]) == true)
            top = push(top, prefix[it] - 48);
        else
        {
            n1 = top->data;
            top = pop(top);
            n2 = top->data;
            top = pop(top);
            switch (prefix[it])
            {
            case '+':
                s = n1 + n2;
                break;
            case '-':
                s = n2 - n1;
                break;
            case '*':
                s = n1 * n2;
                break;
            case '/':
                s = n2 / n1;
                break;
            }
            top = push(top, s);
        }
    }

    printf("The Result : %d\n", top->data);

    return 0;
}