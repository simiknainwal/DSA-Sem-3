#include<stdio.h>
int main(){
    int a[]={5,4,3,2,1};
    int min=100;
    // for(int i=0;i<5;i++){
    //     for(int j=i+1;j<5;j++){
    //         if(a[i]>a[j]){
    //             int t=a[i];
    //             a[i]=a[j];
    //             a[j]=t;
    //         }
    //     }
    // }
    int x=0;
    for(int i=0;i<4;i++){
        min=a[i];
        for(int j=i+1;j<5;j++){
        if(min>a[j]){
            min=a[j];
            x=j;
        }
    }if(min==a[i])
    a[i]=min;
    else{
    int t=a[x];
    a[x]=a[i];
    a[i]=t;
    }
}
    for(int i=0;i<5;i++){
        printf("%d ",a[i]);
    }
}