// NOTE : realloc() is similar to malloc() and works the same way.
// We are using realloc() because it is 4x times faster than malloc().

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct
{
    int top;
    char *items;
} Stack;

void push(Stack *s, char item)
{
    s->top++;
    s->items = (char *)realloc(s->items, (s->top + 1) * sizeof(char));
    if (s->items == NULL)
    {
        printf("Memory allocation error\n");
        exit(1);
    }
    s->items[s->top] = item;
}

char pop(Stack *s)
{
    if (s->top == -1)
    {
        printf("Stack underflow\n");
        exit(1);
    }
    char item = s->items[s->top];
    s->top--;
    s->items = (char *)realloc(s->items, (s->top + 1) * sizeof(char));
    if (s->top == -1)
    {
        s->items = NULL;
    }
    return item;
}

char peek(Stack *s)
{
    if (s->top == -1)
    {
        printf("Stack is empty\n");
        exit(1);
    }
    return s->items[s->top];
}

int is_operand(char c)
{
    return isalnum(c);
}

int precedence(char c)
{
    if (c == '+' || c == '-')
    {
        return 1;
    }
    else if (c == '*' || c == '/')
    {
        return 2;
    }
    else if (c == '^')
    {
        return 3;
    }
    else
    {
        return -1;
    }
}

void prefix_to_postfix(char prefix[], char postfix[])
{
    Stack s;
    s.top = -1;
    s.items = NULL;
    int prefix_len = strlen(prefix);
    for (int i = prefix_len - 1; i >= 0; i--)
    {
        char c = prefix[i];
        if (is_operand(c))
        {
            int postfix_len = strlen(postfix);
            postfix[postfix_len] = c;
            postfix[postfix_len + 1] = '\0';
        }
        else if (c == ')')
        {
            push(&s, c);
        }
        else if (c == '(')
        {
            while (s.top != -1 && peek(&s) != ')')
            {
                int postfix_len = strlen(postfix);
                postfix[postfix_len] = pop(&s);
                postfix[postfix_len + 1] = '\0';
            }
            if (s.top == -1)
            {
                printf("Invalid expression: unbalanced parentheses\n");
                exit(1);
            }
            pop(&s); // Pop the left parenthesis
        }
        else
        {
            while (s.top != -1 && precedence(c) < precedence(peek(&s)))
            {
                int postfix_len = strlen(postfix);
                postfix[postfix_len] = pop(&s);
                postfix[postfix_len + 1] = '\0';
            }
            push(&s, c);
        }
    }
    while (s.top != -1)
    {
        if (peek(&s) == '(')
        {
            printf("Invalid expression: unbalanced parentheses\n");
            exit(1);
        }
        int postfix_len = strlen(postfix);
        postfix[postfix_len] = pop(&s);
        postfix[postfix_len + 1] = '\0';
    }
}

int main()
{
    char prefix[100], postfix[100] = "";

    // Read the prefix expression from the user
    printf("Enter the prefix expression: ");
    fgets(prefix, sizeof(prefix), stdin);
    prefix[strlen(prefix) - 1] = '\0'; // Remove the newline character

    // Convert the prefix expression to postfix
    prefix_to_postfix(prefix, postfix);

    // Display the postfix expression to the user
    printf("The postfix expression is: %s\n", postfix);

    return 0;
}