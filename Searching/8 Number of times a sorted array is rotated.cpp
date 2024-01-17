#include<bits/stdc++.h>
using namespace std;
int rot_sort_times(int a[], int n){
    int s=0, e=n-1;
    while(s<=e){
        int mid=s+(e-s)/2;
        int prev=(mid+n-1)%n;
        int next=(mid+1)%n;
        if(arr[s]<=arr[e]){
            return s;
        }
        if(a[prev]>a[mid] && a[next]>a[mid]){
            return mid;
        }
        else if(a[mid]>=a[s]){
            s=mid+1;
        }
        else if(a[mid]<=a[e]){
            e=mid-1;
        }
    }
    return -1;
}
int main(){
    int n, a[10];
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    
    cout<<rot_sort_times(a, n);
}


APPROACH 2
    #include<bits/stdc++.h>
int findKRotation(vector<int> &arr){
    // Write your code here.
    int n=arr.size();
	int s=0, e=n-1;
	int ans=INT_MAX;
    int index=-1;
	while(s<=e){
		int mid=(s+e)/2;
        if(arr[s]<=arr[e]){
            ans=min(ans, arr[s]);
            if(ans==arr[s]){
                index=s;
            }
            break;
        }
		if(arr[s]<=arr[mid]){
			ans=min(ans, arr[s]);
            if(ans==arr[s]){
                index=s;
            }
			s=mid+1;
		}
		else{
			ans=min(ans, arr[mid]);
            if(ans==arr[mid]){
                index=mid;
            }
			e=mid-1;
		}
	}
	return index;    
}
