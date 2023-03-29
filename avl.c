#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
    int height;
};

int getHeight(struct node *root)
{
    if (root == NULL)
        return 0;
    return root->height;
}

struct node *createNode(int value)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = value;
    temp->height = 1;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

int getBalanceFactor(struct node *root)
{
    if (root == NULL)
        return 0;
    return getHeight(root->left) - getHeight(root->right);
}

int max(int a, int b)
{
    return (a > b) ? a : b;
}

struct node *leftRotate(struct node *x)
{
    struct node *y = x->right;
    struct node *z = y->left;

    x->right = z;
    y->left = x;

    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;

    return y;
}

struct node *rightRotate(struct node *x)
{
    struct node *y = x->left;
    struct node *z = y->right;

    x->left = z;
    y->right = x;

    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;

    return y;
}

struct node *insert(struct node *root, int value)
{
    if (root == NULL)
        return createNode(value);
    else if (value < root->data)
        root->left = insert(root->left, value);
    else if (value > root->data)
        root->right = insert(root->right, value);
    else
        return root;

    root->height = max(getHeight(root->left), getHeight(root->right)) + 1;
    int bf = getBalanceFactor(root);
    // Left Left
    if (bf > 1 && value < root->left->data)
        return rightRotate(root);

    // Right Right
    if (bf < -1 && value > root->right->data)
        return leftRotate(root);

    // Left Right
    if (bf > 1 && value > root->left->data)
    {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    // Right Left
    if (bf < -1 && value < root->right->data)
    {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

void preOrder(struct node *root)
{
    if (root == NULL)
        return;
    printf("%d ", root->data);
    preOrder(root->left);
    preOrder(root->right);
}

int main()
{
    struct node *root = NULL;
    int choice, value;
    while (true)
    {
        printf("\nPress 1 to Insert\n");
        printf("Press 2 for PreOrder Traversal\n");
        printf("Press 3 to Exit\n");
        printf("\nEnter your choice : ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("\nEnter the value to be inserted : ");
            scanf("%d", &value);
            root = insert(root, value);
            break;
        case 2:
            printf("Pre-Order Traversal : \n");
            preOrder(root);
            printf("\n");
            break;
        case 3:
            return 0;
        default:
            printf("Invalid Choice. Try Again\n");
        }
    }
    return 0;
}