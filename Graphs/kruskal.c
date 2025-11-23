#include<stdio.h>
#include<stdlib.h>

struct disjoint{
int* rank;
int* parent;
int* size;
};

struct edge{
    int u;
    int v;
    int wt;
};

struct disjoint* initialize(int n){
    struct disjoint* t=(struct disjoint*)malloc(sizeof(struct disjoint));
    
    t->rank=(int*)malloc(sizeof(int)*(n+1));
    t->parent=(int*)malloc(sizeof(int)*(n+1));
    t->size=(int*)malloc(sizeof(int)*(n+1));
    
    for(int i=0;i<=n;i++){
        t->rank[i]=0;
        t->parent[i]=i;
        t->size[i]=1;
    }
    return t;
}

int findParent(int node,struct disjoint* d){
    if(node==d->parent[node]){
        return node;
    }
    return d->parent[node]=findParent(d->parent[node],d);
}


void unionRank(int u,int v,struct disjoint* d){
    int upu=findParent(u,d);
    int upv=findParent(v,d);

    if(upu==upv)return;
    int uru=d->rank[upu];
    int urv=d->rank[upv];
    if(uru<urv){
        d->parent[upu]=upv;
    }else if(uru>urv){
        d->parent[upv]=upu;
    }else{
        d->parent[upv]=upu;
        d->rank[upu]++;
    }
}

void unionSize(int u,int v,struct disjoint* d){
    int ult_pu=findParent(u,d);
    int ult_pv=findParent(v,d);
    if(ult_pu==ult_pv)return;

    if(d->size[ult_pu]>d->size[ult_pv]){
        d->parent[ult_pv]=ult_pu;
        d->size[ult_pu]+=d->size[ult_pv];
    }
    // else if(d->size[ult_pv]>d->size[ult_pu]){
    //     d->parent[ult_pu]=ult_pv;
    //     d->size[ult_pv]+=d->size[ult_pu];
    // }
    else{
        d->parent[ult_pu]=ult_pv;
        d->size[ult_pv]+=d->size[ult_pu];
    }

}

void sort(struct edge Edge[],int E){
for(int i=0;i<E;i++){
    for(int j=0;j<(E-1-i);j++){
        if(Edge[j].wt>Edge[j+1].wt){
            struct edge t=Edge[j];
            Edge[j]=Edge[j+1];
            Edge[j+1]=t;
        }
    }
}
}

void MST(struct edge Edge[], int E, int N){
    struct disjoint* d=initialize(N);
    int minwt=0;
    sort(Edge,E);
    
    for(int i=0;i<E;i++){
        int u=Edge[i].u;
        int v=Edge[i].v;
        int wt=Edge[i].wt;
        
        if(findParent(u,d)!=findParent(v,d)){
            printf("%d---%d\n",u,v);
            minwt+=wt;
            unionSize(u,v,d);
        }
    }
    printf("Minimum weight is %d",minwt);


}

int main(){
struct edge edges[] = {
        {1, 2, 5},
        {2, 3, 3},
        {1, 3, 10},
        {4, 5, 4},
        {5, 6, 1},
        {6, 7, 2},
        {3, 7, 8},
        {2, 6, 6}
    };
int E=sizeof(edges)/sizeof(edges[0]);
    MST(edges,E,7);

}

