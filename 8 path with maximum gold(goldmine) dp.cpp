#include<bits/stdc++.h>
using namespace std;
int goldmin(vector<vector<int>> v, int n, int m){
    vector<vector<int>>dp(n, vector<int>(m));
    for(int j=m-1;j>=0;j--){
        for(int i=0;i<n;i++){
            if(j==m-1){         //for the last column
            dp[i][j]=v[i][j];
        }
        else if(i==0){          //for the first row    
            dp[i][j]=v[i][j] + max(dp[i][j+1], dp[i+1][j+1]);
        }
        else if(i==n-1){        //for the last row
            dp[i][j]=v[i][j] + max(dp[i-1][j+1], dp[i][j+1]);
        }
        else{                   //for the rest of the elements in the matrix    
            dp[i][j]=v[i][j] + max(dp[i-1][j+1], max(dp[i][j+1], dp[i+1][j+1]));
        }
    }
}
int ans=INT_MIN;
for(int i=0;i<n;i++){
    ans=max(ans, dp[i][0]);
}
return ans;
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
    cout<<goldmin(v, n, m);
}
