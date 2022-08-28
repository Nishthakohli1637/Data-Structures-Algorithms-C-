#include<bits/stdc++.h>
using namespace std;
int fib_dp(int n, vector<int> &dp){
    if(n==0 || n==1){
        return n;
    }
    if(dp[n]!=-1){
        return dp[n];
    }
    int fib1=fib_dp(n-1, dp);
    int fib2=fib_dp(n-2, dp);
    int ans=fib1+fib2;
    dp[n]=ans;
    return dp[n];
}
int main(){
    int n;
    cin>>n;
    vector<int> dp(n+1, -1);
    dp[0]=0;
    dp[1]=1;
    cout<<fib_dp(n, dp);
}
