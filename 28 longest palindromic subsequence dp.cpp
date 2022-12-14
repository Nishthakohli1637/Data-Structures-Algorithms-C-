#include<bits/stdc++.h>
using namespace std;
int lps(string s, string s2, int x, int y){
    vector<vector<int>>dp(x+1, vector<int>(y+1));
    for(int i=0;i<=x;i++){
        dp[i][0]=0;
    }
    for(int j=0;j<=y;j++){
        dp[0][j]=0;
    }
    for(int i=1;i<=x;i++){
        for(int j=1;j<=y;j++){
            if(s[i-1]==s2[j-1]){
                dp[i][j]=dp[i-1][j-1]+1;
            }
            else{
                dp[i][j]=max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    return dp[x][y];
}
int main(){
    string s;
    cin>>s;
    string s2=s;
    reverse(s2.begin(), s2.end());
    int x=s.length();
    int y=s2.length();
    cout<<lps(s, s2, x, y);
}
