#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* next;
};

struct queue{
    struct node* front,* rear;
};

struct node* createNode(int val){
    struct node* newNode=(struct node*)malloc(sizeof(struct node));
    newNode->data=val;
    newNode->next=NULL;
    return newNode;
}

void enqueue(struct queue* q,int val){
    if(q->front==NULL){
        q->front=q->rear=createNode(val);
        return;
    }
    struct node* temp=createNode(val);
    q->rear->next=temp;
    q->rear=temp;
}

void dequeue(struct queue* q){
    if(q->front==NULL){
        return;
    }
    struct node* temp=q->front;
    q->front=q->front->next;
    if(q->front==NULL){
        q->rear=NULL;
    }
    free(temp);
}

void display(struct queue* q){
    if(q->front==NULL){
        return;
    }
    struct node* temp=q->front;
    while(temp){
        printf("%d ",temp->data);
        temp=temp->next;
    }
}

int main(){
    struct queue* q=(struct queue*)malloc(sizeof(struct queue));
    q->front=q->rear=NULL;
    enqueue(q,1);
    enqueue(q,2);
    enqueue(q,3);
    enqueue(q,4);
    enqueue(q,5);
    dequeue(q);
    display(q);
}