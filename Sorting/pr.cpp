#include<iostream>
#include<limits.h>
using namespace std;

void bubble(int* arr,int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<(n-1-i);j++){
            if(arr[j]>arr[j+1]){
                int t=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=t;
            }
        }
    }
}

void selection(int* arr,int n){
    int min;
    for(int i=0;i<n;i++){
        min=i;
        for(int j=i;j<n;j++){
            if(arr[j]<arr[min]){
                min=j;
            }
        }
        if(min!=i){
            int t=arr[min];
            arr[min]=arr[i];
            arr[i]=t;
        }
    }
}

void insertion(int* arr,int n){
    for(int i=0;i<n;i++){
        int j=i;
        while(j>0 && arr[j]<arr[j-1]){
            int t=arr[j];
            arr[j]=arr[j-1];
            arr[j-1]=t;
            j--;
        }
    }
}

void display(int* arr,int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}

int main(){
int arr[]={5,4,3,2,1};
// bubble(arr,5);
// selection(arr,5);
insertion(arr,5);
display(arr,5);
// selection(arr,5);
// display(arr,5);
}