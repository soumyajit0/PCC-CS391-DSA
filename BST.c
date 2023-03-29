#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *insert(struct node *root)
{
    int value;
    printf("Enter the value to be inserted : ");
    scanf("%d", &value);
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = value;
    temp->left = NULL;
    temp->right = NULL;

    if (root == NULL)
        return temp;

    struct node *ptr = root;
    while (true)
    {
        if (value == ptr->data)
        {
            printf("BST cannot have a duplicate value\n");
            return root;
        }
        else if (value < ptr->data)
        {
            if (ptr->left == NULL)
            {
                ptr->left = temp;
                return root;
            }
            ptr = ptr->left;
        }
        else if (value > ptr->data)
        {
            if (ptr->right == NULL)
            {
                ptr->right = temp;
                return root;
            }
            ptr = ptr->right;
        }
    }
}

struct node *findMaxNode(struct node *root)
{
    if (root->right == NULL)
        return root;
    return findMaxNode(root->right);
}

struct node *deleteLink(struct node *root)
{
    if (root->left == NULL)
        return root->right;
    else if (root->right == NULL)
        return root->left;
    else
    {
        struct node *ptr = findMaxNode(root->left);
        ptr->right = root->right;
        ptr = root->left;
        free(root);
        return ptr;
    }
}
struct node *delete(struct node *root)
{
    int value;
    if (root == NULL)
    {
        printf("BST is already empty\n");
        return root;
    }
    printf("Enter the value to be deleted : ");
    scanf("%d", &value);
    if (value == root->data)
    {
        return deleteLink(root);
    }
    struct node *temp = root;
    while (temp != NULL)
    {
        if (value < temp->data)
        {
            if (temp->left != NULL && value == temp->left->data)
            {
                temp->left = deleteLink(temp->left);
                break;
            }
            temp = temp->left;
        }
        else if (value > temp->data)
        {
            if (temp->right != NULL && value == temp->right->data)
            {
                temp->right = deleteLink(temp->right);
                break;
            }
            temp = temp->right;
        }
    }
    return root;
}

void preOrder(struct node *root)
{
    printf("%d ", root->data);
    preOrder(root->left);
    preOrder(root->right);
}

void inOrder(struct node *root)
{
    inOrder(root->left);
    printf("%d ", root->data);
    inOrder(root->right);
}
void postOrder(struct node *root)
{
    postOrder(root->left);
    postOrder(root->right);
    printf("%d ", root->data);
}

int max(int a, int b)
{
    return (a > b) ? a : b;
}

int height(struct node *root)
{
    if (root == NULL)
        return 0;
    return max(height(root->left), height(root->right)) + 1;
}

void kBST(struct node *root, int k)
{
    if (root == NULL)
        return;
    if (k == 1)
        printf("%d ", root->data);
    kBST(root->left, k - 1);
    kBST(root->right, k - 1);
}

void levelOrder(struct node *root)
{
    int k;
    for (k = 1; k <= height(root); k++)
        kBST(root, k);
}

int findSize(struct node *root)
{
    if (root == NULL)
        return 0;
    return findSize(root->left) + findSize(root->right) + 1;
}

int minBST(struct node *root)
{
    while (root->left != NULL)
        root = root->left;
    return root->data;
}

int maxBST(struct node *root)
{
    while (root->right != NULL)
        root = root->right;
    return root->data;
}

int main()
{
    struct node *root = NULL;
    int c;
    while (true)
    {
        printf("\nPress 1 to Insert\n");
        printf("Press 2 to Delete\n");
        printf("Press 3 for Preorder Traversal\n");
        printf("Press 4 for Inorder Traversal\n");
        printf("Press 5 for Postorder Traversal\n");
        printf("Press 6 for Level Order Traversal\n");
        printf("Press 7 for Height of BST\n");
        printf("Press 8 to print Nodes at K Level\n");
        printf("Press 9 for Size of the BST\n");
        printf("Press 10 for the Minimum Node\n");
        printf("Press 11 for the Maximum Node\n");
        printf("Press 12 to Exit\n");
        printf("\nEnter your choice : ");
        scanf("%d", &c);
        switch (c)
        {
        case 1:
            root = insert(root);
            break;
        case 2:
            root = delete (root);
            break;
        case 3:
            printf("Preorder Traversal : \n");
            preOrder(root);
            printf("\n");
            break;
        case 4:
            printf("Inorder Traversal : \n");
            inOrder(root);
            printf("\n");
            break;
        case 5:
            printf("Postorder Traversal : \n");
            postOrder(root);
            printf("\n");
            break;
        case 6:
            printf("Levelorder Traversal : \n");
            levelOrder(root);
            printf("\n");
            break;
        case 7:
            printf("The Height of the BST : %d\n", height(root));
            break;
        case 8:
            int k;
            printf("Enter the value of k : ");
            scanf("%d", &k);
            printf("The Nodes at %d level are/is : \n");
            kBST(root, k);
            printf("\n");
        case 9:
            printf("The Size of the BST : %d\n", findSize(root));
            break;
        case 10:
            printf("The Minimum Node : %d\n", minBST(root));
            break;
        case 11:
            printf("The Maximum Node : %d\n", maxBST(root));
            break;
        case 12:
            return 0;
        default:
            printf("\nInvalid Choice. Try again\n");
        }
    }
}