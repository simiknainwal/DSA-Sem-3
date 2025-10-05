#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* next;
};

struct queue{
    struct node* front,*rear;
};

struct queue* initialize(){
struct queue* q=(struct queue*)malloc(sizeof(struct queue));
q->rear=q->front=NULL;
return q;
}

struct node* createNode(int val){
    struct node* newNode=(struct node*)malloc(sizeof(struct node));
    newNode->data=val;
    newNode->next=NULL;
    return newNode;
}

void enqueue(struct queue* q,int val){
    if(q->rear==NULL){
        q->front=q->rear=createNode(val);
        return;
    }
    struct node* newNode=createNode(val);
    q->rear->next=newNode;
    q->rear=newNode;
}

void dequeue(struct queue*q){
    if(q->rear==NULL){
        return;
    }
    struct node* temp=q->front;
    q->front=q->front->next;
    if(q->front==NULL){
        q->rear=NULL;
    }
    free(temp);
}

void printQueue(struct queue* q){
    if(q->rear==NULL){
        return;
    }
    struct node* temp=q->front;
    while(temp){
        printf("%d ",temp->data);
        temp=temp->next;
    }
}

int main(){
    struct queue* q=initialize();
    enqueue(q,1);
    enqueue(q,2);
    enqueue(q,3);
    enqueue(q,4);
    enqueue(q,5);
    dequeue(q);
    dequeue(q);
    dequeue(q);
    dequeue(q);
    dequeue(q);
    enqueue(q,999);
    // enqueue(q,999);
    printQueue(q);
}