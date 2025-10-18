#include<stdio.h>
void mergesort(int a[],int l,int r){
    if(l<r){
        int m=(l+r)/2;
        mergesort(a,l,m);
        mergesort(a,m+1,r);
        merge(a,l,m,r);
    }
}
void merge(int ar[],int l,int m,int r){
    int aux[r];
    int k=l,i=l,j=m+1;
    while(i<=m && j<=r){
        if(ar[i]<=ar[j]){
            aux[k++]=ar[i++];
        }
        else{
            aux[k++]=ar[j++];
        }
    }
    while(i<=m){
        aux[k++]=ar[i++];
    }
    while(j<=r){
        aux[k++]=ar[j++];
    }
    for(int p=l;p<=r;p++){
        ar[p]=aux[p];
    }

}
int main()
{
    
    return 0;
}