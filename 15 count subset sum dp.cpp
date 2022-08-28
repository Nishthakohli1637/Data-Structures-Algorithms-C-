#include<bits/stdc++.h>
using namespace std;
int target_count(int a[], int n, int sum){
    int dp[n+1][sum+1];
    for(int i=0;i<=n;i++){
        for(int j=0;j<=sum;j++){
            if(i==0 && j==0){
                dp[i][j]=0;
            }
            else if(i==0){
                dp[i][j]=0;
            }
            else if(j==0){
                dp[i][j]=1;
            }
            else{
                if(j>=a[i-1]){
                    dp[i][j]=dp[i-1][j]+dp[i-1][j-a[i-1]];
                }
                else{
                    dp[i][j]=dp[i-1][j];
                }
            }
        }
    }
    return dp[n][sum];
}
int main(){
    int n, a[10];
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int sum;
    cin >>sum;
    cout<<target_count(a, n, sum);
}
