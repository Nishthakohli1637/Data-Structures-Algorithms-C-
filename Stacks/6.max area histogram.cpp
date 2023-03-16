#include<bits/stdc++.h>
using namespace std;
vector<int> nsr(int a[], int n){
    stack<pair<int, int>> s;
    vector<int> ans;
    for(int i=n-1;i>=0;i--){
        if(s.empty()){
            ans.push_back(-1);
        }
        else if(!s.empty() && s.top().first<a[i]){
            ans.push_back(s.top().second);
        }
        else if(!s.empty() && s.top().first>=a[i]){
            while(!s.empty() && s.top().first>=a[i]){
                s.pop();
            }
            if(s.empty()){
                ans.push_back(-1);
            }
            else{
                ans.push_back(s.top().second);
            }
        }
        s.push({a[i], i});
    }
    reverse(ans.begin(), ans.end());
    return ans;
}
vector<int> nsl(int a[], int n){
    stack<pair<int, int>> s;
    vector<int> ans;
    for(int i=0;i<n;i++){
        if(s.empty()){
            ans.push_back(-1);
        }
        else if(!s.empty() && s.top().first<a[i]){
            ans.push_back(s.top().second);
        }
        else if(!s.empty() && s.top().first>=a[i]){
            while(!s.empty() && s.top().first>=a[i]){
                s.pop();
            }
            if(s.empty()){
                ans.push_back(-1);
            }
            else{
                ans.push_back(s.top().second);
            }
        }
        s.push({a[i], i});
    }
    
    return ans;
}
int max_area(int a[], int n){
    vector<int> left=nsl(a, n);
    vector<int> right=nsr(a, n);
    int ans=INT_MIN;
    for(int i=0;i<n;i++){
        if(right[i]==-1){
            right[i]=n;
        }
        ans=max(ans, a[i]*(right[i]-left[i]-1));
    }
    return ans;
}
int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    cout<<max_area(a, n);
}
