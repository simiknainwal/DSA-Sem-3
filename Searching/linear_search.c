#include<stdio.h>
void main(){
    int arr[]={1,2,3,4,5};
    int x,f=0;
    scanf("%d",&x);
    for(int i=0;i<5;i++){
        if(arr[i]==x){f=1; printf("true");}
    }if(f==0)
    printf("false");
}