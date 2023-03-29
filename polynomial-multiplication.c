#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node
{
    int coefficient;
    int power;
    struct node *next;
};

struct node *insert(struct node *head, int co, int po)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node *));
    temp->coefficient = co;
    temp->power = po;
    temp->next = NULL;
    if (head == NULL)
        return temp;
    bool flag = false;
    struct node *ptr = head;
    while (ptr->next != NULL)
    {
        if (ptr->power == po)
        {
            ptr->coefficient += co;
            flag = true;
            break;
        }
        ptr = ptr->next;
    }
    if (flag == false)
        ptr->next = temp;
    return head;
}

void display(struct node *head)
{
    printf("\nThe Result : \n");
    struct node *temp = head;
    while (temp->next != NULL)
    {
        if (temp->power == 0)
            printf("%d + ", temp->coefficient);
        else if (temp->power == 1)
            printf("%dx + ", temp->coefficient);
        else
            printf("%dx^%d + ", temp->coefficient, temp->power);
        temp = temp->next;
    }
    if (temp->power == 0)
        printf("%d", temp->coefficient);
    else if (temp->power == 1)
        printf("%dx", temp->coefficient);
    else
        printf("%dx^%d", temp->coefficient, temp->power);
    printf("\n");
}

int main()
{
    int terms, it, co, po;

    struct node *head1 = NULL;
    printf("Enter the no. of terms for first polynomial : ");
    scanf("%d", &terms);
    for (it = 1; it <= terms; it++)
    {
        printf("Enter the coefficient of the %d term : ", it);
        scanf("%d", &co);
        printf("Enter the power of the %d term : ", it);
        scanf("%d", &po);
        head1 = insert(head1, co, po);
    }

    struct node *head2 = NULL;
    printf("Enter the no. of terms for second polynomial : ");
    scanf("%d", &terms);
    for (it = 1; it <= terms; it++)
    {
        printf("Enter the coefficient of the %d term : ", it);
        scanf("%d", &co);
        printf("Enter the power of the %d term : ", it);
        scanf("%d", &po);
        head2 = insert(head2, co, po);
    }

    struct node *head3 = NULL;
    struct node *temp1 = head1;
    while (temp1 != NULL)
    {
        struct node *temp2 = head2;
        while (temp2 != NULL)
        {
            co = temp1->coefficient * temp2->coefficient;
            po = temp1->power + temp2->power;
            head3 = insert(head3, co, po);
            temp2 = temp2->next;
        }
        temp1 = temp1->next;
    }

    display(head3);
}