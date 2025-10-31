#include <stdio.h>

int binarySearch(int arr[], int n, int x) {
    int left = 0;
    int right = n-1;
    while (left <= right) {
        int mid = left + right / 2;
        if (arr[mid] ==x){
            return 1; 
        }
        else if (arr[mid] <x){
            left = mid + 1;  
        }else{
            right = mid - 1;
        }
        }
    return -1;
}

int main(){
    int arr[]={1,2,3,4,5,6};
    if(binarySearch(arr,5,33)==1)
    printf("true");
    else printf("false");
}
