#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* next;
};
struct list{
    struct node* head;
    struct node* tail;
};

void initialize(struct list*l){
    // struct list* l=(struct list*)malloc(sizeof(struct list));
    l->head=NULL;
    // return l;
}

struct node* createNode(int val){
    struct node* newNode=(struct node*)malloc(sizeof(struct node));
    newNode->data=val;
    newNode->next=NULL;
    return newNode;
}

void insertAtBegin(struct list*l,int val){
    if(l->head==NULL){
        l->head=createNode(val);
        return;
    }
    struct node* newNode=createNode(val);
    newNode->next=l->head;
    l->head=newNode;
}

void printList(struct list*l){
    if(l->head==NULL){
        return;
    }
    struct node* temp=l->head;
    while(temp){
        printf("%d ",temp->data);
        temp=temp->next;
    }
}

int main(){
    // struct list* l=(struct list*)malloc(sizeof(struct list));
    struct list l;
    initialize(&l);
    insertAtBegin(&l,1);
    insertAtBegin(&l,2);
    insertAtBegin(&l,3);
    insertAtBegin(&l,4);
    insertAtBegin(&l,5);
    printList(&l);
}