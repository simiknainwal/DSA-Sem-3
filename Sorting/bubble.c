#include<stdio.h>
int main(){
    int a[]={3,5,1,6,2,0};
    for(int i=0;i<5;i++){
        for(int j=0;j<(4-i);j++){
            if(a[j]>a[j+1]){
                int t=a[j];
                a[j]=a[j+1];
                a[j+1]=t;
            }
        }
    }
    for(int i=0;i<5;i++){
        printf("%d ",a[i]);
    }
}