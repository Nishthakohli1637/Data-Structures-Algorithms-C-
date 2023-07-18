  #include<bits/stdc++.h>
using namespace std;
bool target_sum(int a[], int n, int target){
    bool dp[n+1][target+1];
    for(int i=0;i<=n;i++){
        for(int j=0;j<=target;j++){
            if(i==0 && j==0){
                dp[i][j]=true;
            }
            else if(i==0){
                dp[i][j]=false;
            }
            else if(j==0){
                dp[i][j]==true;
            }
            
                else{
                    if(j>=a[i-1]){
                            dp[i][j]=dp[i-1][j-a[i-1]];
                        }
                        else{
                            dp[i][j]=dp[i-1][j];
                        }
                    }
                }
            }
    return dp[n][target];
}
int main(){
    int n, a[20];
    cin>>n;
    
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int target;
    cin>>target;
    if(target_sum(a, n, target)){
        cout << "true";
    }
    else{
        cout << "false";
    }
}
