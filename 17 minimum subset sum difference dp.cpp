#include<bits/stdc++.h>
using namespace std;
int diff(int a[], int n, int sum){
    int dp[n+1][sum+1];
    for(int i=0;i<=n;i++){
        for(int j=0;j<=sum;j++){
            if(i==0 && j==0){
                dp[i][j]=true;
            }
            else if(i==0){
                dp[i][j]=false;
            }
            else if(j==0){
                dp[i][j]=true;
            }
            else{
                if(j>=a[i-1]){
                    dp[i][j]=dp[i-1][j] || dp[i-1][j-a[i-1]];
                }
                else{
                    dp[i][j]=dp[i-1][j];
                }
            }
        }
    }
    
    int mini=INT_MAX;
    for(int i=0;i<=sum/2;i++){
        if(dp[n][sum]==true){
        mini=min(mini, sum-2*i);
    }
    }
    return mini;
}
int main(){
    int n, a[10], sum=0;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
        sum+=a[i];
    }
    cout<<diff(a, n, sum);
}
