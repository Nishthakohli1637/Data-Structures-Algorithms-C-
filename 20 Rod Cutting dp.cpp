#include<bits/stdc++.h>
using namespace std;
int rod_cut(int length[], int price[], int n, int len){
    int dp[n+1][len+1];
    for(int i=0;i<=n;i++){
        dp[i][0]=0;
    }
    for(int j=0;j<=len;j++){
        dp[0][j]=0;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=len;j++){
            if(j>=length[i-1]){
                dp[i][j]=max(dp[i-1][j],price[i-1]+dp[i][j-length[i-1]]);
            }
            else{
                dp[i][j]=dp[i-1][j];
            }
        }
    }
    return dp[n][len];
}
int main(){
    int n, length[10], price[10];
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>length[i];
    }
    for(int i=0;i<n;i++){
        cin>>price[i];
    }
    int len;
    cin>>len;
    cout<<rod_cut(length, price, n, len);
}
