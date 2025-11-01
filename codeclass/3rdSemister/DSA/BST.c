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

void inorder(node *root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->key);
        inorder(root->right);
    }
}

void preorder(node *root) {
    if (root != NULL) {
        printf("%d ", root->key);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(node *root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->key);
    }
}

int main() {
    node *root = NULL;
    int choice, data;

    while (1) {
        printf("\n--- BINARY SEARCH TREE MENU ---\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Search\n");
        printf("4. Inorder Traversal\n");
        printf("5. Preorder Traversal\n");
        printf("6. Postorder Traversal\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
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
                    printf("%d found in BST\n", data);
                else
                    printf("%d not found in BST\n", data);
                break;
            case 4:
                printf("Inorder Traversal: ");
                inorder(root);
                printf("\n");
                break;
            case 5:
                printf("Preorder Traversal: ");
                preorder(root);
                printf("\n");
                break;
            case 6:
                printf("Postorder Traversal: ");
                postorder(root);
                printf("\n");
                break;
            case 7:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice, try again\n");
        }
    }
    return 0;
}
