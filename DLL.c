//Wastage of memory is the drawback
#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node*next;
    struct node*prev;
};

struct node* createNode(int val){
    struct node*newNode=(struct node*)malloc(sizeof(struct node));
    newNode->prev=newNode->next=NULL;
    newNode->data=val;
    return newNode;
}

void insertAtBegin(struct node**head,int val){
    if(*head==NULL){
        *head=createNode(val);
        return;
    }
    struct node* newNode=createNode(val);
    newNode->next=(*head);
    (*head)->prev=newNode;
    *head=newNode;
}
void insertAtEnd(struct node**head,int val){
    if(*head==NULL){
        *head=createNode(val);
        return;
    }
    struct node* newNode=createNode(val);
    struct node* temp=*head;
    while(temp->next){
            temp=temp->next;
    }
    temp->next=newNode;
    newNode->prev=temp;
}

void insertAtK(struct node**head,int val,int k){
    if(*head==NULL){
        return;
    }if(k==0){
        insertAtBegin(head,val);
        return;
    }
struct node* newNode=createNode(val);
struct node* temp=*head;
k=k-1;
while(temp){
    k--;
    if(k==0)break;
    temp=temp->next;
}
newNode->next=temp->next;
temp->next=newNode;
newNode->prev=temp;
}

void deleteAtBegin(struct node**head){
    if(*head==NULL){
        return;
    }
    struct node* temp=*head;
    *head=(*head)->next;
    (*head)->prev=NULL;
    free(temp);
}

void deleteAtEnd(struct node**head){
    if(*head==NULL){
        return;
    }
    if((*head)->next==NULL){
        free(*head);
    }
    struct node* temp=*head;
    while(temp->next->next){
        temp=temp->next;
    }
    temp->next=NULL;
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
    struct node*head=NULL;
    insertAtBegin(&head,1);
    insertAtBegin(&head,2);
    insertAtBegin(&head,3);
    insertAtBegin(&head,4);
    insertAtEnd(&head,5);
    insertAtK(&head,999,2);
    printList(&head);
    deleteAtBegin(&head);
    deleteAtEnd(&head);
}
