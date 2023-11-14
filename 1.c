#include <stdio.h>
#include <stdlib.h>
typedef struct Node
{
    int data;
    struct Node *left, *right;
} Node;
struct Node *new_node(int x)
{
    struct Node *p = malloc(sizeof(struct Node));
    p->data = x;
    p->left = NULL;
    p->right = NULL;
    return p;
}
Node *insert(Node *root, int x)
{
    if (root == NULL)
        return new_node(x);
    if (x < root->data)
        root->left = insert(root->left, x);
    else if (x > root->data)
        root->right = insert(root->right, x);
    return root;
}
void printAllElements(Node *root)
{
    if (root == NULL)
        return;
    printAllElements(root->left);
    printf("%d ", root->data);
    printAllElements(root->right);
}
void findKthSmallest(Node *root, int k, int *count)
{
    if (root == NULL || *count >= k)
    {
        return;
    }
    findKthSmallest(root->left, k, count);
    (*count)++;
    if (*count == k)
    {
        printf("K-th Smallest Element is %d\n", root->data);
        return;
    }
    findKthSmallest(root->right, k, count);
}
int main()
{
    Node *root = NULL;
    while (1)
    {
        int choice, k, key, count = 0;
        printf("1. Insert an element\n");
        printf("2. Find k'th smallest element\n");
        printf("3. Print all elements\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter the element to insert: ");
            scanf("%d", &key);
            root = insert(root, key);
            break;
        case 2:
            printf("Enter the value of k: ");
            scanf("%d", &k);
            findKthSmallest(root, k, &count); 
            break;
        case 3:
            printf("All elements in BST (in-order): ");
            printAllElements(root);
            printf("\n");
            break;
        case 4:
            exit(0);
        default:
            printf("Invalid choice. Please try again.\n");
        }
    }
}
