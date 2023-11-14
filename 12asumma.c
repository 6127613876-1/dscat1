#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

struct Node* insert(struct Node* root, int data) {
    if (root == NULL)
        return createNode(data);

    if (data < root->data)
        root->left = insert(root->left, data);
    else if (data > root->data)
        root->right = insert(root->right, data);

    return root;
}

void inorderTraversal(struct Node* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}

int findLargest(struct Node* root) {
    if (root == NULL) {
        printf("BST is empty\n");
        return -1;
    }
    while (root->right != NULL)
        root = root->right;
    return root->data;
}

int findSmallest(struct Node* root) {
    if (root == NULL) {
        printf("BST is empty\n");
        return -1;
    }
    while (root->left != NULL)
        root = root->left;
    return root->data;
}

int findLargestInLeftSubtree(struct Node* root) {
    if (root->right == NULL)
        return root->data;
    return findLargestInLeftSubtree(root->right);
}

int findSmallestInRightSubtree(struct Node* root) {
    if (root->left == NULL)
        return root->data;
    return findSmallestInRightSubtree(root->left);
}

struct Node* search(struct Node* root, int key) {
    if (root == NULL || root->data == key)
        return root;

    if (key < root->data)
        return search(root->left, key);
    return search(root->right, key);
}

struct Node* deleteNode(struct Node* root, int key) {
    if (root == NULL)
        return root;
    if (key < root->data)
        root->left = deleteNode(root->left, key);
    else if (key > root->data)
        root->right = deleteNode(root->right, key);
    else {
        if (root->left == NULL) {
            struct Node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct Node* temp = root->left;
            free(root);
            return temp;
        }
        root->data = findLargestInLeftSubtree(root->left);
        root->left = deleteNode(root->left, root->data);
    }
    return root;
}

int main() {
    struct Node* root = NULL;
    int choice, data;
    while (1) {
        printf("\n1. Insert\n2. Print\n3. Find Largest\n4. Find Smallest\n5. Find Largest in Left Subtree\n6. Find Smallest in Right Subtree\n7. Search\n8. Delete\n9. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                root = insert(root, data);
                break;
            case 2:
                printf("Inorder Traversal: ");
                inorderTraversal(root);
                printf("\n");
                break;
            case 3:
                printf("Largest element: %d\n", findLargest(root));
                break;
            case 4:
                printf("Smallest element: %d\n", findSmallest(root));
                break;
            case 5:
                printf("Largest in Left Subtree: %d\n", findLargestInLeftSubtree(root->left));
                break;
            case 6:
                printf("Smallest in Right Subtree: %d\n", findSmallestInRightSubtree(root->right));
                break;
            case 7:
                printf("Enter element to search: ");
                scanf("%d", &data);
                if (search(root, data))
                    printf("Element found in the BST.\n");
                else
                    printf("Element not found in the BST.\n");
                break;
            case 8:
                printf("Enter element to delete: ");
                scanf("%d", &data);
                root = deleteNode(root, data);
                break;
            case 9:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
