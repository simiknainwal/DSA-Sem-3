#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* next;
};

struct node* createNode(int val){
    struct node* newNode=(struct node*)malloc(sizeof(struct node));
    newNode->next=NULL;
    newNode->data=val;
    return newNode;
}

void insertAtBegin(struct node**head,int val){
    if(*head==NULL){
        *head=createNode(val);
        return;
    }
    // struct node* temp=*head;
    struct node* newNode=createNode(val);
    newNode->next=*head;
    *head=newNode;
}

void swap(struct node**head){
    if(*head==NULL || (*head)->next==NULL){
        return;
    }
    struct node* cur=*head;
    struct node* nxt=*head;
    struct node* prev=*head;
    while(cur->next){
            nxt=cur->next->next;
            prev=cur->next;
            prev->next=cur;
            cur->next=nxt;
            cur=nxt;
            prev=nxt;
    }
}

void printList(struct node**head){
    if(*head==NULL){
        return;
    }
    struct node* temp=*head;
    while(temp){
        printf("%d ",temp->data);
        temp=temp->next;
    }
}

int main(){
    struct node* head=NULL;
    insertAtBegin(&head,1);
    insertAtBegin(&head,2);
    insertAtBegin(&head,3);
    insertAtBegin(&head,4);
    insertAtBegin(&head,5);
    printList(&head);
    printf("\n");
    swap(&head);
    printList(&head);
}