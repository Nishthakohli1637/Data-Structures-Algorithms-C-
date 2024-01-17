#include<bits/stdc++.h>
using namespace std;
int peak_element(int a[], int n){
    int s=0;
    int e=n-1;
    while(s<=e){
        int mid=(s+e)/2;
        if(mid>0 && mid<n-1){
            if(a[mid]>a[mid-1] && a[mid]>a[mid+1]){
                return mid;
            }
            else if(a[mid-1]>a[mid]){
                e=mid-1;
            }
            else{
                s=mid+1;
            }
        }
        else if(mid==0){
            if(a[0]>a[1]){
                return 0;
            }
            else{
                return 1;
            }
        }
        else if(mid==n-1){
            if(a[n-1]>a[n-2]){
                return n-1;
            }
            else{
                return n-2;
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
    cout<<peak_element(a, n);
}





class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n=nums.size();
        int s=0, e=n-1;
        while(s<e){
            int mid=s+(e-s)/2;
            if(nums[mid]<nums[mid+1]){
                s=mid+1;
            }
            else{
                e=mid;
            }
        }
        return s;
    }
};




int findPeakElement(vector<int> &arr) {
    // Write your code here
    int n=arr.size();
    if(n==1){
        return 0;
    }
    if(arr[0]>arr[1]){
        return 0;
    }
    if(arr[n-1]>arr[n-2]){
        return n-1;
    }
    int s=1, e=n-2;
    while(s<=e){
        int mid=(s+e)/2;
        if(arr[mid]>arr[mid-1] && arr[mid]>arr[mid+1]){
            return mid;
        }
        else if(arr[mid]>arr[mid-1]){
            s=mid+1;
        }
        else{
            e=mid-1;
        }
    }
    return -1;
}
