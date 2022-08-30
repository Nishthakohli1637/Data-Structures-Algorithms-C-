#include<bits/stdc++.h>
using namespace std;
int binary_desc(int a[], int n, int key){
    int s=n-1, e=0;
    while(s>=e){
        int mid=(s+e)/2;
        if(a[mid]==key){
            return mid;
        }
        else if(a[mid]<key){
            s=mid-1;
        }
        else{
            e=mid+1;
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
    cout<<binary_desc(a, n, key);
}
