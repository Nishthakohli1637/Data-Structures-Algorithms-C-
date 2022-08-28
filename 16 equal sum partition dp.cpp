#include<bits/stdc++.h>
using namespace std;
int subset(int a[], int n, int sum){
    bool dp[n+1][sum+1];
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
    return dp[n][sum];
}
bool equal(int a[], int n){
    int ans=0;
    for(int i=0;i<n;i++){
        ans=ans+a[i];
    }
    if(ans%2!=0){
        return false;
    }
    return subset(a, n, ans/2);
}
int main(){
    int n, a[10];
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int sum;
    cin>>sum;
    cout<<equal(a, n);
}
