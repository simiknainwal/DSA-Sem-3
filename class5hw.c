#include<stdio.h>
#include<stdlib.h>

struct que{
    int *arr;
    int start,end,cap;
};

struct que* initialize(int size){
    struct que* temp=(struct que*)malloc(sizeof(struct que));
    temp->arr=(int*)malloc(sizeof(int));
    temp->start=-1;
    temp->end=-1;
    temp->cap=size;
    return temp;
}

struct que* push(struct que* q,int val){
    if(q->end==(q->cap)-1){
        printf("Queue full");
        return q;
    }
    if(q->start==-1){
        q->start=0;
    }
    q->end=(q->end+1)%q->cap;
    q->arr[q->end]=val;
    return q;
}

void main(){
    struct que *q=initialize(100);
    q=push(q,10);
    q=push(q,20);

    printf("%d ",q->arr[q->end--]);
    printf("%d ",q->arr[q->end]);
}