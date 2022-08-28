#include<bits/stdc++.h>
using namespace std;
int lps_del(string s, string s1, int n, int m){
    vector<vector<int>>dp(n+1, vector<int>(m+1));
    for(int i=0;i<=n;i++){
        dp[i][0]=0;
    }
    for(int j=0;j<=m;j++){
        dp[0][j]=0;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(s[i-1]==s1[j-1]){
                dp[i][j]=dp[i-1][j-1]+1;
            }
            else{
                dp[i][j]=max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    int lcs=dp[n][m];
    int ans=s.length()-lcs;
    return ans;
}
int main(){
    string s;
    cin>>s;
    string s1=s;
    reverse(s.begin(), s.end());
    int n=s.length();
    int m=s1.length();
    cout<<lps_del(s, s1, n, m);
}
