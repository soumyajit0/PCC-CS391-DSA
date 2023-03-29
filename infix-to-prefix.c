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

void infixRev(char *c)
{
    int l = strlen(c);
    for (int i = 0; i <= l / 2; i++)
    {
        if (c[i] == '(')
            c[i] = ')';
        else if (c[i] == ')')
            c[i] = '(';
        if (c[l - i - 1] == '(')
            c[l - i - 1] = ')';
        else if (c[l - i - 1] == ')')
            c[l - i - 1] = '(';
        char a = c[i];
        c[i] = c[l - i - 1];
        c[l - i - 1] = a;
    }
}

int main()
{
    char c[20], c2[20];
    int index = -1;
    scanf("%s", c);
    infixRev(c);
    struct node *top = NULL;
    for (int i = 0; i < strlen(c); i++)
    {
        if ((c[i] >= 'a' && c[i] <= 'z') || (c[i] >= 'A' && c[i] <= 'Z'))
            c2[++index] = c[i];
        else if (c[i] == '(')
            top = push(top, '(');
        else if (c[i] == ')')
        {
            while (top->data != '(')
            {
                c2[++index] = top->data;
                top = pop(top);
            }
            top = pop(top);
        }
        else
        {
            while (top != NULL && precidence(top->data) >= precidence(c[i]))
            {
                c2[++index] = top->data;
                top = pop(top);
            }
            top = push(top, c[i]);
        }
    }
    while (top != NULL)
    {
        c2[++index] = top->data;
        top = pop(top);
    }
    for (int i = index; i >= 0; i--)
        printf("%c", c2[i]);
    printf("\n");
    return 0;
}