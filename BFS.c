// NOTE : We are taking an already accepted graph for the traversal.
// If you wish to take an user input graph then make changes accordingly, given the algorithm remains same.
//       2----3
//     / |   /|
//   1   | /  |
//     \ |/   |
//       4----5

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *enqueue(struct node *head, int value)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = value;
    temp->next = NULL;
    if (head == NULL)
    {
        return temp;
    }
    struct node *ptr = head;
    while (ptr->next != NULL)
    {
        ptr = ptr->next;
    }
    ptr->next = temp;
    return head;
}

struct node *dequeue(struct node *head)
{
    struct node *temp = head->next;
    free(head);
    return temp;
}

void bfs(int graph[][5], int visited[], int vertices, struct node *head)
{
    int it, value = 1;
    printf("%d ", value);
    visited[value - 1] = 1;
    head = enqueue(head, value);
    while (head != NULL)
    {
        value = head->data;
        head = dequeue(head);
        for (it = 0; it < vertices; it++)
        {
            if (graph[value - 1][it] == 1 && visited[it] == 0)
            {
                printf("%d ", it + 1);
                visited[it] = 1;
                head = enqueue(head, it + 1);
            }
        }
    }
    printf("\n");
}

int main()
{
    int vertices = 5;
    int graph[][5] = {
        {0, 1, 0, 1, 0},
        {1, 0, 1, 1, 0},
        {0, 1, 0, 1, 1},
        {1, 1, 1, 0, 1},
        {0, 0, 1, 1, 0}};
    int visited[] = {0, 0, 0, 0, 0};
    struct node *head = NULL;

    printf("The BFS Traversal : \n");
    bfs(graph, visited, vertices, head);

    return 0;
}