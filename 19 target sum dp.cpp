#include<bits/stdc++.h>
using namespace std;
int target_sum(int a[], int n, int target){
    int dp[n+1][target+1];
    for(int i=0;i<=n;i++){
        for(int j=0;j<=target;j++){
            if(i==0 && j==0){
                dp[i][j]=1;
            }
            else if(i==0){
                dp[i][j]=0;
            }
            else if(j==0){
                dp[i][j]=1;
            }
            else{
                if(j>=a[i-1]){
                    dp[i][j]=dp[i-1][j] + dp[i-1][j-a[i-1]];
                }
                else{
                    dp[i][j]=dp[i-1][j];
                }
            }
        }
    }
    return dp[n][target];
}
int main(){
    int n, a[10], sum=0;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<n;i++){
        sum+=a[i];
    }
    int target;
    cin>>target;
    int ans=(sum+target)/2;
    cout<<target_sum(a, n, ans);
}
