#include<bits/stdc++.h>
using namespace std;
int wine_prob(int a[], int s, int e, int y, int dp[][10]){
    if(s>e){
        return 0;
    }
    
    if(dp[s][e]!=0){
        return dp[s][e];
    }
    int left=a[s]*y + wine_prob(a, s+1, e, y+1, dp);
    int right=a[e]*y + wine_prob(a, s, e-1, y+1, dp);
    dp[s][e]=max(left,right);
    return dp[s][e];
}
int main(){
    int n, a[10], y;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    cin>>y;
    int dp[10][10]={0};
    cout<<wine_prob(a, 0, n-1, y, dp);
}

