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
int main() {
    node *head = NULL;
    node *tail = NULL;
    int choice, data, position;
    
    printf("Doubly Linked List Operations\n");
    printf("=============================\n");
    
    while(1) {
        printf("\nMenu:\n");
        printf("1. Insert at head\n");
        printf("2. Insert at tail\n");
        printf("3. Insert at position\n");
        printf("4. Delete from head\n");
        printf("5. Delete from tail\n");
        printf("6. Delete from position\n");
        printf("7. Display list\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                printf("Enter data to insert at head: ");
                scanf("%d", &data);
                insertathead(&head, &tail, data);
                printf("Inserted %d at head\n", data);
                break;
                
            case 2:
                printf("Enter data to insert at tail: ");
                scanf("%d", &data);
                insertattail(&head, &tail, data);
                printf("Inserted %d at tail\n", data);
                break;
                
            case 3:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                printf("Enter position: ");
                scanf("%d", &position);
                insertatpos(&head, &tail, data, position);
                printf("Inserted %d at position %d\n", data, position);
                break;
                
            case 4:
                deleteatbeg(&head, &tail);
                printf("Deleted from head\n");
                break;
                
            case 5:
                deleteattail(&head, &tail);
                printf("Deleted from tail\n");
                break;
                
            case 6:
                printf("Enter position to delete: ");
                scanf("%d", &position);
                deleteatpos(&head, &tail, position);
                printf("Deleted from position %d\n", position);
                break;
                
            case 7:
                printf("Current list: ");
                print(&head);
                break;
                
            case 8:
                printf("Exiting...\n");
                exit(0);
                
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    
    return 0;
}
