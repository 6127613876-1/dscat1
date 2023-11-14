#include <stdio.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node* createnode(int data)
{
    struct node* newNode = (struct Node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
};

struct node *insert(struct node* root, int data)
{
    if(root==NULL)
    {
        return createnode(data);
    }

    if(data<root->data)
    {
        root->left=insert(root->left,data);
    }
    else if (data>root->data)
    {
        root->right=insert(root->right,data);
    }
    return root;
};


