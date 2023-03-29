#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
};

struct Node *front = NULL;
struct Node *rear = NULL;

void insertFront(int value)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = front;
    if (front == NULL)
        rear = newNode;
    else
        front->prev = newNode;
    front = newNode;
}

void insertRear(int value)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->prev = rear;
    newNode->next = NULL;
    if (rear == NULL)
        front = newNode;
    else
        rear->next = newNode;
    rear = newNode;
}

int deleteFront()
{
    if (front == NULL)
    {
        printf("Queue is empty\n");
        return -1;
    }
    struct Node *temp = front;
    int value = temp->data;
    front = front->next;
    if (front == NULL)
        rear = NULL;
    else
        front->prev = NULL;
    free(temp);
    return value;
}

int deleteRear()
{
    if (rear == NULL)
    {
        printf("Queue is empty\n");
        return -1;
    }
    struct Node *temp = rear;
    int value = temp->data;
    rear = rear->prev;
    if (rear == NULL)
        front = NULL;
    else
        rear->next = NULL;
    free(temp);
    return value;
}

void display()
{
    if (front == NULL)
    {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue: ");
    struct Node *temp = front;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main()
{
    int choice = 0;
    while (choice != 5)
    {
        printf("\n1. Insert at Front\n");
        printf("2. Insert at Rear\n");
        printf("3. Delete from Front\n");
        printf("4. Delete from Rear\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
        {
            int value;
            printf("Enter the value to insert: ");
            scanf("%d", &value);
            insertFront(value);
            break;
        }
        case 2:
        {
            int value;
            printf("Enter the value to insert: ");
            scanf("%d", &value);
            insertRear(value);
            break;
        }
        case 3:
        {
            int value = deleteFront();
            if (value != -1)
                printf("Deleted value: %d\n", value);
            break;
        }
        case 4:
        {
            int value = deleteRear();
            if (value != -1)
                printf("Deleted value: %d\n", value);
            break;
        }
        case 5:
        {
            printf("Exiting...\n");
            break;
        }
        default:
        {
            printf("Invalid choice. Please try again.\n");
            break;
        }
        }
        display();
    }

    return 0;
}