#include<stdio.h>
#include<stdlib.h>
// struct queue{
//     int*arr;
//     int front,rear,cap,size;
// };

// struct queue* initialize(int s){
//     struct queue* q=(struct queue*)malloc(sizeof(struct queue));
//     q->arr=(int*)malloc(sizeof(int)*s);
//     q->front=-1;
//     q->rear=-1;
//     q->cap=s;
//     q->size=0;
//     return q;
// }

// int isFull(struct queue*q){
//     return (q->rear+1)%q->cap==q->front;
// }
// int isEmpty(struct queue*q){
//     return q->size==0;
// }

// void enqueue(struct queue*q,int val){
//     if(isFull(q)){
//         return;
//     }
//     if(q->front==-1){
//         q->front=0;
//     }
//     q->rear=(q->rear+1)%q->cap;
//     q->arr[q->rear]=val;
//     q->size++;
// }

// void dequeue(struct queue*q){
//     if(isEmpty(q)){
//         return;
//     }
//     if(q->rear==q->front){
//         q->rear=-1;
//         q->front=-1;
//     }else{
//     q->front=(q->front+1)%q->cap;
//     }
//     q->size--;
// }

// void printQueue(struct queue*q){
//     if(q->rear==-1){
//         return;
//     }
//     int i=q->front;
//     while(1){
//         printf("%d ",q->arr[i]);
//         if(i==q->rear){
//             break;
//         }
//         i=(i+1)%q->cap;
//     }
// }

// int main(){
//     struct queue*q=initialize(100);
//     enqueue(q,10);
//     enqueue(q,20);
//     enqueue(q,30);
//     enqueue(q,40);
//     dequeue(q);
//     printQueue(q);
// }

struct node{
    int data;
    struct node*next;
};

struct queue{
    struct node*front,*rear;
    int size;
};

struct node* initialize(int size){
    struct queue*q=(struct queue*)malloc(sizeof(struct queue));
    q->size=0;
    q->front=q->rear=0;
    return q;
}

int isEmpty(struct queue*q){
    return q->front==NULL;
}
int isFull(struct queue*q){
    struct node*n=(struct node*)malloc(sizeof(struct node));
    if(n==NULL){
        return 1;
    }else{
        free(n);
        return 0;
    }
}

