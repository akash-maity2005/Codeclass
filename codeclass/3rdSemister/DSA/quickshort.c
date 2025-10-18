#include<stdio.h>
void swap(int *a,int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}
void quicksort(int a[],int beg,int end){
    if(beg<end){
        int p=partition(a,beg,end);
        quicksort(a,beg,p);
        quicksort(a,p+1,end);
    }
}
int partition(int a[],int beg,int end){
    int down=beg-1,up=end+1;
    int pivot=a[beg];
    while(1){
        do{
            --up;
        }while(a[up]>pivot && up>=beg);
        do{
            ++down;
        }while(a[down]<pivot && down<=end);
        if(down<up){
            swap(&a[down],&a[up]);
        }
        else{
            return up;
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
    int a[5]={5,4,3,2,1};
    quicksort(a,0,4);
    display(a,5);
    return 0;
}