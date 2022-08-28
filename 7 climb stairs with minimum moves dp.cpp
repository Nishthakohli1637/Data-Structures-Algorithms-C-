#include<bits/stdc++.h>
using namespace std;
int min_moves(int a[], int n){
    vector<int> dp(n+1, INT_MAX);
    dp[n]=0;
    for(int i=n-1;i>=0;i--){
        if(a[i]>0){
            int mini=INT_MAX;
        for(int j=1;j<a[i] && (i+j)<n;j++){
            mini=min(mini, dp[i+j]);
        }
        if(mini!=INT_MAX){
            dp[i]=mini+1;
        }
        else{
            dp[i]=0;
        }
        }
    }
    return dp[0];
}
int main(){
    int n, a[20];
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    cout<<min_moves(a, n);
}
