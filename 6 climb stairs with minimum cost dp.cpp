#include<bits/stdc++.h>
using namespace std;
int min_cost_path(vector<vector<int>>v, int n, int m){
    vector<vector<int>>dp(n, vector<int>(m));
    for(int i=n-1;i>=0;i--){
        for(int j=m-1;j>=0;j--){
            if(i==n-1 && j==m-1){
                dp[i][j]=v[i][j];
            }
            else if(i==n-1){
                dp[i][j]=dp[i][j+1]+v[i][j];
            }
            else if(j==m-1){
                dp[i][j]=dp[i+1][j]+v[i][j];
            }
            else{
                dp[i][j]=min(dp[i][j+1], dp[i+1][j])+v[i][j];
            }
        }
    }
    return dp[0][0];
}
int main(){
    int n, m;
    cin>>n>>m;
    vector<vector<int>>v(n, vector<int>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>v[i][j];
        }
    }
   cout<<min_cost_path(v, n, m);
}
