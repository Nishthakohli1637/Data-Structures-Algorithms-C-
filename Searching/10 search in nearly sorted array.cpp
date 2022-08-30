#include<bits/stdc++.h>
using namespace std;
int search_nearly_sort(int a[], int n, int key){
    int s=0, e=n-1;
    while(s<=e){
        int mid=(s+e)/2;
        if(a[mid]==key){
            return mid;
        }
     if(mid-1>=s && a[mid-1]==key){
            return mid-1;
        }
     if(mid+1<=e && a[mid+1]==key){
            return mid+1;
        }
        else if(a[mid]>key){
            e=mid-2;
        }
        else{
            s=mid+1;
        }
    }
    return -1;
}
int main(){
    int n, a[10];
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int key;
    cin>>key;
    cout<<search_nearly_sort(a, n, key);
}
