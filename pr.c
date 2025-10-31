#include<stdio.h>
#include<stdlib.h>

struct queue{
    int* arr;
    int front,rear,size,cap;
};

struct queue* initialize(int size){
    struct queue* q=(struct queue*)malloc(sizeof(struct queue));
    q->arr=(int*)malloc(sizeof(int)*size);
    q->front=q->rear=-1;
    q->size=0;
    q->cap=size;
    return q;
}

int isEmpty(struct queue* q){
    return q->size==0;
}

int isFull(struct queue* q){
    return (q->rear+1)%q->cap==q->front;
}

void enqueue(struct queue* q,int val){
    if(isFull(q)){
        return ;
    }
    if(q->front==-1){
        q->front=q->rear=0;
    }else{

        q->rear=(q->rear+1)%q->cap;
    }
    q->arr[q->rear]=val;
    q->size++;
}

int dequeue(struct queue* q){
    if(isEmpty(q)){
        return -1;
    }

    int val=q->arr[q->front];
    q->size--;
    if(q->size==0){
        q->front=q->rear=-1;
    }else{
        q->front=(q->front+1)%q->cap;
        
    }
    return val; 
}

void bfs(int start,int end,int n,int adjm[][7]){
    struct queue*q=initialize(100);
    int visited[50]={0};
    visited[start]=1;
    printf("%d ",start);
    enqueue(q,start);
    while(!isEmpty(q)){
        int node=dequeue(q);
        for(int j=0;j<n;j++){
            if(adjm[node][j]==1 && visited[j]==0){
                printf("%d ",j);
                visited[j]=1;
                enqueue(q,j);
            }
        }
    }
}

void printQueue(struct queue* q){
    if(isEmpty(q)){
        return;
    }
    int i=q->front;
    int count=q->size;
    while(count--){
        printf("%d ",q->arr[i]);
        i=(i+1)%q->cap;
    }
}

int main(){
    struct queue* q=initialize(100);
    // enqueue(q,1);
    // enqueue(q,2);
    // enqueue(q,3);
    // enqueue(q,4);
    // enqueue(q,5);
    // dequeue(q);
    // dequeue(q);
    // dequeue(q);
    // dequeue(q);
    // dequeue(q);
    // enqueue(q,9999);
    // enqueue(q,9998);
    // printQueue(q);


    //BFS implementation

// int u,i=0,visited[7]={0};
// //Adjacency Matrix=>representing a graph
// int a[7][7]={
//     {0,1,1,1,0,0,0},
//     {1,0,1,0,0,0,0},
//     {1,1,0,1,1,0,0},
//     {1,0,1,0,1,0,0},
//     {0,0,1,1,0,1,1},
//     {0,0,0,0,1,0,0},
//     {0,0,0,0,1,0,0}
// };
// printf("%d ",i);
// visited[i]=1;
// enqueue(q,i); // For exploration
// while(!isEmpty(q)){

//     int node=dequeue(q);
//     for(int j=0;j<7;j++){
//         if(a[node][j]==1 && visited[j]==0){
//             printf("%d ",j);
//             visited[j]=1;
//             enqueue(q,j);
//         }
//     }
// }

int adjm[7][7]={
    {0,1,1,1,0,0,0},
    {1,0,1,0,0,0,0},
    {1,1,0,1,1,0,0},
    {1,0,1,0,1,0,0},
    {0,0,1,1,0,1,1},
    {0,0,0,0,1,0,0},
    {0,0,0,0,1,0,0}
};
bfs(0,6,7,adjm);
// printQueue(q);
} 