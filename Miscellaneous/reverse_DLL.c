#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* next,*prev;
};

struct node* createNode(int val){
    struct node* newNode=(struct node*)malloc(sizeof(struct node));
    newNode->data=val;
    newNode->next=NULL;
    newNode->prev=NULL;
    return newNode;
}


struct node* insertAtEnd(struct node* head,int val){
    struct node* newNode=createNode(val);
    if(head==NULL){
        return newNode;
    }
    struct node* temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=newNode;
    newNode->prev=temp;
    return head;
}

struct node* reverse(struct node* head){
    if(head==NULL || head->next==NULL){
        return head;
    }
    struct node* last=NULL;
    struct node* curr=head;
    while(curr){
        curr->prev=curr->next;
        curr->next=last;
        last=curr;
        curr=curr->prev;
    }
    return last;
}

struct node* oddeven(struct node*head){
    if(head==NULL){
        return head;
    }
    struct node* head2=head->next;
    struct node* prv1=NULL;
    struct node* prv2=NULL;
    struct node* t2=head->next;
    struct node* t1=head;
    while(t2 && t2->next){
        t1->next=t2->next;
        t1->prev=prv1;
        prv1=t1;
        t1=t1->next;
        t2->next=t1->next;
        t2->prev=prv2;
        prv2=t2;
        t2=t2->next;
    }
    t1->next=head2;
    head2->prev=t1;
    return head;
}

struct node* evenodd(struct node*head){
    if(head==NULL){
        return head;
    }
    // struct node* 
}

void display(struct node* head){
    if(head==NULL){
        return;
    }
    struct node* temp=head;
    while(temp){
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("\n");
}

int main(){
    struct node* head=NULL;
    head=insertAtEnd(head,13);
    head=insertAtEnd(head,25);
    head=insertAtEnd(head,34);
    head=insertAtEnd(head,49);
    head=insertAtEnd(head,51);
    // display(head);
    // printf("\n");
    // head=reverse(head);
    head=oddeven(head);
    display(head);
    return 0;
}