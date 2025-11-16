#include<stdio.h>
#include<stdlib.h>

struct graph{
    int nv;
    int a[10][10];
};

struct graph* createGraph(int vertices){
    struct graph* g=(struct graph*)malloc(sizeof(struct graph));
    g->nv=vertices;
    for(int i=0;i<vertices;i++){
        for(int j=0;j<vertices;j++){
            g->a[i][j]=0;
        }
    }
    return g;
}

void add(int src,int dest,struct graph* g){
    g->a[src][dest]=1;
    g->a[dest][src]=1;
}

void addDirected(int src,int dest,struct graph* g){
    g->a[src][dest]=1;
}

void display(struct graph* g){
    for(int i=0;i<g->nv;i++){
        for(int j=0;j<g->nv;j++){
            printf("%d ",g->a[i][j]);
        }
        printf("\n");
    }
}

int main(){
    struct graph* g=createGraph(5);
    add(0,1,g);
    add(0,4,g);
    add(1,2,g);
    add(1,3,g);
    add(1,4,g);
    add(2,3,g);
    add(3,4,g);
    display(g);
}