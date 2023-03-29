#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct node
{
    char data;
    struct node *left;
    struct node *right;
} Node;

Node *create_node(char data)
{
    Node *new_node = (Node *)malloc(sizeof(Node));
    if (new_node == NULL)
    {
        printf("Memory allocation error\n");
        exit(1);
    }
    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

void inorder_traversal(Node *root)
{
    if (root != NULL)
    {
        inorder_traversal(root->left);
        printf("%c ", root->data);
        inorder_traversal(root->right);
    }
}

void preorder_traversal(Node *root)
{
    if (root != NULL)
    {
        printf("%c ", root->data);
        preorder_traversal(root->left);
        preorder_traversal(root->right);
    }
}

void postorder_traversal(Node *root)
{
    if (root != NULL)
    {
        postorder_traversal(root->left);
        postorder_traversal(root->right);
        printf("%c ", root->data);
    }
}

int is_operand(char c)
{
    return isalnum(c);
}

Node *build_expression_tree(char postfix[])
{
    int len = strlen(postfix);
    Node *stack[len];
    int top = -1;
    for (int i = 0; i < len; i++)
    {
        char c = postfix[i];
        if (is_operand(c))
        {
            Node *new_node = create_node(c);
            stack[++top] = new_node;
        }
        else
        {
            Node *new_node = create_node(c);
            new_node->right = stack[top--];
            new_node->left = stack[top--];
            stack[++top] = new_node;
        }
    }
    return stack[top];
}

int main()
{
    char postfix[100];

    // Read the postfix expression from the user
    printf("Enter the postfix expression: ");
    fgets(postfix, sizeof(postfix), stdin);
    postfix[strlen(postfix) - 1] = '\0'; // Remove the newline character

    // Build the expression tree from the postfix expression
    Node *root = build_expression_tree(postfix);

    // Display the expression tree using inorder, preorder, and postorder traversals
    printf("Inorder traversal: ");
    inorder_traversal(root);
    printf("\n");

    printf("Preorder traversal: ");
    preorder_traversal(root);
    printf("\n");

    printf("Postorder traversal: ");
    postorder_traversal(root);
    printf("\n");

    return 0;
}