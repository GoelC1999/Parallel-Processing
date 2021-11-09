#include<stdio.h>
#include<conio.h>
void merge(int *arr,int l,int mid ,int r){
    int c[r-l+1];int pos = 0;
    int i =l;int j = mid+1;
    while(i<=mid&&j<=r){
        if(arr[i]>arr[j]){
            c[pos++] = arr[j++];
        }else{
            c[pos++] = arr[i++];
        }
    }
    while(i<=mid){
        c[pos++] = arr[i++];
    }
    while(j<=r){
        c[pos++] = arr[j++];
    }
    for(int i = l;i<=r;i++){
        arr[i] = c[i-l];
    }
}
void mergeSort(int *arr,int l,int r){
    if(l == r){
        return;
    }
    int mid = l + (r-l)/2;
    #pragma omp parallel
    {
    mergeSort(arr,l,mid);
    }
    #pragma omp parallel
    {
    mergeSort(arr,mid+1,r);
    }
    merge(arr,l,mid,r);
}
int main(){
    int n = 8; 
    int arr[]  = {12,34,1,67,3,23,67,2};
    mergeSort(arr,0,n-1);
     for(int i =0;i<n;i++){
        printf("%d ",arr[i]);
    }
    return 0;
}
