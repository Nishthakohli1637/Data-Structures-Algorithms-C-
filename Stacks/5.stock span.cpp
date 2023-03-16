#include<bits/stdc++.h>
using namespace std;
vector<int> stock_span(int a[], int n){
    stack<pair<int, int>> s;
    vector<int> ans;
    for(int i=0;i<n;i++){
        if(s.empty()){
            ans.push_back(-1);
        }
        else if(!s.empty() && s.top().first>a[i]){
            ans.push_back(s.top().second);
        }
        else if(!s.empty() && s.top().first<=a[i]){
            while(!s.empty() && s.top().first<=a[i]){
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
    for(int i=0;i<ans.size();i++){
        ans[i]=i-ans[i];
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
    vector<int> v=stock_span(a, n);
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
}
