#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *left;
    struct node *right;
};
struct node* create()
{
    int x;
    struct node *newnode;
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("Enter node : ");
    scanf("%d",&x);
    if(x==-1)
    {
        return NULL;
    }
    newnode->data=x;
    printf("Left child of %d ",x);
    newnode->left=create();
    printf("Right child of %d ",x);
    newnode->right=create();
    return newnode;
}
void preorder(struct node* root)
{
    if(root!=NULL)
    {
        printf("%d ",root->data);
        preorder(root->left);
        preorder(root->right);
    }
}
void inorder(struct node* root)
{
    if(root!=NULL)
    {
        inorder(root->left);
        printf("%d ",root->data);
        inorder(root->right);
    }
}
void postorder(struct node* root)
{
    if(root!=NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d ",root->data);
    }
}
void main()
{
    struct node* root;
    printf("enter -1 incase you no need to insert a node\n");
    root=create();
    printf("pre-order : ");
    preorder(root);
    printf("\nin-order : ");
    inorder(root);
    printf("\npost-order : ");
    postorder(root);
}
