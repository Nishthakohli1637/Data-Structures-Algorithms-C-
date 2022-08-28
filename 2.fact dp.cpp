#include<bits/stdc++.h>
using namespace std;
int fact_dp(int n, vector<int> &dp){
    if(n==0){
        return 1;
    }
    if(dp[n]!=-1){
        return dp[n];
    }
    int ans=fact_dp(n-1, dp)*n;
    dp[n]=ans;
    return dp[n];
}
int main(){
    int n;
    cin>>n;
    vector<int> dp(n+1, -1);
    dp[0]=0;
    dp[1]=1;
    cout<<fact_dp(n, dp);
}
