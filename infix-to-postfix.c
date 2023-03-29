#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct node
{
    char data;
    struct node *next;
};

struct node *push(struct node *top, char c)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = c;
    temp->next = top;
    return temp;
}

struct node *pop(struct node *top)
{
    if (top == NULL)
        return NULL;
    struct node *temp = top->next;
    free(top);
    return temp;
}

int precidence(char c)
{
    if (c == '^')
        return 3;
    else if (c == '*' || c == '/')
        return 2;
    else if (c == '+' || c == '-')
        return 1;
    else
        return -1;
}

int main()
{
    char c[20];
    scanf("%s", c);
    struct node *top = NULL;
    for (int i = 0; i < strlen(c); i++)
    {
        if ((c[i] >= 'a' && c[i] <= 'z') || (c[i] >= 'A' && c[i] <= 'Z'))
            printf("%c", c[i]);
        else if (c[i] == '(')
            top = push(top, '(');
        else if (c[i] == ')')
        {
            while (top->data != '(')
            {
                printf("%c", top->data);
                top = pop(top);
            }
            top = pop(top);
        }
        else
        {
            while (top != NULL && precidence(top->data) >= precidence(c[i]))
            {
                printf("%c", top->data);
                top = pop(top);
            }
            top = push(top, c[i]);
        }
    }
    while (top != NULL)
    {
        printf("%c", top->data);
        top = pop(top);
    }
    printf("\n");
    return 0;
}