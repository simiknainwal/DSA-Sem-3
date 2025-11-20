#include<stdio.h>
#include<stdlib.h>

struct disjoint{
int* rank;
int* parent;
int* size;
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

int main(){
struct disjoint* d=initialize(7);

unionSize(1,2,d);
unionSize(2,3,d);
unionSize(4,5,d);
unionSize(6,7,d);
unionSize(5,6,d);

if(findParent(3,d)==findParent(7,d)){
    printf("Same\n");
}else{
printf("Different\n");
}

unionSize(3,7,d);
if(findParent(3,d)==findParent(7,d)){
    printf("Same\n");
}else{
printf("Different\n"); 
}
}

