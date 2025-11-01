#include <stdio.h>
#include <stdlib.h>

typedef struct BST {
    int key;
    struct BST *left;
    struct BST *right;
} node;

node* createNode(int data) {
    node *ptr = (node*)malloc(sizeof(node));
    ptr->key = data;
    ptr->left = NULL;
    ptr->right = NULL;
    return ptr;
}

void insert(node **root, int data) {
    if (*root == NULL) {
        *root = createNode(data);
        return;
    } else if (data < (*root)->key) {
        insert(&(*root)->left, data);
    } else if (data > (*root)->key) {
        insert(&(*root)->right, data);
    }
}

node* search(node *root, int data) {
    if (root == NULL || root->key == data)
        return root;
    else if (data < root->key)
        return search(root->left, data);
    else
        return search(root->right, data);
}

void inorder(node *root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->key);
        inorder(root->right);
    }
}

node* minval(node *root) {
    node *cur = root;
    while (cur && cur->left != NULL)
        cur = cur->left;
    return cur;
}

void deleteNode(node **root, int data) {
    if (*root == NULL)
        return;

    if (data < (*root)->key)
        deleteNode(&(*root)->left, data);
    else if (data > (*root)->key)
        deleteNode(&(*root)->right, data);
    else {
        if ((*root)->left == NULL && (*root)->right == NULL) {
            free(*root);
            *root = NULL;
        } else if ((*root)->left == NULL) {
            node *ptr = *root;
            *root = (*root)->right;
            free(ptr);
        } else if ((*root)->right == NULL) {
            node *ptr = *root;
            *root = (*root)->left;
            free(ptr);
        } else {
            node *ptr = minval((*root)->right);
            (*root)->key = ptr->key;
            deleteNode(&(*root)->right, ptr->key);
        }
    }
}

int main() {
    node *root = NULL;
    int choice, data;

    while (1) {
        printf("\n1. Insert\n2. Delete\n3. Search\n4. Inorder\n5. Exit\nEnter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data: ");
                scanf("%d", &data);
                insert(&root, data);
                break;
            case 2:
                printf("Enter data to delete: ");
                scanf("%d", &data);
                deleteNode(&root, data);
                break;
            case 3:
                printf("Enter data to search: ");
                scanf("%d", &data);
                if (search(root, data))
                    printf("Found\n");
                else
                    printf("Not found\n");
                break;
            case 4:
                inorder(root);
                printf("\n");
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}
