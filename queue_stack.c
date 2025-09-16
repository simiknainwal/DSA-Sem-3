#include<stdio.h>
#include<stdlib.h>

struct stack{
    int* arr;
    int top,size,cap;
};

struct queue{
    struct stack* s1,* s2;
};

struct stack* initialize(int val){
    struct stack* st=(struct stack*)malloc(sizeof(struct stack));
    st->arr=(int*)malloc(sizeof(int)*val);
    st->top=-1;
    st->cap=val;
    st->size=0;
    return st;
}

int isEmpty(struct stack* st){
    return st->top==-1;
}

int isFull(struct stack* st){
    return st->top==st->cap-1;
}

void push(struct stack* st,int val){
    if(isFull(st)){
        return;
    }
    st->top++;
    st->arr[st->top]=val;
    st->size++;
}

int pop(struct stack* st){
    if(isEmpty(st)){
        return -1;
    }
    st->size--;
    return st->arr[st->top--];
}

int top1(struct stack* st){
    if(isEmpty(st)){
        return -1;
    }
    return st->arr[st->top];
}

struct queue* initializeQueue(int size){
    struct queue* q=(struct queue*)malloc(sizeof(struct queue));
    q->s1=initialize(size);
    q->s2=initialize(size);
    return q;
}

void enqueue(struct queue*q,int val){
    if(isFull(q->s1)){
        return;
    }
    while(!isEmpty(q->s1)){
        push(q->s2,pop(q->s1));
    }
    push(q->s1,val);
    while(!isEmpty(q->s2)){
        push(q->s1,pop(q->s2));
    }
}

void dequeue(struct queue*q){
    if(isEmpty(q->s1)){
        return;
    }
    pop(q->s1);
    if(q->s1->size==0){
        q->s1->top=-1;
    }
}

int front(struct queue* q){
    if(isEmpty(q->s1)){
        return -1;
    }

    return q->s1->arr[q->s1->top];
}

int main(){
    struct queue*q=initializeQueue(100);
    enqueue(q,10);
    enqueue(q,20);
    enqueue(q,30);
    enqueue(q,40);
    enqueue(q,50);
    // printf("%d ",front(q));
    // dequeue(q);
    // printf("%d ",front(q));
    // dequeue(q);
    // printf("%d ",front(q));
    // dequeue(q);
    // printf("%d ",front(q));
    // dequeue(q);
    // printf("%d ",front(q));
    // dequeue(q);
    enqueue(q,999);
    enqueue(q,998);
    dequeue(q);
    dequeue(q);
    dequeue(q);
    dequeue(q);
    dequeue(q);
    dequeue(q);
    dequeue(q);
    printf("%d ",front(q));
}

