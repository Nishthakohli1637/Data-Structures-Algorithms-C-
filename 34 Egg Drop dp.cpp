#include<bits/stdc++.h>
using namespace std;
int egg_drop(int e, int f, vector<vector<int>>&dp){
    if(f==0 || f==1){
        return f;
    }
    if(e==1){
        return f;
    }
    if(dp[e][f]!=-1){
        return dp[e][f];
    }
    int ans=INT_MAX;
    for(int k=1;k<=f;k++){
        int ans1=egg_drop(e-1, k-1, dp);
        int ans2=egg_drop(e, f-k, dp);
        int temp=min(ans1, ans2);
        ans=min(ans, temp);
    }
    dp[e][f]=ans+1;
    return dp[e][f];
}
int main(){
    int e, f;
    cin>>e>>f;
    vector<vector<int>>dp(e+1, vector<int>(f+1, -1));
     cout<<egg_drop(e, f, dp);
}
