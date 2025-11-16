#include<stdio.h>
#include<stdlib.h>

void DFS(int A[][7],int i,int v[7]){
    // int visited[7]={0};
    printf("%d ",i);
    v[i]=1;
    for(int j=0;j<7;j++){
        if(A[i][j]==1 && v[j]==0){
            // visited[j]=1;
            DFS(A,j,v);
        }
    }
}

void main(){
    int a[7][7]={
    {0,1,1,1,0,0,0},
    {1,0,1,0,0,0,0,},
    {1,1,0,1,1,0,0},
    {1,0,1,0,1,0,0},
    {0,0,1,1,0,1,1},
    {0,0,0,0,1,0,0},
    {0,0,0,0,1,0,0}
};
int v[7]={0};
DFS(a,4,v);
}