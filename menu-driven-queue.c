// NOTE : We are using Linkedlist in order to save memory space. Using array for queue is not advisable.

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *enqueue(struct node *head)
{
    int value;
    printf("Enter the value to be enqueued : ");
    scanf("%d", &value);
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = value;
    temp->next = NULL;
    if (head == NULL)
        return temp;
    struct node *ptr = head;
    while (ptr->next != NULL)
        ptr = ptr->next;
    ptr->next = temp;
    printf("%d is enqueued in the Queue\n", value);
    return head;
}

struct node *dequeue(struct node *head)
{
    if (head == NULL)
    {
        printf("Queue Underflow\n");
        return head;
    }
    struct node *temp = head->next;
    printf("%d is dequeued from the Queue\n", head->data);
    free(head);
    return temp;
}

void display(struct node *head)
{
    printf("\nQueue : \n");
    while (head != NULL)
    {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

int main()
{
    int c;
    struct node *head = NULL;
    while (true)
    {
        printf("\nPress 1 to Enqueue\n");
        printf("Press 2 to Dequeue\n");
        printf("Press 3 to Display\n");
        printf("Press 4 to Exit\n");
        printf("\nEnter your choice : ");
        scanf("%d", &c);
        switch (c)
        {
        case 1:
            head = enqueue(head);
            break;
        case 2:
            head = dequeue(head);
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
}