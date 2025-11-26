#include<stdio.h>
#include<stdlib.h>

struct edge{
    int u;
    int v;
    int wt;
};

//Maintaining the property of min-heap at every swap.
void heapify(struct edge heap[],int i,int n){
    int smallest=i;
    int left=2*i+1;
    int right=2*i+2;
    if(left<n && heap[left].wt<heap[smallest].wt){
        smallest=left;
    }
    if(right<n && heap[right].wt<heap[smallest].wt){
        smallest=right;
    }
    if(smallest!=i){
        int t=heap[smallest].wt;
        heap[smallest].wt=heap[i].wt;
        heap[i].wt=t;
        heapify(heap,smallest,n);
    }
}

//Transforming the unordered array into complete binary tree.
void buildheap(struct edge heap[],int n){
    for(int i=n/2-1;i>=0;i--){
        heapify(heap,i,n);
    }
}

void heapsort(struct edge heap[],int n){
    buildheap(heap,n);
    for(int i=n-1;i>0;i--){
        int t=heap[0].wt;
        heap[0].wt=heap[i].wt;
        heap[i].wt=t;
        heapify(heap,0,i);
    }
}

