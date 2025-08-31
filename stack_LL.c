#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* next;
};
struct stack{
    struct node* top;
};

struct node* createNode(int val){
    struct node* newNode=(struct node*)malloc(sizeof(struct node));
    newNode->data=val;
    newNode->next=NULL;
    return newNode;
}

void push(struct stack*st,int val){
    if(st->top==NULL){
        st->top=createNode(val);
        return;
    }
    struct node* newNode=createNode(val);
    newNode->next=st->top;
    st->top=newNode;
}

void pop(struct stack*st){
    if(st->top==NULL){
        return;
    }
    struct node* temp=st->top;
    st->top=st->top->next;
    free(temp);
}

void display(struct stack*st){
    if(st->top==NULL){
        return;
    }
    struct node* temp=st->top;
    while(temp){
        printf("%d ",temp->data);
        temp=temp->next;
    }
}

int main(){
    struct stack* st=(struct stack*)malloc(sizeof(struct stack));
    st->top=NULL;
    push(st,1);
    push(st,2);
    push(st,3);
    push(st,4);
    push(st,5);
    pop(st);
    display(st);
}