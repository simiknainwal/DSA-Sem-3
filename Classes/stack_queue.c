#include<stdio.h>
#include<stdlib.h>


struct queue{
    int* arr;
    int front,rear,cap,size;
};

struct queue* initialize(int val){
    struct queue* q=(struct queue*)malloc(sizeof(struct queue));
    q->arr=(int*)malloc(sizeof(int));
    q->front=q->rear=-1;
    q->cap=val;
    q->size=0;
    return q;
}

int isFull(struct queue* q){
    return (q->rear+1)%q->cap==q->front;
}
int isEmpty(struct queue* q){
    return q->size==0;
}

void enqueue(struct queue*q,int val){
    if(isFull(q)){
        return;
    }
    if(q->front==-1){
        q->front=0;
        // q->rear=0;
    }
    q->rear=(q->rear+1)%q->cap;
    q->arr[q->rear]=val;
    q->size++;

}

void dequeue(struct queue* q){
    if(isEmpty(q)){
        return;
    }

    q->front=(q->front+1)%q->cap;
    q->size--;
    if(q->size==0){
        q->front=q->rear=-1;
    }
}

void push(){
    
}

void printQueue(struct queue* q){
    if(isEmpty(q)){
        return;
    }
    int count=q->size;
    int i=q->front;
    while(count--){
        printf("%d ",q->arr[i]);
        i=(i+1)%q->cap;
    }
}
