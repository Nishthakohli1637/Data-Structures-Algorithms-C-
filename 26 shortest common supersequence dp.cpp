#include<bits/stdc++.h>
using namespace std;
int lcs_superstring(string x, string y, int n, int m){
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
                dp[i][j]=max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    int lcs=dp[n][m];
    return ((n+m)-lcs);
    
}
int main(){
    string x, y;
    cin>>x>>y;
    int n=x.length();
    int m=y.length();
    cout<<lcs_superstring(x, y, n, m);
}
