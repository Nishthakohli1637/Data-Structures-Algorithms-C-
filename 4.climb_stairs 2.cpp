#include<bits/stdc++.h>
using namespace std;
int climb_stairs(int n, vector<int> &dp){
    if(n==0){
        return 1;
    }
    if(n<0){
        return 0;
    }
    if(dp[n]!=-1){
        return dp[n];
    }
    int climb1=climb_stairs(n-1, dp);
    int climb2=climb_stairs(n-2, dp);
    
    int ans=climb1+climb2;
    dp[n]=ans;
    return dp[n];
}
int main(){
    int n;
    cin>>n;
    vector<int> dp(n+1, -1);
    dp[0]=0;
    dp[1]=1;
    cout<<climb_stairs(n, dp);
}
