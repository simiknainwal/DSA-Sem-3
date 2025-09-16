//***** Linked List ***** */
#include<stdio.h>
#include<stdlib.h>
struct Node{
     int data;
     struct Node* next;
};


struct Node *createNode(int val){
    struct Node *temp=(struct Node*) malloc(sizeof(struct Node));

    temp->data=val;
    temp->next=NULL;
    return temp;
}

void insertAtBegin(struct Node **head, int val){
    if(*head==NULL){
        *head= createNode(val);
        return;
    }
    struct Node* temp=createNode(val);
    temp->next=*head;
    *head=temp;
    return;
}

void insertAtEnd(struct Node**head,int val){
    struct Node *temp=createNode(val);
    if(*head==NULL){
        *head=createNode(val);
        return;
    }
    struct Node*temp2=*head;
    while(temp2->next!=NULL){
        temp2=temp2->next;
    }
    temp2->next=temp;
}

void deleteFromBegin(struct Node**head){
if(*head==NULL){
    return;
}
struct Node*temp=*head;
*head=(*head)->next;
free(temp);
}

void deleteAtEnd(struct Node**head){
    if(*head==NULL){
        return;
    }
    struct Node*temp=*head;
    struct Node*temp2;
    while(temp->next!=NULL){
        temp2=temp;
        temp=temp->next;
    }
    temp2->next=NULL;
}

void insertAfterK(struct Node**head,int k,int val){
    struct Node *temp1=*head;
    // struct Node*temp2=NULL;
    struct Node*newNode=createNode(val);
if(*head==NULL){
    *head=createNode(val);
    return;
}

    while(temp1->data!=k){
        if(temp1->next==NULL){
            temp1->next=newNode;
            // newNode->next=NULL;
            return;
        }
            temp1=temp1->next;
}
newNode->next=temp1->next;
temp1->next=newNode;
return;

}

void insertBeforeK(struct Node**head,int k,int val){
    struct Node*temp=*head;
    struct Node*temp2=*head;
    struct Node *newNode=createNode(val);
    if(*head==NULL){
        printf("Empty list");
        return;
    }while(temp!=NULL){
        if(temp->data==k){
            if(temp2==*head){
                newNode->next=temp;
            *head=newNode;
            return;
            
            }else{
            newNode->next=temp;
            temp2->next=newNode;
            return;
        }
    }
        temp2=temp;
    temp=temp->next;
    }
    newNode->next=*head;
    *head=newNode;
}
void DeleteK(struct Node**head,int k){
    struct Node* temp=*head;
    struct Node*temp2=NULL;
    if(*head==NULL){
        printf("Empty List");
        return;
    }
    while(temp!=NULL){
if(temp->data==k){
    if(temp==*head){
        temp2=temp;
        temp=temp->next;
        *head=temp;
        free(temp2);
        return;
    }else{
        
temp2->next=temp->next;
free(temp);
return;
}
}
temp2=temp;
temp=temp->next;
}
}

void deleteAtMultipleOfK(struct Node**head, int k){
    if(*head==NULL){
        return;
    }int c=0,i=0;
    printf("Enter value of K:");
    scanf("%d",&k);
    struct Node* temp=*head;
    struct Node* temp2=*head;
    // while(temp){
    //     c++;
    //     temp=temp->next;
    // }
    while(temp && temp->next){
        if(k%i==0){
            struct Node* t=temp;
            temp2->next=temp->next;
            free(t);
        }
        temp2=temp->next;
        temp=temp->next->next;
i++;
    }
}

void printList(struct Node**head){
    struct Node* temp=*head;
    if(*head==NULL){
        printf("Empty list");
        return;
    }
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp=temp->next;
    }
}


int main(){
    int c=1;
    struct Node *head=NULL;
    insertAtBegin(&head,5);
    insertAtBegin(&head,4);
    insertAtBegin(&head,3);
    insertAtBegin(&head,2);
    insertAtBegin(&head,1);
    deleteAtMultipleOfK(&head,2);
    // insertAtEnd(&head,78);
    // deleteFromBegin(&head);
    // insertAfterK(&head,5,999);
    // insertBeforeK(&head,99,888);
    // DeleteK(&head,888);
    // // printList(&head);
    // while(c){
    //     int ch;
    //     printf("Enter choice:");
    //     scanf("%d",&ch);
    //     switch(ch){
    //         case 1:insertAtBegin(&head,2);  
    //                         break;
    //         case 2:printList(&head);
    //         break;                
    //         case 3:printf("End\n");c=0;
    //         break;                
    //     }
    // }
    printList(&head);
}
