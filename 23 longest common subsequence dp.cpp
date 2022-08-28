#include<bits/stdc++.h>
using namespace std;
int lcs_dp(string x, string y, int n, int m, vector<vector<int>>dp){
   
    if(n==0 || m==0){
        return 0;
    }
    if(dp[n][m]!=-1){
        return dp[n][m];
    }
    if(x[n-1] == y[m-1]){
         dp[n][m]=1+lcs_dp(x, y, n-1, m-1,dp);
    }
    else{
     dp[n][m]=max(lcs_dp(x, y, n, m-1, dp), lcs_dp(x, y, n-1, m, dp));
    }
    
    return dp[n][m];
}

int main(){
    string x, y;
   cin>>x>>y;
    int n=x.length();
    int m=y.length();
    vector<vector<int>>dp(n+1, vector<int>(m+1));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            dp[i][j]=-1;
        }
    }
    cout<<lcs_dp(x, y, n, m, dp);
}

#include<bits/stdc++.h>
using namespace std;
int lcs_top_down(string x, string y, int n, int m){
    vector<vector<int>>dp(n+1, vector<int>(m+1));
    for(int i=0;i<=n;i++){
        dp[i][0]=0;
    }
    for(int j=0;j<=m;j++){
        dp[0][j]=0;
    }
    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++){
            if(x[i-1]==y[i-1]){
                dp[i][j]=1+dp[i-1][j-1];
            }
            else{
                dp[i][j]=max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    return dp[n][m];
}
int main(){
    string x, y;
    cin>>x>>y;
    int n=x.length();
    int m=y.length();
    cout<<lcs_top_down(x, y, n, m);
}
