#include<stdio.h>
#include<stdlib.h>

struct queue{
    int* arr;
    int front,rear,cap,size;
};

struct stack{
    struct queue* q1,* q2;
};

struct queue* initialize(int size){
    struct queue* q=(struct queue*)malloc(sizeof(struct queue));
    q->arr=(int*)malloc(sizeof(int)*size);
    q->front=q->rear=-1;
    q->cap=size;
    q->size=0;
    return q;
}

int isFull(struct queue* q){
    return (q->rear+1)%q->cap==q->front;
}

int isEmpty(struct queue*q){
    return q->size==0;
}

void enqueue(struct queue* q,int val){
    if(isFull(q)){
        return;
    }
    if(q->front==-1){
        q->front=0;
    }
q->rear=(q->rear+1)%q->cap;
q->arr[q->rear]=val;
q->size++;
}

int dequeue(struct queue* q){
    if(isEmpty(q)){
        return -1;
    }
    int t=q->arr[q->front];
    q->front=(q->front+1)%q->cap;
    q->size--;
    if(q->size==0){
        q->front=q->rear=-1;
    }
    return t;
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

struct stack* createStack(int size) {
    struct stack* st = (struct stack*)malloc(sizeof(struct stack));
    st->q1 = initialize(size);
    st->q2 = initialize(size);
    return st;
}
void push(struct stack* st,int val){
    if(isFull(st->q1)){
        return;
    }
    while(!isEmpty(st->q1)){
    enqueue(st->q2,dequeue(st->q1));
    }
    enqueue(st->q1,val);
    while(!isEmpty(st->q2)){
        enqueue(st->q1,dequeue(st->q2));
    }
}

void pop(struct stack*st){
    if(isEmpty(st->q1)){
        return;
    }
    dequeue(st->q1);
}

int top(struct stack* st){
    if(isEmpty(st->q1)){
        return -1;
    }
    return st->q1->arr[st->q1->front];
}

int main(){
    struct stack* st=createStack(100);
    push(st,1);
    push(st,2);
    push(st,3);
    push(st,4);
    push(st,5);
    printf("%d ",top(st));
    pop(st);
    printf("%d ",top(st));
    pop(st);
    printf("%d ",top(st));
    pop(st);
    printf("%d ",top(st));
    pop(st);
    printf("%d ",top(st));
}