#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* next;
};

struct graph{
    int nv;
    struct node** al;
};

struct node* createNode(int vertex){
    struct node* temp=(struct node*)malloc(sizeof(struct node));
    temp->data=vertex;
    temp->next=NULL;
    return temp;
}

struct graph* createGraph(int v){
    struct graph* g=(struct graph*)malloc(sizeof(struct graph));
    g->nv=v;
    g->al=(struct node**)malloc(sizeof(struct node*)*v);
    for(int i=0;i<g->nv;i++){
        g->al[i]=NULL;
    }
    return g;
}

void add(struct graph* g,int src,int dest){
struct node* t=createNode(dest);
t->next=g->al[src];
g->al[src]=t;

struct node* temp=createNode(src);
temp->next=g->al[dest];
g->al[dest]=temp;
}

void display(struct graph* g){
for(int i=0;i<g->nv;i++){
    struct node* temp=g->al[i];
    printf("Vertex %d:",i);
    while(temp){
        printf("%d->",temp->data);
        temp=temp->next;
    }
    printf("NULL\n");
}
}

int main(){
    struct graph* graph=createGraph(5);
    add(graph, 0, 1);
    add(graph, 0, 4);
    add(graph, 1, 2);
    add(graph, 1, 3);
    add(graph, 1, 4);
    add(graph, 2, 3);
    add(graph, 3, 4);
    display(graph);
}

