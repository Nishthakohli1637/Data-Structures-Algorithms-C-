
#include<bits/stdc++.h>
using namespace std;
int ceil_elem(int a[], int n, int key){
    int s=0, e=n-1;
    int ans=-1;
    while(s<=e){
        int mid=(s+e)/2;
        if(a[mid]==key){
            return a[mid];
        }
        else if(a[mid]>key){
            ans=a[mid];
            e=mid-1;
        }
        else{
            s=mid+1;
        }
    }
    return ans;
}
int main(){
    int n, a[10];
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int key;
    cin>>key;
    cout<<ceil_elem(a, n, key);
}
