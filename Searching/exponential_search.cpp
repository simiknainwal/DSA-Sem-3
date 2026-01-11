#include<iostream>
using namespace std;



int binarySearch(int* arr,int l,int h,int key){
    while(l<=h){
        int mid=l+(h-l)/2;
        if(arr[mid]==key)return mid;
        else if(arr[mid]<key)l=mid+1;
        else h=mid-1;
    }
    return -1;
}


int exponentialSearch(int* arr,int n,int key){
        int i=0;
        if(arr[i]==key)return 0;

        i=1;
        while(i<n && key>=arr[i]){
            i=i*2;
        }
        return binarySearch(arr,i/2,min(i,n-1),key);
}


int main(){
    int arr[]={10,20,30,40,50,60,70,80,90,100};
    int key;
    cout<<"Enter the key: ";
    cin>>key;
    if(exponentialSearch(arr,10,key)==-1)cout<<"Element not found";
    else
    cout<<"Element found at index "<<exponentialSearch(arr,10,key);
}