#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node*next;
};

struct node* createNode(int val){
    struct node* temp=(struct node*)malloc(sizeof(struct node));
    temp->data=val;
    temp->next=NULL;
    return temp;
}

void insertAtEnd(struct node**head,int val){
    if(*head==NULL){
        *head=createNode(val);
        return;
    }
    struct node* newNode=createNode(val);
    struct node* temp=*head;
    while(temp->next){
            temp=temp->next;
    }
    temp->next=newNode;
}

struct node* reverseRecursion(struct node*head){
    if(head==NULL || head->next==NULL){
        return head;
    }
    struct node* newHead=reverseRecursion(head->next);
    struct node* front=head->next;
    front->next=head;
    head->next=NULL;
    return newHead;
}

struct node* reverseBetween(struct node* head, int left, int right) {
    if(head==NULL || head->next==NULL || left==right){
        return head;
    }
    int p1=1,p2=1;
    struct node* temp1=head;
    struct node* temp2=head;
    struct node* prev1=NULL;
    while(p1!=left && temp1!=NULL){
        prev1=temp1;
        temp1=temp1->next;
        p1++;
    }
    while(p2!=right && temp2!=NULL){
        temp2=temp2->next;
        p2++;
    }
    if(temp1==NULL || temp2==NULL){
        return head;
    }
    struct node*next2=temp2->next;
    struct node* curr=temp1;
    struct node* nxt=NULL;
    struct node* prev=NULL;
    struct node* temp3=temp2->next;
    while(curr!=temp3){
        nxt=curr->next;
        curr->next=prev;
        prev=curr;
        curr=nxt;
    }
    if(prev1==NULL){
        head=prev1;
    }else{
            prev1->next=prev;
    }
    
    // prev->next=NULL;
    
    temp1->next=next2;
    return head;
}

void reverse(struct node**head){
    if(*head==NULL || (*head)->next==NULL){
        return;
    }
    struct node* curr=*head;
    struct node* nxt=NULL;
    struct node* prev=NULL;
    while(curr){
        nxt=curr->next;
        curr->next=prev;
        prev=curr;
        curr=nxt;
    }
    *head=prev;
    return;
}

void reverseAtMiddle(struct node**head){
    if(*head==NULL || (*head)->next==NULL){
            return;
    }
    struct node* slow=*head;
    struct node* fast=*head;
    struct node* temp=*head;
    while(fast->next && fast->next->next){
        slow=slow->next;
        fast=fast->next->next;
    }
    while(temp!=slow){
            printf("%d ",temp->data);
            temp=temp->next;
    }
    reverse(&slow);
    while(slow){
        printf("%d ",slow->data);
        slow=slow->next;
    }
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
    insertAtEnd(&head,1);
    insertAtEnd(&head,2);
    insertAtEnd(&head,3);
    insertAtEnd(&head,4);
    insertAtEnd(&head,5);
    insertAtEnd(&head,6);
    insertAtEnd(&head,7);
    insertAtEnd(&head,8);
    insertAtEnd(&head,9);
    // printList(&head);
    // reverse(&head);
    // printf("\n");
    // printList(&head);
// reverseAtMiddle(&head);
// head=reverseRecursion(head);
head=reverseBetween(head,2,6);
printList(&head);
}