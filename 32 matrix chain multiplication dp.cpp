#include<bits/stdc++.h>
using namespace std;
int mcm(int a[], int n, int i, int j){
    if(i>=j){
        return 0;
    }
    int minv=INT_MAX;
    int ans;
    for(int k=i;k<j;k++){
         ans=mcm(a, n, i, k)+mcm(a, n, k+1, j)+(a[i-1]*a[k]*a[j]);
         minv=min(minv, ans);
    }
    
    return minv;
    
}
int main(){
    int n, a[10];
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    cout<<mcm(a, n, 1, n-1);
}

#include<bits/stdc++.h>
using namespace std;
int dp[100][100];
int mcm_dp(int a[], int n, int i, int j){
    if(i>=j){
        return 0;
    }
    
    
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    dp[i][j]=INT_MAX;
    for(int k=i;k<j;k++){
        dp[i][j]=min(mcm_dp(a, n, i, k)+mcm_dp(a, n, k+1, j)+(a[i-1]*a[k]*a[j]), dp[i][j]);
    }
    return dp[i][j];
}
int main(){
    int n;
    int a[10];
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
 
    memset(dp, -1, sizeof dp);
    cout<<mcm_dp(a, n, 1, n-1);
}
