#include<bits/stdc++.h>
using namespace std;
int coin(int a[], int n, int amt){
    vector<int>dp(amt+1);
    dp[0]=1;
    for(int i=1;i<dp.size();i++){
        for(int j=0;j<a[j];j++){
            if(a[j]<=i){
                dp[i]+=dp[i-a[j]];
            }
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
    cout<<coin(a, n, amt);
}
