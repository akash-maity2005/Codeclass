#include <stdio.h>

void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

void shiftDown(int a[], int n, int i) {
    int p = i;
    int c;

    while (2 * p + 1 < n) {
        c = 2 * p + 1;
        if (c + 1 < n && a[c + 1] > a[c])
            c = c + 1;

        if (a[p] < a[c]) {
            swap(&a[p], &a[c]);
            p = c;
        } else {
            break;
        }
    }
}

void heapify(int a[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
        shiftDown(a, n, i);
}

void heapSort(int a[], int n) {
    heapify(a, n);
    for (int i = n - 1; i > 0; i--) {
        swap(&a[0], &a[i]);
        shiftDown(a, i, 0);
    }
}

void display(int a[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");
}

int main() {
    int a[100], n;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    printf("Enter elements: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    printf("\nOriginal array: ");
    display(a, n);

    heapSort(a, n);

    printf("\nSorted array: ");
    display(a, n);

    return 0;
}
