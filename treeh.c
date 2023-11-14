#include <stdio.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node* create()
{
    int x;
    scanf("%d",&x);
    struct node *newnode;
    newnode = (struct node*)malloc(sizeof(newnode));
    if(x==-1)
    {
        return NULL;
    }
    newnode->data=x;
    printf("left child of %d : ",x);
    newnode->left=create();
    printf("right child of %d : ",x);
    newnode->right=create();
    return newnode;
}
int treeheight(struct node* root)
{
    if (root == NULL)
    {
        return 0;
    }
    else
    {
        int lh=treeheight(root->left);
        int rh=treeheight(root->right);
        if (lh>=rh)
        {
            return lh+1;
        }
        else
        {
            return rh+1;
        }
        
    }
     
}

void main()
{
    int root;
    root=create();
    int height = treeheight(root);
    printf("%d\n",height);
}