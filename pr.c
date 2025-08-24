#include<stdio.h>
#include<stdlib.h>
// struct Node{
//     int data;
//     struct Node* next;
// };

// struct Node * createNode(int val){
//     struct Node*temp=(struct Node*)malloc(sizeof(struct Node));
//     temp->data=val;
//     temp->next=NULL;
//     return temp;
// }

// void insertAtBegin(struct Node**head,int val){
//     if(*head==NULL){
//         *head=createNode(val);
//         return;
//     }
//     struct Node* temp=*head;
//     temp->next=*head;
//     *head=temp;
// }

// struct Stack{
//     int *arr;
//     int top;
//     int cap;
// };

// struct Stack * initialize(int size){
//     struct Stack*temp=(struct Stack*)malloc(sizeof(struct Stack));
//     temp->top=-1;
//     temp->cap=size;
//     temp->arr=(int*)malloc(sizeof(int)*size);
//     return temp;
// }
// void push(struct Stack*st,int val){
//     if(st->top==(st->cap)-1){
//         printf("Stack Overflow");
//         return;
//     }
//     st->top++;
//     st->arr[st->top]=val;
// }
// void pop(struct Stack*st){
//     if(st->top==-1){
//         printf("Stack underflow\n");
//         return ;
//     }
//     printf("Value popped is %d\n",st->arr[st->top]);
//     st->top--;

// }
// struct Node{
//     int data;
//     struct Node*next;
// };

// void push(struct Node**top,int val){
//     // if(*top==NULL){
//     //     printf("Stack underflow");
//     //     return;
//     // }
//     struct Node*newNode=(struct Node*)malloc(sizeof(struct Node));
// newNode->data=val;
// newNode->next=*top;
// *top=newNode;
// }

// void pop(struct Node**top){
//     if(*top==NULL){
// printf("Stack UnderFlow");
// return;
//     }
//     struct Node*temp=*top;
//     *top=(*top)->next;
//     free(temp);
// }

// struct queue{
//     int *arr;
//     int start,end,cursize,cap;
// };

// struct queue* initialize(int size){
//     struct queue* temp=(struct queue*)malloc(sizeof(struct queue));
//     temp->arr=(int*)malloc(sizeof(int)*size);
//     temp->start=-1;
//     temp->end=-1;
//     temp->cursize=0;
//     temp->cap=size;
//     return temp;
// }

// struct queue* push(struct queue*q,int val){
// //     if(q->end==(q->cap)-1){
// //             q->end=((q->end)+1)%(q->cap);
// //             q->arr[q->end]=val;
// //             return q;
// //     }
// if(q->cursize==(q->cap)){
//     printf("Queue full");
//     return q;
// }
//     if(q->start==-1){
//     q->start=0;
// }
//     q->end++;
//     q->arr[q->end]=val;
//     q->cursize++;
//     return q;
// }


// void main(){
//     // struct Node*head=NULL;
//     // insertAtBegin(&head,55);
//     // printf("%d ",head->data);
// // struct Stack*s=initialize(100);;
// // push(s,66);
// // push(s,68);
// // push(s,65);
// // pop(s);
// // // pop(s);
// // while(s->top!=-1){
// // printf("%d ",s->arr[s->top]);
// // s->top--;
// // }
// // struct Node* top=NULL;
// // push(&top,999);
// // push(&top,998);
// // push(&top,997);
// // pop(&top);
// // struct Node* temp=top;
// // while(temp){
// // printf("%d ",temp->data);
// // temp=temp->next;
// // }

// struct queue*Q=initialize(100);
// Q=push(Q,999);
// printf("%d ",Q->arr[Q->end]);
// }


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

void insertAtBegin(struct node**head,int val){
    if(*head==NULL){
        *head=createNode(val);
        return;
    }
    struct node*newNode=createNode(val);
    newNode->next=*head;
    *head=newNode;
}

struct node* reverse(struct node*head){
    if(head==NULL || head->next==NULL){
        return head;
    }
    struct node* newHead=reverse(head->next);
    struct node* front=head->next;
    front->next=head;
    head->next=NULL;
    return newHead;
}

void printList(struct node** head){
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
    insertAtBegin(&head,10);
    insertAtBegin(&head,20);
    insertAtBegin(&head,30);
    insertAtBegin(&head,40);
    printf("List before reversing: ");
    printList(&head);
    head=reverse(head);
    printf("\nList after reversing: ");
    printList(&head);
}