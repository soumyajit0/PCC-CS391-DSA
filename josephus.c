// NOTE : Josephus problem can be solved much easily using recursion.

#include <stdio.h>
#include <stdlib.h>

// Node structure for circular linked list
struct Node
{
    int data;
    struct Node *next;
};

// Queue structure
struct Queue
{
    struct Node *rear;
};

// Function to create a new node
struct Node *newNode(int data)
{
    struct Node *node = (struct Node *)malloc(sizeof(struct Node));
    node->data = data;
    node->next = NULL;
    return node;
}

// Function to create a new queue
struct Queue *createQueue()
{
    struct Queue *queue = (struct Queue *)malloc(sizeof(struct Queue));
    queue->rear = NULL;
    return queue;
}

// Function to enqueue an item
void enqueue(struct Queue *queue, int data)
{
    struct Node *node = newNode(data);
    if (queue->rear == NULL)
    {
        queue->rear = node;
        node->next = node;
    }
    else
    {
        node->next = queue->rear->next;
        queue->rear->next = node;
        queue->rear = node;
    }
}

// Function to dequeue an item
int dequeue(struct Queue *queue)
{
    if (queue->rear == NULL)
    {
        printf("Queue is empty\n");
        return -1;
    }
    int data;
    if (queue->rear->next == queue->rear)
    {
        data = queue->rear->data;
        free(queue->rear);
        queue->rear = NULL;
    }
    else
    {
        struct Node *temp = queue->rear->next;
        data = temp->data;
        queue->rear->next = temp->next;
        free(temp);
    }
    return data;
}

// Function to display the queue
void display(struct Queue *queue)
{
    if (queue->rear == NULL)
    {
        printf("Queue is empty\n");
        return;
    }
    struct Node *temp = queue->rear->next;
    printf("Queue: ");
    do
    {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != queue->rear->next);
    printf("\n");
}

// Function to solve the Josephus problem
void josephus(int n, int k)
{
    struct Queue *queue = createQueue();
    int i;
    for (i = 1; i <= n; i++)
    {
        enqueue(queue, i);
    }
    while (queue->rear != NULL)
    {
        for (i = 1; i < k; i++)
        {
            enqueue(queue, dequeue(queue));
        }
        printf("%d ", dequeue(queue));
    }
}

// Main function
int main()
{
    int n, k;
    printf("Enter the number of people: ");
    scanf("%d", &n);
    printf("Enter the kth person to be eliminated: ");
    scanf("%d", &k);
    printf("The order of elimination is: ");
    josephus(n, k);
    printf("\n");
    return 0;
}