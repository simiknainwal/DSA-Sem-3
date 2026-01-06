#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* next;
};

struct node* createNode(int val){
    struct node* newNode=(struct node*)malloc(sizeof(struct node));
    newNode->data=val;
    newNode->next=NULL;
    return newNode;
}

struct node* insertAtBegin(struct node* head,int val){
    if(head==NULL){
        head=createNode(val);
        return head;
    }
    struct node* newNode=createNode(val);
    newNode->next=head;
    head=newNode;
    return head;
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
}

struct node* middle(struct node* head){
    if(head==NULL || head->next==NULL){
        return head;
    }
    struct node* slow=head;
    struct node* fast=head;
    while(fast && fast->next){
        slow=slow->next;
        fast=fast->next->next;
    }
    printf("%d\n",slow->data);
}

struct node* reverse(struct node* head){
    if(head==NULL || head->next==NULL){
        return head;
    }
    struct node* curr=head;
    struct node* nxt=head;
    struct node* prev=NULL;
    while(curr){
        nxt=curr->next;
        curr->next=prev;
        prev=curr;
        curr=nxt;
    }
    return prev;
}

struct node* oddeven(struct node*head){
    if(head==NULL || head->next==NULL){
        return head;
    }
        struct node* t1=head;
        struct node* t2=head->next;
        struct node* head2=head->next;
        while(t2 && t2->next){
            t1->next=t2->next;
            t1=t2->next;
            t2->next=t1->next;
            t2=t1->next;
        }
        t2->next=head;
        t1->next=NULL;
        return head2;
    }

    struct node* evenodd_values(struct node* head){
        if(head==NULL){
            return head;
        }
        struct node* temp=head;
        struct node* t1=createNode(-1);
        struct node* dNode1=t1;
        struct node* t2=createNode(-1);
        struct node* dNode2=t2;
        while(temp){
            if((temp->data)%2==0){
                t1->next=temp;
                t1=t1->next;
            }else{
            t2->next=temp;
            t2=t2->next;
            }
            temp=temp->next;
        }
        t2->next=NULL;
        t1->next=dNode2->next;
        return dNode1->next;
    }


int main(){
    struct node* head=NULL;
    head=insertAtBegin(head,1);
    head=insertAtBegin(head,2);
    head=insertAtBegin(head,3);
    head=insertAtBegin(head,4);
    head=insertAtBegin(head,5);
    head=insertAtBegin(head,6);
    // middle(head);
    // head=reverse(head);
    // head=oddeven(head);
    // head=evenodd_values(head);
    display(head);
}