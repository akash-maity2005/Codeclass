#include<stdio.h>
void shellsort(int a[],int n){
    int incr=n/2;
    while(incr>0){
        for(int i=incr;i<n;i++){
            int temp=a[i];
            int j=i-incr;
            for( ;j>=0;j=j-incr){
                if(a[j]>temp){
                    a[j+incr]=a[j];
                }
                else{
                    break;
                }
            }
            a[j+incr]=temp;
        }
        incr=incr/2;
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
    shellsort(a,5);
    display(a,5);
    return 0;
}