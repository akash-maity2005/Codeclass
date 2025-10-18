#include<stdio.h>
void Bubble_sort2(int a[], int size) {
    for (int i = 1; i < size; i++) {
        int flag = 0;  
        for (int j = 0; j < size - i; j++) {
            if (a[j] > a[j + 1]) {
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
                flag = 1;
            }
        }
        if (flag == 0) {
            break;
        }
    }
}
void display(int a[],int n){
    for(int i=0;i<n;i++){
        printf("%d ",a[i]);
    }
    printf("\n");
    
}
int main()
{
    int a[10];
    int n;
    printf("enter the size of the array:\n");
    scanf("%d",&n);
    printf("enter the elements of array:\n");
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    Bubble_sort2(a,n);
    printf("array in sorted order:\n");
    display(a,n);
    return 0;
}