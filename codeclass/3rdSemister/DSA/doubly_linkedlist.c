#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int data;
    struct node *next;
    struct node *prev;
}node;
node *createnode(int val){
    node *newn=(node*)malloc(sizeof(node));
    newn->data=val;
    newn->next=newn->prev=NULL;
    return newn;
}
void insertathead(node **head,node **tail,int val){
    node *newnode=createnode(val);
    if(*head==NULL){
        *head=newnode;
        *tail=newnode;
        return;
    }
    (*head)->prev=newnode;
    newnode->next=*head;
    *head=newnode;
}
void insertattail(node **head,node **tail,int val){
    node *newnode=createnode(val);
    if(*tail==NULL){
        *head=newnode;
        *tail=newnode;
        return;
    }
    (*tail)->next=newnode;
    newnode->prev=*tail;
    *tail=newnode;
}
void print(node **head){
    node *temp=*head;
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp=temp->next;
    }
}
void deleteatbeg(node **head,node**tail){
    if(*head==NULL){
        return;

    }
    if(*head==*tail){
        node *temp=*head;
        free(temp);
        *head=NULL;
        *tail=NULL;
        return;
    }
    node *temp=*head;
    temp->next->prev=NULL;
    *head=temp->next;
    temp->next=NULL;
    free(temp);
}
void deleteattail(node **head,node**tail){
    if(*tail==NULL){
        return;

    }
    if(*head==*tail){
        node *temp=*tail;
        free(temp);
        *head=NULL;
        *tail=NULL;
        return;
    }
    node *temp=*tail;
    temp->prev->next=NULL;
    *tail=temp->prev;
    temp->prev=NULL;
    free(temp);
}
void insertatpos(node **head,node **tail,int data,int pos){
    if(pos==1){
        insertathead(head,tail,data);
        return;
    }
    else{

        node *temp=*head;
        int cnt=1;
        while(cnt<pos-1 && temp!=NULL){
            temp=temp->next;
            cnt++;
        }
        if(temp->next==NULL){
            insertattail(head,tail,data);
            return;
        }
        node *newnode=createnode(data);
        temp->next->prev=newnode;
        newnode->next=temp->next;
        newnode->prev=temp;
        temp->next=newnode;
    }
}
void deleteatpos(node **head,node**tail,int pos){
    if(pos==1){
        deleteatbeg(head,tail);
        return;
    }
    else{
        node *curr=*head;
        int cnt=1;
        while(cnt<pos && curr!=NULL){
            curr=curr->next;
            cnt++;
        }
        if(curr==*tail){
            deleteattail(head,tail);
            return;
        }
        curr->prev->next=curr->next;
        curr->next->prev=curr->prev;
        curr->next=NULL;
        curr->prev=NULL;
        free(curr);
    }
}
int main()
{
    node *head=NULL;
    node *tail=NULL;
    insertathead(&head,&tail,12);
    insertathead(&head,&tail,18);
    insertathead(&head,&tail,19);
    insertattail(&head,&tail,10);
    insertattail(&head,&tail,20);
    print(&head);
    deleteatbeg(&head,&tail);
    deleteatbeg(&head,&tail);
    printf("\n");
    print(&head);
    deleteattail(&head,&tail);
    deleteattail(&head,&tail);
    printf("\n");
    print(&head);
    insertatpos(&head,&tail,14,2);
    insertatpos(&head,&tail,15,2);
    insertatpos(&head,&tail,16,3);
    printf("\n");
    print(&head);
    deleteatpos(&head,&tail,2);
    printf("\n");
    print(&head);
    deleteatpos(&head,&tail,3);
    printf("\n");
    print(&head);
    return 0;
}