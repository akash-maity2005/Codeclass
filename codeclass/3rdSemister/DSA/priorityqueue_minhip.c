#include<stdio.h>
#define max 5
typedef struct queue{
    int arr[max];
    int front;
    int rear;
}queue;
void swap(int *a,int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}
void createqueue(queue *q){
    q->rear=-1;
}
int isFull(queue *q){
    return q->rear==max-1;
}
int isEmpty(queue *q){
    return q->rear==-1;
}
void insert_priority(queue *q,int item){
    if(isFull(q)){
        printf("queue full\n");
        return;
    }
    q->arr[++(q->rear)]=item;
    int c=q->rear;
    int f;
    do{
        f=(c-1)/2;
        if(q->arr[c]<q->arr[f]){
            swap(&q->arr[c],&q->arr[f]);
            c=f;
        }
        else
            break;

    }while (c!=0);
    
    
}
int delete_priority(queue *q){
    if(isEmpty(q)){
        printf("queue empty\n");
        return 0;
    }
    int data = q->arr[0];
    q->arr[0]=q->arr[q->rear--];
    int p=0;
    int c;
    do{
        c=2*p+1;
        if(c+1>q->rear){
            break;
        }
        if(c+1<=q->rear && q->arr[c+1]<q->arr[c]){
            c=c+1;
        }
        if(q->arr[c]<q->arr[p]){
            swap(&q->arr[p],&q->arr[c]);
            p=c;
        }
        else
            break;
    }while(c<=q->rear);
    return data;
}
int peek(queue *q){
    if(isEmpty(q)){
        printf("queue empty\n");
        return 0;
    }
    return q->arr[q->front];
}
int main()
{
    queue q;
    createqueue(&q);
    int k,elem;
    do{
        printf("Enter 1 for enqueue\n2 for dequeue\n3 for peek\n4 for exit\n");
        scanf("%d",&k);
        switch(k){
            case 1:
                printf("enter element to push\n");
                scanf("%d",&elem);
                insert_priority(&q,elem);
                break;
            case 2:
                printf("element dequeued is %d\n",delete_priority(&q));
                break;
            
            case 3:
                printf("the elment is %d\n",peek(&q));
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("wrong choice selected\n");
                break;
        }
    }while(k!=4);
    return 0;
}