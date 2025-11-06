#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

Node* createNode(int n) {
    Node *newnode = (Node*) malloc(sizeof(Node));
    newnode->data = n;
    newnode->next = NULL;
    return newnode;
}

void push(Node **top, int value) {
    Node *newnode = createNode(value);
    newnode->next = *top;
    *top = newnode;
}

void pop(Node **top) {
    if (*top == NULL) {
        printf("Stack Underflow\n");
        return;
    }
    Node *temp = *top;
    printf("Popped element: %d\n", temp->data);
    *top = (*top)->next;
    free(temp);
}

void peek(Node **top) {
    if (*top == NULL) {
        printf("Stack Underflow\n");
        return;
    }
    printf("Top element: %d\n", (*top)->data);
}

int main() {
    Node *top = NULL;
    int k, value;

    do {
        printf("Enter 1 for push\n2 for pop\n3 for peek\n4 for exit:\n");
        scanf("%d", &k);

        switch (k) {
            case 1:
                printf("Enter element:\n");
                scanf("%d", &value);
                push(&top, value);
                break;

            case 2:
                pop(&top);
                break;

            case 3:
                peek(&top);
                break;

            case 4:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid Input\n");
        }
    } while (k != 4);

    return 0;
}
