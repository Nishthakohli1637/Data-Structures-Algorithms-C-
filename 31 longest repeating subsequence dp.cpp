#include<bits/stdc++.h>
using namespace std;
int lrs(string a, int n){
    vector<vector<int>>dp(n+1, vector<int>(n+1));
    for(int i=0;i<=n;i++){
        dp[i][0]=0;
    }
    for(int j=0;j<=n;j++){
        dp[0][j]=0;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(a[i-1]==a[j-1] && i!=j){
                dp[i][j]=dp[i-1][j-1]+1;
            }
            else{
                dp[i][j]=max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    return dp[n][n];
}
int main(){
    string a;
    cin>>a;
    int n=a.length();
    
    cout<<lrs(a, n);
}
