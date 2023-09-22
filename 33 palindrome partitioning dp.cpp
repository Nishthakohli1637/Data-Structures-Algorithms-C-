#include<bits/stdc++.h>
using namespace std;

bool check_palin(string s, int i, int j){
    // if(i==j){
    //     return true;
    // }
    // if(i>j){
    //     return true;
    // }
    while(i<j){
        if(s[i]!=s[j]){
            return false;
        }
        i++;
        j--;
    }
    return true;
}
int palin_part(string s, int n, int i, int j, vector<vector<int>>&dp){
    
    if(i>=j){
        return 0;
    }
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    if(check_palin(s, i, j)==true){
        dp[i][j]=0;
        return 0;
    }
    int minv=INT_MAX;
    
    for(int k=i;k<j;k++){
        int ans1=palin_part(s, n, i, k, dp);
        int ans2=palin_part(s, n, k+1, j, dp);
       minv=min(ans1+ans2+1, minv);
    }
    dp[i][j]=minv;
    return minv;
}
int main(){
    string s;
    cin>>s;
    int n=s.length();
    vector<vector<int>>dp(n, vector<int>(n, -1));
    cout<<palin_part(s, n, 0, n-1, dp);
}
