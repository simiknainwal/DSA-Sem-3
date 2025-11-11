// // Insertion sort=>  All the elements at its left are less than it.

// // Bubble and selection sort can't work perfectly with online data as data can be inserted for infinity
// // Generally used in running stream of data.It doesn't require the limit.

// //Time complexity: Same as bubble.

// #include<stdio.h>
// int main(){
//     int a[]={5,4,3,2,1};
//     int min=a[0],j,temp;
//     for(int i=0;i<5;i++){
//         // min=a[i];
//         j=i-1;
//         temp=a[i];
//         while(j>=0 && a[j]>temp){
//             a[j+1]=a[j];
//             a[j]=temp;
//             j--;
//         }
//     }
//     for(int i=0;i<5;i++){
//         printf("%d ",a[i]);
//     }
// }


#include<stdio.h>
void main(){
     int a[]={6,5,4,3,2,1};
     for(int i=0;i<6;i++){
            for(int j=i;j>0;j--){
                if(a[j-1]>a[j]){
                    int t=a[j-1];
                    a[j-1]=a[j];
                    a[j]=t;
                }
            }
     }
     for(int i=0;i<6;i++){
        printf("%d ",a[i]);
     }
}