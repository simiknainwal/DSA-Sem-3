#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int des;
    struct node * next;
}node;

void add(node * p[],int sp,int dp){
    node * temp=(node *)malloc(sizeof(node));
    temp->des=dp;
    temp->next=NULL;
    if(p[sp]==NULL){
       p[sp]=temp;
    }
    else{
        temp->next=p[sp];
        p[sp]=temp;
    }
}
int main(){
    node * p[10];
    int x;
    printf("Enter the No. of Nodes between 1 to 10:\n");
    scanf("%d",&x);
    for(int i=0;i<x;i++){
        p[i]=NULL;
    }
    int flag=1,choice;
    while(flag){
        printf("Enter the choice\n1.To add edge\n2.to exit\n");
        scanf("%d",&choice);
        if(choice==1){
            int sp,dp;
            printf("Enter the source of the edge:\n");
            scanf("%d",&sp);
            printf("Enter the destination of the edge:\n");
            scanf("%d",&dp);
            add(p,sp,dp);
        }
        else if(choice==2){
            flag=0;
        }
        else{
            printf("Inavlid choice\n");
        }
    }
}