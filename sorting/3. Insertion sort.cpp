#include<bits/stdc++.h>
using namespace std;
int main(){
    int n, a[10];
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=1;i<n;i++){
        int curr=a[i];
        int j=i-1;
        while(a[j]>curr && j>=0){
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=curr;
    }
    for(int i=0;i<n;i++){
        cout<<a[i]<<endl;
    }
}
