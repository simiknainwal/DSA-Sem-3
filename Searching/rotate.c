#include<stdio.h>
#include<limits.h>
void main(){
    int n=5;
    int nums[]={4,5,1,2,3};
    int min=INT_MAX;
    int l=0;
    int h=n-1;
    int i=0;

    while(l<=h){
        int mid=(l+h)/2;

        if(nums[l]<=nums[mid]){
            if(nums[l]<min){
                min=nums[l];
                i=l;
            }
            l=mid+1;
        }
        else{
            if(min>nums[mid]){
                min=nums[mid];
                i=mid;
            }
            h=mid-1;
        }
    }
    printf("Number of times array is rotated is %d",i);
}