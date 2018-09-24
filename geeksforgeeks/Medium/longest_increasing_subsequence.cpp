#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int lisdp(int arr[], int n){
    int lis[1005]={0};
    int maxi =1;
    for(int i=0;i<n;i++)
        lis[i]=1;                
    for(int i=1;i<n;i++){
        for(int j=0;j<i;j++)
            if(arr[i]>arr[j])
                lis[i]=max(lis[i],lis[j]+1);
            // if(arr[i]>arr[j] && lis[i]<lis[j]+1)
            //     lis[i]=lis[j]+1;
    }
    for(int i=0;i<n;i++)
        maxi = max(maxi, lis[i]);
    return maxi;
}

int main()
 {
	//code
	int t; cin>>t;
	int arr[1005]={0};
	while(t--){
	    int n,ans=0;cin>>n;
	    for(int i =0;i<n;i++)cin>>arr[i];
	    if(n!=0){
    	    ans = lisdp(arr, n);
    	    cout<<ans<<endl;
	    }
    	else
    	    cout<<ans<<endl;
	}
	return 0;
}