//Stack implementation
#include<stdio.h>
#include<stdlib.h>
struct Stack{
    int *arr;
    int top,cap;
};

struct Stack* initialize(int size){
    struct Stack* temp=(struct Stack*) malloc((sizeof(struct Stack)));
    temp->top=-1;
    temp->cap=size;
    temp->arr=(int*)malloc(sizeof(int)*size);
return temp;
}

void push(struct Stack* st,int val){
    if(st->top == (st->cap)-1){
        printf("Stack overflow");
        return;
    }
    st->top++;
    st->arr[st->top]=val;
}
void pop(struct Stack*st){
    if(st->top==-1){
        printf("Stack underflow");
    return;
    }

    st->top--;
}

int top(struct Stack*st){
    if(st->top==-1){
        printf("Stack underflow");
        return;
    }
return st->arr[st->top];
}
void printStack(struct Stack*st){
    if(st->top==(st->cap)-1){
        printf("Stack overflow");
    return 0;
    }
    for(int i=0;i<=st->top;i++){
        printf("%d ",*((st->arr)+i));
        // st->top++;
    }
}
void main(){
    struct Stack* s=initialize(100);
push(s,999);
push(s,998);
push(s,997);
pop(s);
printStack(s);
printf("\n%d",top(s));
}