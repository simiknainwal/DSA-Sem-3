//Sorting is done from right to left 
//Maximum element comes at right in ascending.

//Time complexity:
//Best case- O(n)
//Average case- O(n^2)
//Worst case- O(n^2)
#include<stdio.h>
int main(){
    int a[]={1,2,3,4,5};
    int flag=0;
    for(int i=0;i<5;i++){
        for(int j=0;j<(4-i);j++){
            if(a[j]>a[j+1]){
                flag=1;
                int t=a[j];
                a[j]=a[j+1];
                a[j+1]=t;
            }
        }
    }
    if(flag==0)printf("Already sorted\n");
    for(int i=0;i<5;i++){
        printf("%d ",a[i]);
    }
}