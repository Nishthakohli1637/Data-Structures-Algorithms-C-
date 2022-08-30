#include<bits/stdc++.h>
using namespace std;
int first_idx(int a[], int n, int key){
    int s=0, e=n-1;
    int ans=-1;
    while(s<=e){
        int mid=(s+e)/2;
        if(a[mid]==key){
            ans=mid;
            e=mid-1;
        }
        else{
            s=mid+1;
        }
    }
    return ans;
}
int last_occur(int a[], int n, int key){
    int s=0, e=n-1;
    int ans=-1;
    while(s<=e){
        int mid=(s+e)/2;
        if(a[mid]==key){
            ans=mid;
            s=mid+1;
        }
        else{
            e=mid-1;
        }
    }
    return ans;
}
int all_occ(int a[], int n, int key){
    int f=first_idx(a, n, key);
    int l=last_occur(a, n, key);
    
    return (l-f+1);
}
int main(){
    int n, a[10];
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int key;
    cin>>key;
    cout<<all_occ(a, n, key);
}
