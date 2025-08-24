#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* next,*prev;
};

struct node* createNode(int val){
    struct node* temp=(struct node*)malloc(sizeof(struct node));
    temp->data=val;
    temp->next=NULL;
    temp->prev=NULL;
    return temp;
}

void insertAtBegin(struct node**head,struct node**tail,int val){
    if(*head==NULL){
            *head=*tail=createNode(val);
            return;
    }

    struct node*newNode=createNode(val);
    newNode->next=*head;
    (*head)->prev=newNode;
    *head=newNode;
}

void insertAtEnd(struct node**head,struct node**tail,int val){
    if(*head==NULL){
        *head=*tail=createNode(val);
        return;
    }
    struct node*newNode=createNode(val);
    struct node*temp=*tail;
    temp->next=newNode;
    newNode->prev=temp; 
   *tail=newNode;
}

void printList(struct node**head,struct node**tail){
if(*head==NULL){
    return;
}
struct node*temp=*head;
while(temp){
    printf("%d ",temp->data);
    temp=temp->next;
}
}

void insertAfterK(struct node**head,struct node**tail,int k,int val){
    if(*head==NULL){
        *head=*tail=createNode(val);
        return;
    }
    struct node*newNode=createNode(val);
    struct node*temp=*head;
    while(temp->next){
        if(temp->data==k){
                newNode->next=temp->next;
                temp->next->prev=newNode;
                temp->next=newNode;
                newNode->prev=temp;
                
                return;
        }else{
            temp=temp->next;
        }
    }
    if(temp->next==NULL && temp->data==k){
        temp->next=newNode;
        newNode->prev=temp;
        *tail=newNode;
        return;
    }
    insertAtEnd(head,tail,val);
}

void insertBeforeK(struct node**head,struct node**tail,int k,int val){
    if(*head==NULL){
        *head=*tail=createNode(val);
        return;
    }
    struct node*newNode=createNode(val);
    struct node*temp=*head;
    // struct node* temp2=NULL;
    if(temp->data==k){
        newNode->next=temp;
        temp->prev=newNode;
        *head=newNode;
        return;
    }
    while(temp){
        if(temp->data==k){
            newNode->next=temp;
            // temp2->next=newNode;
            // newNode->prev=temp2;
            // temp->prev=newNode;
            newNode->prev=temp->prev;
            temp->prev->next=newNode;
            temp->prev=newNode;
            return;
        }else{
            // temp2=temp;
            temp=temp->next;
        }
    }
insertAtEnd(head,tail,val);
}

// void insertAtK(struct node**head,struct node**tail,int k,int val){
// if(*head==NULL){
//     *head=*tail=createNode(val);
//     return;
// }
// struct node*newNode=createNode(val);
// struct node*temp=*head;

// if(k==0){
//     newNode->next=temp;
//     temp->prev=newNode;
//     *head=newNode;
//     return;
// }
// while(k-1){
//     k--;
//     temp=temp->next;
// }
// if(temp->next){
//     temp->next=newNode;
//     newNode->prev=temp;
//     *tail=newNode;
//     return;
// }
// newNode->next=temp;
// newNode->prev=temp->prev;
// (temp->prev)->next=newNode;
// temp->prev=newNode;
// // insertBeforeK(head,tail,k,val);
// }

void deleteFromEnd(struct node** head, struct node** tail) {
    if (*head == NULL) {  // case 1: empty list
        return;
    }

    struct node* temp = *tail;

    if (*head == *tail) {  
        // case 2: only one node
        *head = *tail = NULL;
    } else {  
        // case 3: more than one node
        *tail = (*tail)->prev;
        (*tail)->next = NULL;
    }

    free(temp);
}

void deleteFromBegin(struct node**head,struct node**tail){
    if(*head==NULL){
        return;
    }
    struct node*temp=*head;
    if(*head==*tail){
        *head=*tail=NULL;
        free(temp);
    }
    *head=(*head)->next;
    (*head)->prev=NULL;
    free(temp);
}

void insertAtK(struct node**head,struct node**tail,int k,int val){
    if(*head==NULL){
        return;
    }
    int c=0;
    struct node*temp=*head;
    struct node*newNode=createNode(val);
    while(c!=k){
        temp=temp->next;
        if(temp->next==NULL){
            temp->next=newNode;
        newNode->prev=temp;
        *tail=newNode;
        return;
        }
        c++;
    }
    if(k==0){
        newNode->next=temp;
        temp->prev=newNode;
        *head=newNode;
        return;
    }
    newNode->next=temp;
    newNode->prev=temp->prev;
    temp->prev->next=newNode;
    temp->prev=newNode;

}

void deleteAtK(struct node**head,struct node**tail,int k){
    if(*head==NULL){
        return; // empty
    }
    struct node*temp=*head;
    int c=0;
    
    // case 1: delete head
    if(k==0){
        *head=temp->next;
        if(*head!=NULL){
            (*head)->prev=NULL;
        } else {
            *tail=NULL; // list became empty
        }
        free(temp);
        return;
    }

    // move to kth node
    while(temp!=NULL && c<k){
        temp=temp->next;
        c++;
    }

    if(temp==NULL){  // k out of range
        return;
    }

    // case 2: delete tail
    if(temp->next==NULL){
        *tail=temp->prev;
        (*tail)->next=NULL;
        free(temp);
        return;
    }

    // case 3: delete middle node
    temp->prev->next=temp->next;
    temp->next->prev=temp->prev;
    free(temp);
}

int main(){
    struct node*head=NULL;
    struct node*tail=NULL;
    insertAtBegin(&head,&tail,10);
    insertAtBegin(&head,&tail,20);
    insertAtBegin(&head,&tail,30);
    insertAtEnd(&head,&tail,40);
    insertAtEnd(&head,&tail,50);
    insertAfterK(&head,&tail,40,60);
    insertBeforeK(&head,&tail,30,70);
    // insertAtK(&head,&tail,2,999);
    // deleteFromEnd(&head,&tail);
    deleteFromBegin(&head,&tail);
    insertAtK(&head,&tail,6,888);
    deleteAtK(&head,&tail,6);
    printList(&head,&tail);
}