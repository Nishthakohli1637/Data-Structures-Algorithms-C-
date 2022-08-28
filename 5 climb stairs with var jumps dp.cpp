#include<bits/stdc++.h>
using namespace std;
int climb_var_jumps(int a[], int n){
    vector<int> dp(n+1, 0);
    dp[n]=1;
    for(int i=n-1;i>=0;i--){
        for(int j=1;j<=a[i] && i+j<=dp.size();j++){
            dp[i]=dp[i]+dp[i+j];
        }
    }
    return dp[0];
}
int main(){
    int n, a[10];
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    cout<<climb_var_jumps(a, n);
}
