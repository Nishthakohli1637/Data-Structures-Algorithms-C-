#include<bits/stdc++.h>
using namespace std;
int min_diff(int a[], int n, int key){
    int s=0, e=n-1;
    while(s<=e){
        int mid=(s+e)/2;
        if(a[mid]==key){
            return a[mid];
        }
        else if(a[mid]<key){
            s=mid+1;
        }
        else{
            e=mid-1;
        }
    }
    int ans1=abs(a[s]-key);
    int ans2=abs(a[e]-key);
    return min(ans1, ans2);
}
int main(){
    int n, a[10];
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int key;
    cin>>key;
    cout<<min_diff(a, n, key);
}
