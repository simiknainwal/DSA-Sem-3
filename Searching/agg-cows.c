#include<stdio.h>
#include<stdlib.h>
// #include<boolean>

void merge(int* arr,int l,int mid,int r){
    int n1=mid-l+1;
    int n2=r-mid;
    int a1[n1],a2[n2];
    for(int i=0;i<n1;i++){
        a1[i]=arr[l+i];
    }
    for(int i=0;i<n2;i++){
        a2[i]=arr[mid+1+i];
    }
    int i=0,j=0,k=l;
    while(i<n1 && j<n2){
        if(a1[i]<a2[j]){
            arr[k++]=a1[i++];
        }else{
            arr[k++]=a2[j++];
        }
    }
    while(i<n1){
        arr[k++]=a1[i++];
    }
    while(j<n2){
        arr[k++]=a2[j++];
    }
}

void mergeSort(int* a,int l,int r){
    if(l<r){
        int mid=l+(r-l)/2;
        mergeSort(a,l,mid);
        mergeSort(a,mid+1,r);
        merge(a,l,mid,r);
    }
}

 int isCowPlaced(int* arr,int dist,int cows,int n){
    int countCows=1;
    int last=arr[0];
    
    for(int i=1;i<n;i++){
        if(arr[i]-last>=dist){
            // return true;
            last=arr[i];
            countCows++;
        }
    }
    if(countCows>=cows){
        return 1;
    }
    return 0;
}

int aggressiveCows(int *stalls, int n, int k) {
    int t=0;
    mergeSort(stalls,0,n-1);
    int max=stalls[n-1];
    int min=stalls[0];
    for(int i=1;i<=max-min;i++){
        if(isCowPlaced(stalls,i,k,n)){
            continue;
        }else{
            return i-1;
        }
    }
    return max-min;

}


int main(){
    int arr[]={1,5,17};
    printf("%d",aggressiveCows(arr,3,2));
}