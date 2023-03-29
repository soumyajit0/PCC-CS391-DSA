// NOTE : We are using Linkedlist in order to save memory space. Using array for stack is not advisable.

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node
{
    int data;
    struct node *next;
};

struct node *push(struct node *head)
{
    int value;
    printf("\nEnter the value to be pushed : ");
    scanf("%d", &value);
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = value;
    temp->next = head;
    printf("%d is pushed into the Stack\n", value);
    return temp;
}

struct node *pop(struct node *head)
{
    if (head == NULL)
    {
        printf("Stack Underflow\n");
        return head;
    }
    struct node *temp = head->next;
    printf("%d is poped from the Stack\n", head->data);
    free(head);
    return temp;
}

void display(struct node *head)
{
    printf("\nStack : \n");
    while (head != NULL)
    {
        printf("%d\n", head->data);
        head = head->next;
    }
}

int main()
{
    int c;
    struct node *head = NULL;
    while (true)
    {
        printf("\nPress 1 to Push\n");
        printf("Press 2 to Pop\n");
        printf("Press 3 to Display\n");
        printf("Press 4 to Exit\n");
        printf("\nEnter your choice : ");
        scanf("%d", &c);
        switch (c)
        {
        case 1:
            head = push(head);
            break;
        case 2:
            head = pop(head);
            break;
        case 3:
            display(head);
            break;
        case 4:
            return 0;
        default:
            printf("Invalid Choice. Try Again\n");
        }
    }
    return 0;
}