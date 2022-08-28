#include<bits/stdc++.h>
using namespace std;
int lcs_substring(string x, string y, int n, int m){
     int dp[n+1][m+1];
     for(int i=0;i<=n;i++){
         dp[i][0]=0;
     }
     for(int j=0;j<=m;j++){
         dp[0][j]=0;
     }
     for(int i=1;i<=n;i++){
         for(int j=1;j<=m;j++){
             if(x[i-1]==y[j-1]){
                 dp[i][j]=dp[i-1][j-1]+1;
             }
             else{
                 dp[i][j]=0;
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
    cout<<lcs_substring(x, y, n, m);
}

