#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node *next;
}node;
node *createnode(int data){
    node *newnode=(node*)malloc(sizeof(node));
    newnode->data=data;
    newnode->next=NULL;
    return newnode;
}
void insertatbeg(node **prear,int data){
    node *newnode=createnode(data);
    if(*prear==NULL){
        newnode->next=newnode;
        *prear=newnode;
        return;
    }
    newnode->next=(*prear)->next;
    (*prear)->next=newnode;


}
void insertatend(node **prear,int data){
    node *newnode = createnode(data);
    if(*prear==NULL){
        newnode->next=newnode;
        *prear=newnode;
        return;
    }
    newnode->next=(*prear)->next;
    (*prear)->next=newnode;
    *prear=newnode;
}
void insertatpos(node **prear,int d,int pos){
    if(*prear==NULL||pos==1){
        insertatbeg(prear,d);
        return;
        
    }
    node *temp=(*prear)->next;
    int cnt=1;
    while(cnt<pos-1&& temp!=*prear){
        temp=temp->next;
        cnt++;
    }
    if(temp==*prear){
        insertatend(prear,d);
    }
    node *newnode=createnode(d);
    newnode->next=temp->next;
    temp->next=newnode;

}
void deleteAtBeg(node **prear) {
    if (*prear == NULL) return;

    node *head = (*prear)->next;

    if (head == *prear) {
        free(head);
        *prear = NULL;
        return;
    } 
    (*prear)->next = head->next;
    free(head);
}
void deleteAtEnd(node **prear) {
    if (*prear == NULL) 
        return;
    node *curr = (*prear)->next;
    if (curr == *prear) {
        free(curr);
        *prear = NULL;
        return;
    }
    while (curr->next != *prear) {
        curr = curr->next;
    }
    curr->next = (*prear)->next;
    free(*prear);
    *prear = curr;
}
void deleteAtPos(node **prear, int pos) {
    if (*prear == NULL) {
        printf("List is empty.\n");
        return;
    }

    if (pos == 1) {
        deleteAtBeg(prear);
        return;
    }

    node *curr = (*prear)->next;
    node *prev = *prear;
    int count = 1;

    while (count < pos && curr != *prear) {
        prev = curr;
        curr = curr->next;
        count++;
    }

    if (curr == *prear) {
        deleteAtEnd(prear);
        return;
    }

    prev->next = curr->next;
    curr->next=NULL;
    free(curr);
}
void display(node **prear) {
    if (*prear == NULL) 
        return;

    node *temp = (*prear)->next;
    printf("List: ");
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != (*prear)->next);
    printf("\n");
}

int main()
{
    node *prear = NULL;
    int choice, val, pos;

       do {
        printf("\n--- Circular Linked List Menu ---\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Insert at Position\n");
        printf("4. Delete at Beginning\n");
        printf("5. Delete at End\n");
        printf("6. Delete at Position\n");
        printf("7. Display List\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert at beginning: ");
                scanf("%d", &val);
                insertatbeg(&prear, val);
                break;
            case 2:
                printf("Enter value to insert at end: ");
                scanf("%d", &val);
                insertatend(&prear, val);
                break;
            case 3:
                printf("Enter value and position to insert: ");
                scanf("%d %d", &val, &pos);
                insertatpos(&prear, val, pos);
                break;
            case 4:
                deleteAtBeg(&prear);
                break;
            case 5:
                deleteAtEnd(&prear);
                break;
            case 6:
                printf("Enter position to delete: ");
                scanf("%d", &pos);
                deleteAtPos(&prear, pos);
                break;
            case 7:
                display(&prear);
                break;
            case 8:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Try again.\n");
        }
    } while (choice != 8);



    return 0;
}