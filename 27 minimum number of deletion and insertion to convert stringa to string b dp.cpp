#include<bits/stdc++.h>
using namespace std;
int length_d_i(string a, string b, int n, int m){
    vector<vector<int>>dp(n+1, vector<int>(m+1));
    for(int i=0;i<=n;i++){
        dp[i][0]=0;
    }
    for(int j=0;j<=m;j++){
        dp[0][j]=0;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(a[i-1]==b[j-1]){
                dp[i][j]=dp[i-1][j-1]+1;
            }
            else{
                dp[i][j]=max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    int lcs=dp[n][m];
    int ans1=a.length()-lcs;
    int ans2=b.length()-lcs;
    return ans1+ans2;
    
}
int main(){
    string a, b;
    cin>>a>>b;
    int n=a.length();
    int m=b.length();
    cout<<length_d_i(a, b, n, m);
}
