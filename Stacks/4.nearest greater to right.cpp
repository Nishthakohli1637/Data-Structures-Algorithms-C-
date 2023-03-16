#include<bits/stdc++.h>
using namespace std;
vector<int> ngr(int a[], int n){
    stack<int> s;
    vector<int> ans;
    for(int i=n-1;i>=0;i--){
        if(s.empty()){
            ans.push_back(-1);
        }
        else if(!s.empty() && s.top()>a[i]){
            ans.push_back(s.top());
        }
        else if(!s.empty() && s.top()<=a[i]){
            while(!s.empty() && s.top()<=a[i]){
                s.pop();
            }
            if(s.empty()){
                ans.push_back(-1);
            }
            else{
                ans.push_back(s.top());
            }
        }
        s.push(a[i]);
    }
    reverse(ans.begin(), ans.end());
    return ans;
}
int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    vector<int> v=ngr(a, n);
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
}
