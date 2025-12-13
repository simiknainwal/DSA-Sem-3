#include<stdio.h>

void bubble(int* a,int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<(n-i-1);j++){
            if(a[j]>a[j+1]){
                int t=a[j];
                a[j]=a[j+1];
                a[j+1]=t;
            }
        }
    }
}

void selection(int* a,int n){
    int j=0;
    for(int i=0;i<n-1;i++){
        int min=i;
        for(int j=i+1;j<n;j++){
            if(a[j]<a[min]){
                min=j;
            }
        }
        int t=a[min];
        a[min]=a[i];
        a[i]=t;
    }
}

void insertion(int* a,int n){
    for(int i=0;i<n;i++){
        for(int j=i;j>0;j--){
            if(a[j-1]>a[j]){
                int t=a[j];
                a[j]=a[j-1];
                a[j-1]=t;
            }
        }
    }
}
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
void mergesort(int* a,int l,int r){
    if(l<r){
        int mid=l+(r-l)/2;
        mergesort(a,l,mid);
        mergesort(a,mid+1,r);
        merge(a,l,mid,r);
    }
}

void main(){
int a[5]={4,2,7,12,1};
// insertion(a,5);
mergesort(a,0,4);
for(int i=0;i<5;i++){
    printf("%d ",a[i]);
}
}