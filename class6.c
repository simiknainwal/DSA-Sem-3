// ****** Doubly Linked List ******

#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node* next, * prev;
};

struct node* createNode(int val){
    struct node* temp=(struct node*)malloc(sizeof(struct node));

    temp->data=val;
    temp->next=temp->prev=NULL;
    return temp;
}

void insertAtBegin(struct node** head, struct node** tail,int val){
    if(*head==NULL){
        *head=*tail=createNode(val);
        return;
    }
    struct node* newNode=createNode(val);
    newNode->next=*head;
    newNode->prev=NULL;
    (*head)->prev=newNode;
    *head=newNode;
}

void printList(struct node**head, struct node** tail){
    if(*head==NULL){
        printf("Empty List");
        return;
    }

    struct node* temp=*tail;
    while(temp){
        printf("%d ",temp->data);
        temp=temp->prev;
    }
}
    int main(){
    struct node* head=NULL;
    struct node* tail=NULL;
    insertAtBegin(&head,&tail,99);
    insertAtBegin(&head,&tail,98);
    insertAtBegin(&head,&tail,97);
    printList(&head,&tail);
}