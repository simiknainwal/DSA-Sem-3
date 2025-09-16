// // #include<stdio.h>
// // #include<stdlib.h>

// // struct queue{
// //     int*arr;
// //     int front,rear,cap,size;
// // };

// // struct queue* initialize(int val){
// //     struct queue* temp=(struct queue*)malloc(sizeof(struct queue));
// //     temp->arr=(int*)malloc(sizeof(int)*val);
// //     temp->front=-1;
// //     temp->rear=-1;
// //     temp->cap=val;
// //     temp->size=0;
// //     return temp;
// // }

// // int isFull(struct queue*q){
// //     if(q->size==(q->cap)){
// //         return 1;
// //     }
// //     return 0;
// // }

// // int isEmpty(struct queue*q){
// //     if(q->size==0){
// //         return 1;
// //     }
// //     return 0;

// // }

// // void enqueue(struct queue*q,int val){
// //     if(isFull(q)){
// // return;
// //     }
// //     if(q->front==-1){
// //         q->front=0;
// //     }
// //     q->rear=(q->rear+1)%q->cap;
// //     q->arr[q->rear]=val;
// //     q->size++;
// // }

// // void dequeue(struct queue*q){
// //     if(isEmpty(q)){
// //         return;
// //     }if(q->size==1){
// //         q->front=q->rear=-1;
// //     }else{
// //     q->front=(q->front+1)%q->cap;
// //     }q->size--;
// // }

// // int front(struct queue*q){
// //     if(isEmpty(q)){
// //         return -1;
// //     }
// //     return q->arr[q->front];
// // }

// // void printQueue(struct queue*q){
// //     if(isEmpty(q)){
// // return;
// //     }
// // // struct queue* temp=q->front;
// // int count=q->size;
// // int i=q->front;
// // while(count--){
// //     printf("%d ",q->arr[i]);
// //     i=(i+1)%q->cap;
// // }
// // }

// // int main(){
// //     struct queue* q=initialize(100);
// //     enqueue(q,10);
// //     enqueue(q,20);
// //     enqueue(q,30);
// //     dequeue(q);
// //     printQueue(q);
// //     printf("\n%d",front(q));
// // }

// #include<stdio.h>
// #include<stdlib.h>

// struct queue{
//     int * arr;
//     int front,rear,size,cap;
// };

// struct queue* initialize(int val){
// struct queue* q=(struct queue*)malloc(sizeof(struct queue));
// q->arr=(int*)malloc(sizeof(int)*val);
// q->front=q->rear=-1;
// q->cap=val;
// q->size=0;
// return q;
// }

// int isFull(struct queue* q){
//     return (q->rear+1)%q->cap == q->front;
// }
// int isEmpty(struct queue* q){
//     return q->size==0;
// }

// void enqueue(struct queue*q,int val){
//     if(isFull(q)){
//         return;
//     }
//     if(q->front==-1){
//         q->front=0;
//         // q->rear=0;
//     }
//     q->rear=(q->rear+1)%q->cap;
//     q->arr[q->rear]=val;
//     q->size++;

// }

// void dequeue(struct queue* q){
//     if(isEmpty(q)){
//         return;
//     }

//     q->front=(q->front+1)%q->cap;
//     q->size--;
//     if(q->size==0){
//         q->front=q->rear=-1;
//     }
// }

// void printQueue(struct queue* q){
//     if(isEmpty(q)){
//         return;
//     }
//     int count=q->size;
//     int i=q->front;
//     while(count--){
//         printf("%d ",q->arr[i]);
//         i=(i+1)%q->cap;
//     }
// }

// int main(){
//     struct queue* q=initialize(100);
//     enqueue(q,1);
//     enqueue(q,2);
//     enqueue(q,3);
//     enqueue(q,4);
//     enqueue(q,5);
//     printQueue(q);
// }


#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node*next;
};

struct queue{
    struct node* front,* rear;
    int cap,size;
};

struct node* createNode(int val){
    struct node* newNode=(struct node*)malloc(sizeof(struct node));
    newNode->data=val;
    newNode->next=NULL;
    return newNode;
}

struct queue* initialize(int val){
    struct queue* q=(struct queue*)malloc(sizeof(struct queue));
    q->rear=q->front=NULL;
    q->cap=val;
    q->size=0;
    return q;
}

int isFull(struct queue*q){
    return q->size==q->cap;
}
int isEmpty(struct queue*q){
    return q->size==0;// q->rear==NULL
}

void enqueue(struct queue*q,int val){
    if(isFull(q)){
        return;
    }
    struct node* newNode=createNode(val);
    struct node* temp=q->rear;
    if(q->front==NULL && q->rear==NULL){
        q->rear=q->front=newNode;
    }else{
    q->rear->next=newNode;
    q->rear=newNode;
    }
    q->size++;
}

void dequeue(struct queue*q){
    if(isEmpty(q)){
        return;
    }
    struct node* temp=q->front;
    // struct node* temp2=q->rear;
    q->front=q->front->next;
    q->size--;
    free(temp);

}

void printQueue(struct queue*q){
    if(isEmpty(q)){
        return;
    }

    struct node* temp=q->front;
    while(temp){
        printf("%d ",temp->data);
        temp=temp->next;
    }
}

int main(){
    struct queue*q=initialize(100);
    enqueue(q,1);
    enqueue(q,2);
    enqueue(q,3);
    enqueue(q,4);
    // dequeue(q);
    printQueue(q);
}