// NOTE : The auxiliary array's size is taken 10 by default. Change it accordingly.

#include<stdio.h>
#include<stdlib.h>

#define MAX_SIZE 10

int front=-1, rear=-1;
int queue[MAX_SIZE];

void enqueue(int value)
{
    if((rear+1)%MAX_SIZE == front)
    {
        printf("Queue is full\n");
        return;
    }
    if(front == -1)
        front = rear = 0;
    else
        rear = (rear+1)%MAX_SIZE;
    queue[rear] = value;
}

int dequeue()
{
    if(front == -1)
    {
        printf("Queue is empty\n");
        return -1;
    }
    int value = queue[front];
    if(front == rear)
        front = rear = -1;
    else
        front = (front+1)%MAX_SIZE;
    return value;
}

void display()
{
    if(front == -1)
    {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue: ");
    int i;
    for(i=front; i!=rear; i=(i+1)%MAX_SIZE)
        printf("%d ", queue[i]);
    printf("%d\n", queue[i]);
}

int main()
{
    int choice = 0;
    while (choice != 4) {
        printf("\n1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                int value;
                printf("Enter the value to enqueue: ");
                scanf("%d", &value);
                enqueue(value);
                break;
            }
            case 2: {
                int value = dequeue();
                if(value != -1)
                    printf("Dequeued value: %d\n", value);
                break;
            }
            case 3: {
                display();
                break;
            }
            case 4: {
                printf("Exiting...\n");
                break;
            }
            default: {
                printf("Invalid choice. Please try again.\n");
                break;
            }
        }
    }

    return 0;
}