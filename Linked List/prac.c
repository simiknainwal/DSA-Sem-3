#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* next;
};

struct node* createNode(int val){
    struct node* temp=(struct node*)malloc(sizeof(struct node));
    temp->data=val;
    temp->next=NULL;
    return temp;
}

struct node* insertAtEnd(struct node* head,int val){
    if(head==NULL){
        head=createNode(val);
        return head;
    }
    struct node* newNode=createNode(val);
    struct node* t=head;
    while(t->next){
        t=t->next;
    }
    t->next=newNode;
    return head;
}

struct node* middle(struct node*head){
    if(head==NULL || head->next==NULL){
        return head;
    }
    struct node* slow=head;
    struct node* fast=head;
    while(fast && fast->next){
        slow=slow->next;
        fast=fast->next->next;
    }
    return slow;
}

struct node* oddeven(struct node*head){
    if(head==NULL){
        return head;
    }
    struct node* t1=head;
    struct node* t2=head->next;
    struct node* t3=head->next;
    while(t2 && t2->next){
        t1->next=t2->next;
        t1=t2->next;
        t2->next=t1->next;
        t2=t1->next;
    }
    t1->next=t3;
    return head;
}

struct node* delete(struct node*head,int n){
    if(head==NULL){
        return head;
    }
    struct node* temp=head;
    int l=0;
    while(temp){
        temp=temp->next;
        l++;
    }
    if(n>l)return head;
    int d=l-n;
    if(d==0){
        head=head->next;
        return head;
    }
    temp=head;
    struct node* prev=NULL;
    while(d--){
        prev=temp;
        temp=temp->next;
    }
    // struct node* dNode=temp->next;
    // temp->next=dNode->next;
    prev->next=temp->next;
    free(temp);
    return head;
}



void display(struct node*head){
    if(head==NULL){
        return;
    }
    struct node* temp=head;
    while(temp){
        printf("%d ",temp->data);
        temp=temp->next;
    }
}

int main(){
    struct node* head=NULL;
    head=insertAtEnd(head,10);
    head=insertAtEnd(head,20);
    head=insertAtEnd(head,30);
    head=insertAtEnd(head,40);
    head=insertAtEnd(head,50);
    // head=middle(head);
    // head=oddeven(head);
    head=delete(head,5);
    display(head);
}