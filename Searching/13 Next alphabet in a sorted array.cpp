#include<bits/stdc++.h>
using namespace std;
int next_alpha(char a[], int n, char ch){
    int s=0, e=n-1;
    int ans=-1;
    while(s<=e){
        int mid=(s+e)/2;
        if(a[mid]==ch){
            s=mid+1;
        }
        else if(a[mid]<ch){
            s=mid+1;
        }
        else if(a[mid]>ch){
            ans=mid;
            e=mid-1;
        }
    }
    return ans;
}
int main(){
    char a[]={'a', 'b', 'c', 'f', 'h'};
    int n=sizeof(a)/sizeof(a[0]);
    char ch;
    cin>>ch;
    cout<<next_alpha(a, n, ch);
}
