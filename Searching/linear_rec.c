#include<stdio.h>
int linear(int*arr,int n,int x){
    if(n==0)return 0;
    if(arr[n]==x)return 1;
    linear(arr,n-1,x);
}

int main(){
    int arr[]={1,2,3,4,5,12,67,22,0};
    if(linear(arr,8,2)==1){
        printf("True");
    }else{
        printf("False");
    }
}