#include<stdio.h>
#define max 5
typedef struct queue{
    int arr[max];
    int front;
    int rear;
}queue;
void createqueue(queue *q){
    q->front=-1;
    q->rear=-1;
}
int isFull(queue *q){
    return (q->front==q->rear+1 || (q->front==0 && q->rear==max-1));
}
int isEmpty(queue *q){
    return q->front==-1;
}
void enqueue(queue *q,int item){
    if(isFull(q)){
        printf("queue full\n");
        return;
    }
    if(q->rear==-1){
        q->front=q->rear=0;
        q->arr[q->rear]=item;
    }
    else if(q->front!=0 && q->rear==max-1){
        q->rear=0;
        q->arr[q->rear]=item;
    }
    else{
        q->arr[++(q->rear)]=item;
    }
}
int dequeue(queue *q){
    if(isEmpty(q)){
        printf("queue empty\n");
        return 0;
    }
    int data = q->arr[q->front];
    if(q->rear==q->front)
        q->rear=q->front=-1;
    else if(q->front==max-1)
        q->front=0;
    else
        q->front++;
    return data;
}
int peek(queue *q){
    if(isEmpty(q)){
        printf("queue empty\n");
        return 0;
    }
    return q->arr[q->front];
}
enum colour{
    white,grey,black

};
void readmatrix(int a[10][10],int n)
{
    int i,j;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
}
void bfs(int a[10][10],enum colour c[],int p[],int d[],int s,int n)
{
    queue q;
    createqueue(&q);
    int u,v;
    for(u=0;u<n;u++)
    {
        c[u]=white;
        p[u]=-1;
        d[u]=0;
    }
    c[s]=grey;
    enqueue(&q,s);
    do{
        u=dequeue(&q);
        for(v=0;v<n;v++)
        {
            if(a[u][v]==1 && c[v]==white)
            {
                c[v]=grey;
                d[v]=d[u]+1;
                p[v]=u;
                enqueue(&q,v);
            }
        }
        c[u]=black;

    }while(!isEmpty(&q));
}
int main()
{
    
    int n, s;
    int a[10][10];
    enum colour c[10];
    int p[10], d[10];

    printf("Enter the number of vertices (max 10): ");
    scanf("%d", &n);

    printf("Enter the adjacency matrix:\n");
    readmatrix(a, n);

    printf("Enter the source vertex (0 to %d): ", n - 1);
    scanf("%d", &s);

    bfs(a, c, p, d, s, n);

    printf("\nVertex\tDistance from Source\tParent\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t\t%d\t\t", i, d[i]);
        if (i == s)
            printf("NULL\n");
        else
            printf("%d\n", p[i]);
    }
    return 0;
}
