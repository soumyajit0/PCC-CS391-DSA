#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *insertBeg(struct node *head)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    printf("Enter the value to be inserted : ");
    int value;
    scanf("%d", &value);
    temp->data = value;
    temp->next = head;
    return temp;
}

struct node *insertEnd(struct node *head)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    printf("Enter the value to be inserted : ");
    int value;
    scanf("%d", &value);
    temp->data = value;
    temp->next = NULL;
    if (head == NULL)
        return temp;
    struct node *ptr = head;
    while (ptr->next != NULL)
        ptr = ptr->next;
    ptr->next = temp;
    return head;
}

struct node *insertSort(struct node *head)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    printf("Enter the value to be inserted : ");
    int value;
    scanf("%d", &value);
    temp->data = value;
    temp->next = head;
    while (temp->next != NULL)
    {
        if (temp->data < temp->next->data)
            break;
        int k = temp->data;
        temp->data = temp->next->data;
        temp->next->data = k;
    }
    return temp;
}

struct node *insertPos(struct node *head, int value, int pos)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = value;
    temp->next = NULL;
    if (pos == 1)
    {
        temp->next = head;
        return temp;
    }
    int it;
    struct node *ptr = head;
    for (it = 1; it < pos - 1; it++)
    {
        if (ptr == NULL)
        {
            printf("Invalid Position\n");
            return head;
        }
        ptr = ptr->next;
    }
    temp->next = ptr->next;
    ptr->next = temp;
    return head;
}

struct node *deleteBeg(struct node *head)
{
    if (head == NULL)
    {
        printf("LinkedList is already empty\n");
        return head;
    }
    struct node *temp = head->next;
    free(head);
    return temp;
}

struct node *deleteEnd(struct node *head)
{
    if (head == NULL)
    {
        printf("LinkedList is already empty\n");
        return head;
    }
    else if (head->next == NULL)
    {
        free(head);
        return NULL;
    }
    struct node *temp = head;
    while (temp->next->next != NULL)
        temp = temp->next;
    free(temp->next);
    temp->next = NULL;
    return head;
}

struct node *deletePos(struct node *head, int pos)
{
    if (head == NULL)
    {
        printf("LinkedList is already empty\n");
        return head;
    }
    if (pos == 1)
    {
        struct node *temp = head->next;
        free(head);
        return temp;
    }
    int it;
    struct node *temp = head;
    for (it = 1; it < pos - 1; it++)
    {
        if (temp == NULL)
        {
            printf("Invalid position\n");
            return head;
        }
        temp = temp->next;
    }
    if (temp->next == NULL)
    {
        printf("Invalid position\n");
        return head;
    }
    struct node *ptr = temp->next->next;
    free(temp->next);
    temp->next = ptr;
    return head;
}

struct node *reverse(struct node *head)
{
    struct node *prev = NULL, *current = head, *next = NULL;

    while (current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    return prev;
}

struct node *sort(struct node *head)
{
    int swapped, i;
    struct node *ptr1;
    struct node *lptr = NULL;

    if (head == NULL || head->next == NULL)
    {
        return head;
    }

    do
    {
        swapped = 0;
        ptr1 = head;

        while (ptr1->next != lptr)
        {
            if (ptr1->data > ptr1->next->data)
            {
                // Swap the nodes
                int temp = ptr1->data;
                ptr1->data = ptr1->next->data;
                ptr1->next->data = temp;
                swapped = 1;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    } while (swapped);
    return head;
}

void display(struct node *head)
{
    printf("LinkedList : \n");
    while (head != NULL)
    {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

int main()
{
    int c, pos, value;
    struct node *head = NULL;
    while (true)
    {
        printf("\nPress 1 to Insert at the Beginning\n");
        printf("Press 2 to Insert at the End\n");
        printf("Press 3 to Insert in a Sorted LinkedList\n");
        printf("Press 4 to Insert at a specific position\n");
        printf("Press 5 to Delete from the Beginning\n");
        printf("Press 6 to Delete from the End\n");
        printf("Press 7 to Delete a specific node\n");
        printf("Press 8 to Reverse the LinkedList\n");
        printf("Press 9 to Sort the LinkedList\n");
        printf("Press 10 to Display\n");
        printf("Press 11 to Exit\n");
        printf("\nEnter your choice : ");
        scanf("%d", &c);
        switch (c)
        {
        case 1:
            head = insertBeg(head);
            break;
        case 2:
            head = insertEnd(head);
            break;
        case 3:
            head = insertSort(head);
            break;
        case 4:
            printf("Enter the value to be inserted : ");
            scanf("%d", &value);
            printf("Enter the position where to be inserted : ");
            scanf("%d", &pos);
            head = insertPos(head, value, pos);
            break;
        case 5:
            head = deleteBeg(head);
            break;
        case 6:
            head = deleteEnd(head);
            break;
        case 7:
            printf("Enter the position to be deleted : ");
            scanf("%d", &pos);
            head = deletePos(head, pos);
            break;
        case 8:
            head = reverse(head);
            break;
        case 9:
            head = sort(head);
            break;
        case 10:
            display(head);
            break;
        case 11:
            return 0;
        default:
            printf("Invalid choice. Try again\n");
        }
    }
    return 0;
}