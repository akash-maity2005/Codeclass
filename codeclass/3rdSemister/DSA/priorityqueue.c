#include <stdio.h>
#include <stdlib.h>

#define MAX 3

typedef struct {
    int ar[MAX];
    int rear;
} Q;

void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

void create_pq(Q *q) {
    q->rear = -1;
}

int isFull(Q *q) {
    return (q->rear == MAX - 1);
}

int isEmpty(Q *q) {
    return (q->rear == -1);
}

void insert_pq(Q *q, int n) {
    if (isFull(q)) {
        printf("Priority Queue is Full\n");
        return;
    }

    q->ar[++q->rear] = n;  // insert at end
    int c = q->rear;
    int f;

    while (c > 0) {
        f = (c - 1) / 2;
        if (q->ar[c] > q->ar[f]) {
            swap(&q->ar[c], &q->ar[f]);
            c = f;
        } else
            break;
    }

    printf("Inserted %d successfully\n", n);
}

int delete_pq(Q *q) {
    if (isEmpty(q)) {
        printf("Priority Queue is Empty\n");
        return -1;
    }

    int n = q->ar[0];
    q->ar[0] = q->ar[q->rear];
    q->rear--;

    int p = 0, c;

    while (1) {
        c = 2 * p + 1;
        if (c > q->rear)
            break;

        if (c + 1 <= q->rear && q->ar[c + 1] > q->ar[c])
            c = c + 1;

        if (q->ar[c] > q->ar[p]) {
            swap(&q->ar[c], &q->ar[p]);
            p = c;
        } else
            break;
    }

    return n;
}

int peek_pq(Q *q) {
    if (isEmpty(q)) {
        printf("Priority Queue is Empty\n");
        return -1;
    }
    return q->ar[0];
}

void display_pq(Q *q) {
    if (isEmpty(q)) {
        printf("Priority Queue is Empty\n");
        return;
    }

    printf("Priority Queue: ");
    for (int i = 0; i <= q->rear; i++)
        printf("%d ", q->ar[i]);
    printf("\n");
}

int main() {
    Q q;
    create_pq(&q);
    int ch, val;

    while (1) {
        printf("\n--- Choose Task ---\n");
        printf("1. Insert (Enqueue)\n2. Delete (Dequeue)\n3. Peek (Top Element)\n4. Display\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                printf("Enter element to insert: ");
                scanf("%d", &val);
                insert_pq(&q, val);
                break;

            case 2:
                val = delete_pq(&q);
                if (val != -1)
                    printf("Deleted element: %d\n", val);
                break;

            case 3:
                val = peek_pq(&q);
                if (val != -1)
                    printf("Top element: %d\n", val);
                break;

            case 4:
                display_pq(&q);
                break;

            case 5:
                printf("Exiting...\n");
                exit(0);

            default:
                printf("Error: Wrong Input\n");
        }
    }

    return 0;
}
