#include<bits/stdc++.h>
using namespace std;
int coin_combi(int a[], int n, int amt){
    vector<int>dp(amt+1);
    dp[0]=1;
    for(int i=0;i<n;i++){
        for(int j=a[i];j<dp.size();j++){
            dp[j]+=dp[j-a[i]];
        }
    }
    return dp[amt];
}
int main(){
    int n, a[10];
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int amt;
    cin>>amt;
    cout<<coin_combi(a, n, amt);
}
