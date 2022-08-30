#include<bits/stdc++.h>
using namespace std;
int rot_sort_times(int a[], int n){
    int s=0, e=n-1;
    while(s<=e){
        int mid=s+(e-s)/2;
        int prev=(mid+n-1)%n;
        int next=(mid+1)%n;
        if(a[prev]>a[mid] && a[next]>a[mid]){
            return mid;
        }
        else if(a[mid]>=a[s]){
            s=mid+1;
        }
        else if(a[mid]<=a[e]){
            e=mid-1;
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
    
    cout<<rot_sort_times(a, n);
}
