#include<bits/stdc++.h>
using namespace std;
string print_lcs(string x, string y, int n, int m){
   vector<vector<int>>dp(n+1, vector<int>(m+1));
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
    int i=n, j=m;
    string s;
    while(i>0 && j>0){
        if(x[i-1]==y[j-1]){
            s.push_back(x[i-1]);
            i--;
            j--;
        }
        else{
            if(dp[i-1][j]>dp[i][j-1]){
            i--;
        }
        else{
            j--;
        }
    }
    }
    reverse(s.begin(), s.end());
    return s;
}
int main(){
    string x, y;
    cin>>x>>y;
    int n=x.length();
    int m=y.length();
    cout<<print_lcs(x, y, n, m);
}
