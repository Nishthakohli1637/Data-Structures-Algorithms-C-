#include<bits/stdc++.h>
using namespace std;
int knapsack_bound(int value[], int wt[], int n, int capacity){
    int dp[capacity+1];
    dp[0]=0;
    for(int j=1;j<=capacity;j++){
        int maxv=0;
        for(int i=0;i<n;i++){
            if(j>=wt[i]){
                int total=dp[j-wt[i]]+value[i];
            
            if(total>maxv){
                maxv=total;
            }
        }
        }
        dp[j]=maxv;
    }
    
    return dp[capacity];
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
    cout<<knapsack_bound(value, wt, n, capacity);
}
