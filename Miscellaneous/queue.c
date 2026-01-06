#include<stdio.h>
#include<stdlib.h>

struct queue{
    int* arr;
    int front,rear,size,cap;
};

struct queue* initialize(int size){
    struct queue* q=(struct queue*)malloc(sizeof(struct queue));
    q->arr=(int*)malloc(sizeof(int)*size);
    q->front=q->rear=-1;
    q->size=0;
    q->cap=size;
    return q;
}

int isEmpty(struct queue* q){
    return q->size==0;
}

int isFull(struct queue* q){
    return (q->rear+1)%q->cap==q->front;
}

void enqueue(struct queue* q,int val){
    if(isFull(q)){
        return ;
    }
    if(q->front==-1){
        q->front=q->rear=0;
    }
    q->arr[q->rear]=val;
    q->rear=(q->rear+1)%q->cap;
    q->size++;
}

void dequeue(struct queue* q){
    if(isEmpty(q)){
        return;
    }
    q->front=(q->front+1)%q->cap;
    q->size--;
}

void printQueue(struct queue* q){
    if(isEmpty(q)){
        return;
    }
    int i=q->front;
    int count=q->size;
    while(count--){
        printf("%d ",q->arr[i]);
        i=(i+1)%q->cap;
    }
}

int main(){
    struct queue* q=initialize(100);
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
    enqueue(q,9999);
    enqueue(q,9998);
    printQueue(q);
}