#include<bits/stdc++.h>
using namespace std;
int count_binary(int n){
    int dp0[n+1];
    int dp1[n+1];
    dp0[1]=1;
    dp1[1]=1;
    for(int i=2;i<=n;i++){
        dp1[i]=dp0[i-1]+dp1[i-1];
        dp0[i]=dp1[i-1];
    }
    return dp0[n]+dp1[n];
}
int main(){
    int n;
    cin>>n;
    cout<<count_binary(n);
}
