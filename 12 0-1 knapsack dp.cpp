#include<bits/stdc++.h>
using namespace std;
int knapsack(int value[], int wt[], int n, int capacity){
    int dp[n+1][capacity+1];
    for(int i=0;i<n;i++){
        for(int j=0;j<=capacity;j++){
            if(i==0 || j==0){
               dp[i][j]= 0;
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=capacity;j++){
            if(j>=wt[i-1])
                {
                 
                      dp[i][j]=max(dp[i-1][j],dp[i-1][j-wt[i-1]]+value[i-1]);
                  
                  
                }
            else{
                dp[i][j]=dp[i-1][j];
            }
        }
    }
    return dp[n][capacity];
}
int main(){
    int n, value[10], wt[10];
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>value[i];
    }
    for(int i=0;i<n;i++){
        cin>>wt[i];
    }
    int capacity;
    cin>>capacity;
    cout<<knapsack(value, wt, n, capacity);
    // int value[] = { 15, 14, 10, 45, 30};
    // int wt[] = { 2, 5, 1, 3, 4};
    // int capacity = 7;
    // cout<<knapsack(value, wt, 5, capacity)<<endl;
    // return 0;
}
