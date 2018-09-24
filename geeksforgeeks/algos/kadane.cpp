#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int kadane(int arr[], int n){
    int max_ending_here=0,max_so_far=-1e9,s=0,start=0,e=0;
    for(int i =0;i<n;i++){
        max_ending_here+=arr[i];
        if(max_ending_here>max_so_far){
            max_so_far = max_ending_here;
            start=s;
            e=i;
        }
        if(max_ending_here<0){
            max_ending_here=0;
            s=i+1;
        }        
    }
    return max_so_far;
}

int main()
 {
	//code
	int t;cin>>t;
    while(t--){
        int n; cin>>n;
        int arr[1000]={0};
        for(int i=0;i<n;i++)cin>>arr[i];
        int ans = kadane(arr,n);
        cout<<ans<<endl;
    }
	return 0;
}