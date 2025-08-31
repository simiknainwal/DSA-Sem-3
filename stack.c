#include<stdio.h>
#include<stdlib.h>

struct stack{
    int *arr;
    int top,cap,size;
};

struct stack* initialize(int val){
    struct stack*st=(struct stack*)malloc(sizeof(struct stack));
    st->arr=(int*)malloc(sizeof(int)*val);
    st->top=-1;
    st->cap=val;
    st->size=0;
    return st;
}

void push(struct stack*st,int val){
    if(st->size==st->cap){
        printf("Overflow");
        return;
    }
    st->top++;
    st->arr[st->top]=val;
    st->size++;
}

void pop(struct stack*st){
    if(st->size==0){
        printf("Underflow");
        return;
    }
    st->top--;
    st->size--;
}

int peek(struct stack*st){
    if(st->top==-1){
        return;
    }
    return st->arr[st->top];
}

void printStack(struct stack* st){
    if(st->size==0){
        printf("Underflow");
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
    push(st,4);
    push(st,5);
    // pop(st);
    // pop(st);
    printStack(st);
}