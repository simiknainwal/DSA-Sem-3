#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node*next,*prev;
};
struct linkedlist{
    struct node*head,*tail;
};

struct node* createNode(int val){
    struct node* temp=(struct node*)malloc(sizeof(struct node));
    temp->data=val;
    temp->next=temp->prev=NULL;
    return temp;
}

struct linkedlist* insertAtBegin(struct linkedlist*L1,int val){
    if(L1->head==NULL){
        return L1;
    }
    struct linkedlist*temp=L1;
    struct node*newNode=createNode(val);
    newNode->next=temp->head;
    temp->head->prev=newNode;
    L1->head=newNode;
    return L1;

}

int main(){
    struct linkedlist* L=NULL;
    L=insertAtBegin(L,999);
    printf("%d ",L->head->data);
}