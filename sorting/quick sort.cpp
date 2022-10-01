#include<bits/stdc++.h>
using namespace std;
int partition(int a[], int s, int e){
    int pivot=a[e];
    int j=s-1;
    for(int i=s;i<e;i++){
        if(a[i]<pivot){
           j++;
            swap(a[i], a[j]);
        }
    }
    
    swap(a[j+1], a[e]);
    return j+1;
}
void quick_sort(int a[], int s, int e){
    if(s<e){
        
    
    int p=partition(a, s, e);
    quick_sort(a, 0, p-1);
    quick_sort(a, p+1, e);
    }
}
int main(){
    int n, a[10];
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    quick_sort(a, 0, n-1);
    for(int i=0;i<n;i++){
        cout<<a[i];
    }
}
