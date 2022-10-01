#include<bits/stdc++.h>
using namespace std;
void merge(int arr[], int s, int e){
    int mid=(s+e)/2;
    int n1=mid-s+1;
    int n2=e-mid;
    int a[n1];
    int b[n2];
    int k=s;
    for(int i=0;i<n1;i++){
        a[i]=arr[k++];
    }
    k=mid+1;
    for(int i=0;i<n2;i++){
        b[i]=arr[k++];
    }
    int i=0;
    int j=0;
    k=s;
    while(i<n1 && j<n2){
        if(a[i]<b[j]){
            arr[k++]=a[i++];
        }
        else{
            arr[k++]=b[j++];
        }
    }
    while(i<n1){
        arr[k++]=a[i++];
    }
    while(j<n2){
        arr[k++]=b[j++];
    }
}
void merge_sort(int arr[], int s, int e){
    if(s>=e){
        return;
    }
    int mid=(s+e)/2;
    merge_sort(arr, s, mid);
    merge_sort(arr, mid+1, e);
    merge(arr, s, e);
}
int main(){
    int n, arr[10];
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    merge_sort(arr, 0, n-1);
    for(int i=0;i<n;i++){
        cout<<arr[i];
    }
}
