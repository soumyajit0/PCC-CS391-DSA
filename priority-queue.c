#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node
{
    int data;
    int priority;
    struct node *next;
};

struct node *enqueue(struct node *head)
{
    int value, power;
    printf("\nEnter the Value to be enqueue : ");
    scanf("%d", &value);
    printf("Enter the priority of the value : ");
    scanf("%d", &power);
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = value;
    temp->priority = power;
    printf("%d is enqueued in the Priority Queue with %d priority\n", value, power);
    if (head == NULL || head->priority < power)
    {
        temp->next = head;
        return temp;
    }
    struct node *ptr = head;
    while (ptr->next != NULL && ptr->next->priority > power)
        ptr = ptr->next;
    temp->next = ptr->next;
    ptr->next = temp;
    return head;
}

struct node *dequeue(struct node *head)
{
    if (head == NULL)
    {
        printf("Priority Queue Underflow\n");
        return head;
    }
    struct node *temp = head->next;
    printf("%d is dequeued from the Priority Queue\n", head->data);
    free(head);
    return temp;
}

void display(struct node *head)
{
    printf("\nPriority Queue : \n");
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