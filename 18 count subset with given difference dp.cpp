#include<bits/stdc++.h>
using namespace std;
int count(int a[], int n, int sum){
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
                    dp[i][j]=dp[i-1][j] + dp[i-1][j-a[i-1]];
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
    int n, a[10], sum=0;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
        sum+=a[i];
    }
    int diff;
    cin>>diff;
    int ans=(diff+sum)/2;
    cout<<count(a, n, ans);
}
