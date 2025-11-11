//Selection sort=> In this we will se first element and check for minimum element at its right and swap the elements and next we check for minimum element after that index at right.

//Has less number of swap operations than bubble but time complexity is not same in all cases.
//Time complexity:
// O(n^2) for all cases.
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