#include<bits/stdc++.h>
using namespace std;
int main(){
    int n, a[10];
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int point=1;
    while(point<n){
        for(int i=0;i<n-point;i++){
            if(a[i]>a[i+1]){
                int temp=a[i+1];
                a[i+1]=a[i];
                a[i]=temp;
            }
        }
        point++;
    }
    for(int i=0;i<n;i++){
        cout<<a[i]<<endl;
    }
}
