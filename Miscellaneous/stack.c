#include<stdio.h>
#include<stdlib.h>

struct stack{
    int* arr;
    int top,size,cap;
};

struct stack* initialize(int size){
    struct stack* st=(struct stack*)malloc(sizeof(struct stack));
    st->arr=(int*)malloc(sizeof(int)*size);
    st->top=-1;
    st->size=0;
    st->cap=size;
    return st;
}

int isFull(struct stack* st){
    return st->size==st->cap;
}

int isEmpty(struct stack* st){
    return st->size==0;
}

void push(struct stack* st,int val){
    if(isFull(st)){
        return;
    }
    st->arr[++(st->top)]=val;
    st->size++;
}

void pop(struct stack* st){
    if(isEmpty(st)){
        return;
    }
    st->arr[st->top--];
    st->size--;
}

int top(struct stack* st){
    return st->arr[st->top];
}

void printStack(struct stack* st){
    if(st->top==-1){
        return;
    }
    for(int i=st->top;i>=0;i--){
        printf("%d ",st->arr[i]);
    }
}



int main(){
    struct stack* st=initialize(100);
    push(st,1);
    push(st,2);
    push(st,3);
    pop(st);
    push(st,4);
    pop(st);
    push(st,5);
    printf("%d\n",top(st));
    printStack(st);
}