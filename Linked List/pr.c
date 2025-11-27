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

struct node* insertAtEnd(struct node*head,int val){
if(head==NULL){
    head=createNode(val);
    return head;
}
struct node* newNode=createNode(val);
struct node* temp=head;
while(temp->next){
    temp=temp->next;
}
temp->next=newNode;
return head;
}

struct node* middle(struct node*head){
    if(head==NULL || head->next==NULL){
        return head;
    }
    struct node* fast=head;
    struct node* slow=head;

    while(fast && fast->next){
        slow=slow->next;
        fast=fast->next->next;
    }
    return slow;
}

struct node* reverse(struct node*head){
    if(head==NULL){
        return head;
    }
    struct node* cur=head;
    struct node* nxt=head;
    struct node* prev=NULL;

    while(cur){
        nxt=cur->next;
        cur->next=prev;
        prev=cur;
        cur=nxt;
    }
    return prev;
}

struct node* oddeven(struct node*head){
    if(head==NULL){
        return head;
    }
    struct node* t1=head;
    struct node* t2=head->next;
    struct node* prev=head->next;

    while(t2 && t2->next){
        t1->next=t2->next;
        t1=t1->next;
        t2->next=t1->next;
        t2=t2->next;
    }
    t1->next=prev;
    return head;
}

struct node* reorder(struct node*head){
    if(head==NULL || head->next==NULL){
        return head;
    }
    struct node* slow=head;
    struct node* fast=head;
    struct node* prev=head;
    struct node* temp=head;
    while(fast && fast->next){
        prev=slow;
        slow=slow->next;
        fast=fast->next->next;
    }
    if(fast){
        prev=slow;
        slow=slow->next;
    }
    prev->next=NULL;
    struct node* head2=reverse(slow);
    
    while(temp && head2){
    struct node* n1=temp->next;
    struct node* n2=head2->next;
    temp->next=head2;
    head2->next=n1;
    temp=n1;
    head2=n2;
    }
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
    // head=insertAtEnd(head,60);
    display(head);
    printf("\nMiddle element is %d\n",middle(head)->data);
    // struct node* nhead=reverse(head);
    // display(nhead);
    printf("\n");
    // struct node* head2=oddeven(head);
    struct node* head2=reorder(head);
    display(head2);
}