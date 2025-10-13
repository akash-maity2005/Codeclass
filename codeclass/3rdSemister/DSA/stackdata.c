#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;



Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

void push(Node** top, int value) {
    Node* newNode = createNode(value);
    newNode->next = *top;
    *top = newNode;
}

void pop(Node** top) {
    if (*top == NULL) {
        printf("Node underflow\n");
        return;
    }
    Node* temp = *top;
    printf("Popped: %d\n", temp->data);
    *top = (*top)->next;
    free(temp);
}

void peek(Node** top) {
    if (*top == NULL) {
        printf("Node is empty\n");
        return;
    }
    printf("Top element: %d\n", (*top)->data);
}

void display(Node** top) {
    Node* current = *top;
    printf("Node: ");
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    Node *top = NULL;
    int choice, value;

    do {
        printf("\n1.Push  2.Pop  3.Peek  4.Display  5.Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to push: ");
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
                display(&top);
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice\n");
        }
    } while (choice != 5);

    return 0;
}