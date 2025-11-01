#include<stdio.h>
enum colour{
    white,grey,black

};
void readmatrix(int a[10][10],int n){
    int i,j;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
}
void dfs(int a[][10],int d[],int f[],enum colour c[],int n,int p[]){
    int u;
    for(u=0;u<n;u++){
        if(c[u]==white){
            dfs_visit(a,d,f,c,n,p,u);
        }
    }
}
void dfs_visit(int a[][10],int d[],int f[],enum colour c[],int n,int p[],int u){
    static int time=0;
    int v;
    c[u]=grey;
    d[u]=time++;
    for(v=0;v<n;v++){
        if(a[u][v]==1 && c[v]==white){
            p[v]=u;
            dfs_visit(a,d,f,c,n,p,v);
        }
    }
    c[u]=black;
    f[u]=time++;

}
int main()
{
    int n;
    int a[10][10];
    enum colour c[10];
    int d[10], f[10], p[10];

    printf("Enter number of vertices (max 10): ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    readmatrix(a, n);
    for (int i = 0; i < n; i++) {
        c[i] = white;
        p[i] = -1;
    }

    dfs(a, d, f, c, n, p);

    printf("\nVertex\tDiscovery\tFinish\tParent\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t\t%d\t\t%d\t", i, d[i], f[i]);
        if (p[i] == -1)
            printf("NULL\n");
        else
            printf("%d\n", p[i]);
    }

    return 0;
}
