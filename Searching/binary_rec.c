#include<stdio.h>
int binary(int *arr,int l,int r,int x){
    if(l>r)return -1;
    int mid=(l+r)/2;
    if(arr[mid]==x){
        return 1;
    }
    else if(arr[mid]<x)binary(arr,l+1,r,x);
    else binary(arr,l,r-1,x);
}

int main(){
    int arr[]={1,2,3,4,5,6};
    if(binary(arr,0,5,4)==1)
    printf("true");
    else printf("false");
}
