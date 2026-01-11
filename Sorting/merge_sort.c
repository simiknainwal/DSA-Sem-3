// Time Complexity=> O(nlog(n))
// Space Complexity=> O(n)
#include<stdio.h>
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

int main(){
    int a[]={45,23,78,90,12};
    mergeSort(a,0,4);
    printf("After sorting:");
    for(int i=0;i<5;i++){
        printf("%d ",a[i]);
    }
}