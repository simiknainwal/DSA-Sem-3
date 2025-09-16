//stack implementation using LL
#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node* next;
}node;

void push(node **top,int val){
    node* newNode=(node*)malloc(sizeof(node));
    newNode->data=val;
    newNode->next=*top;
    *top=newNode;
}

void pop(node**top){
    if(*top==NULL){
        printf("Stack underflow");
        return;
    }
    node*temp =*top;
    *top=(*top)->next;
    free(temp);
}

void topd(node*top){
    if(top==NULL){
        printf("Stack underflow");
        return;
    }
    printf("%d \n",top->data);
}

void main(){
    node*top=NULL;
    push(&top,999);
    push(&top,998);
    push(&top,997);
    // pop(&top);
    topd(top);
    node*temp=top;//Use temp variable so that you can access the original stack many times. 
while(temp){
    printf("%d ",temp->data);
    temp=temp->next;
}
}
