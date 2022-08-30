#include<bits/stdc++.h>
using namespace std;
int search_rot_sort(int a[], int n, int key){
    int s=0, e=n-1;
    while(s<=e){
        int mid=(s+e)/2;
        
        if(a[mid]==key){
            return mid;
        }
        else if(a[mid]>=a[s]){
            if(key>=a[s] && key<=a[mid]){
                e=mid-1;
            }
            else{
                s=mid+1;
            }
        }
        else{
            if(key<=a[e] && key>=a[mid]){
                s=mid+1;
            }
            else{
                e=mid-1;
            }
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
    cout<<search_rot_sort(a, n, key);
}

