#include<bits/stdc++.h>
using namespace std;
int dp[100][100];
bool check_palin(string s, int n, int i, int j){
    if(i==j){
        return true;
    }
    if(i>j){
        return true;
    }
    while(i<j){
        if(s[i]!=s[j]){
            return false;
        }
        i++;
        j--;
    }
    return true;
}
int palin_part(string s, int n, int i, int j){
    if(i>=j){
        return 0;
    }
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    dp[i][j]=INT_MAX;
    for(int k=i;k<j;k++){
        int ans1=palin_part(s, n, i, k);
        int ans2=palin_part(s, n, k+1, j);
        dp[i][j]=min(ans1+ans2+1, dp[i][j]);
    }
    return dp[i][j];
}
int main(){
    string s;
    cin>>s;
    int n=s.length();
    memset(dp, -1, sizeof(dp));
    cout<<palin_part(s, n, 1, n-1);
}
