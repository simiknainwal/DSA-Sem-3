#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node*next;
};

struct node* createNode(int val){
    struct node* newNode=(struct node*)malloc(sizeof(struct node));
    newNode->data=val;
    newNode->next=NULL;
    return newNode;
}

struct node* insertAtEnd(struct node* head,int val){
    if(head==NULL){
        head=createNode(val);
        return head;
    }
    struct node* temp=head;
    struct node* newNode=createNode(val);
    while(temp->next){
        temp=temp->next;
    }
    temp->next=newNode;
    return head;
}

struct node* reverse(struct node*head){
    if(head==NULL || head->next==NULL){
        return head;
    }
    struct node* cur=head;
    struct node* nxt=NULL;
    struct node* prev=NULL;
    while(cur){
        nxt=cur->next;
        cur->next=prev;
        prev=cur;
        cur=nxt;
    }
    head=prev;
    return head;
}

struct node* reverseRecursion(struct node*head){
    if(head==NULL || (head)->next==NULL){
        return head;
    }
    struct node* newHead=reverseRecursion((head)->next);
    struct node* front=(head)->next;
    front->next=head;
    head->next=NULL;
    return newHead;
}

void printList(struct node**head){
    if(*head==NULL){
        return;
    }
    struct node* temp=*head;
    while(temp){
        printf("%d ",temp->data);
        temp=temp->next;
    }
}

int main(){
    struct node* head=NULL;
    head=insertAtEnd(head,1);
    head=insertAtEnd(head,2);
    head=insertAtEnd(head,3);
    printList(&head);
    printf("\n");
    head=reverseRecursion(head);
    printList(&head);
}

