#include<stdio.h>
#include<stdlib.h>

struct adjNode{
    int vertex;
    struct adjNode* next;
};

struct adjList{
    struct adjNode* head;
};

struct graph{
    int vertices;
    struct adjList* array;
};

struct adjNode* createNode(int v){
    struct adjNode* t=(struct adjNode*)malloc(sizeof(struct adjNode));
    t->vertex=v;
    t->next=NULL;
    return t;
}

struct graph* createGraph(int vertices){
    struct graph* g=(struct graph*)malloc(sizeof(struct graph));
    g->vertices=vertices;

    g->array=(struct adjList*)malloc(vertices*sizeof(struct adjList));
    for(int i=0;i<vertices;i++){
        g->array[i].head=NULL;
    }
    return g;
}

void addEdge(struct graph* g,int src,int dest){
struct adjNode* t=createNode(dest);
t->next=g->array[src].head;
g->array[src].head=t;

struct adjNode* temp=createNode(src);
temp->next=g->array[dest].head;
g->array[dest].head=temp;
}

void display(struct graph* g){
    for(int i=0;i<g->vertices;i++){
        struct adjNode* temp=g->array[i].head;
        while(temp){
            printf("%d-> ",temp->vertex);
            temp=temp->next;
        }
    printf("NULL\n");
    }
}

int main(){
    struct graph* g=createGraph(5);
    
    addEdge(g, 0, 1);
    addEdge(g, 0, 4);
    addEdge(g, 1, 2);
    addEdge(g, 1, 3);
    addEdge(g, 3, 4);

    display(g);
}