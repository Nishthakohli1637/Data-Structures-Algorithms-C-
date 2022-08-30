#include<bits/stdc++.h>
using namespace std;
void search(int a[10][10], int n, int key){
    int i=0;
    int j=n-1;
    while(i>=0 && i<n && j>=0 && j<n){
        if(a[i][j]==key){
            cout<<i<<" "<<j;
            return;
        }
        else if(a[i][j]>key){
            j--;
        }
        else if(a[i][j]<key){
            i++;
        }
    }
    cout<<"-1";
    return;
}
int main(){
    int n, a[10][10];
    cin>>n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>a[i][j];
        }
    }
    int key;
    cin>>key;
   search(a, n, key);
}
