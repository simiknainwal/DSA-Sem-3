#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node* next;
}node;

typedef struct stack{
    struct node* top;
}stack;

void initialize(stack*s){
    s->top=NULL;
}

stack*  push(stack* s,int val){
node* newNode=(node*) malloc(sizeof(node));

newNode->data=val;
newNode->next=s->top;
s->top=newNode;
return s;
}

stack* pop(stack*s){
    if(s->top==NULL){
        return s;
    }
    node* temp=s->top;
    node* temp2=temp;
    temp=temp->next;
    s->top=temp;
    free(temp2);
    return s;
    
}

void printStack(stack*s){
    if(s->top==NULL){
        printf("Empty stack");
        return;
    }

    node* temp=s->top;
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp=temp->next;
    }
}

void main(){
    stack* s=(stack*) malloc(sizeof(stack));
    initialize(s);
    s=push(s,10);
    s=push(s,20);
    s=push(s,30);
    printStack(s);
}