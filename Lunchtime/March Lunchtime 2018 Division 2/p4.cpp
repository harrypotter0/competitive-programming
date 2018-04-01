#include <stdio.h>
#include<iostream>
#include<set>
#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define MAX  1000005

int preSum[MAX];
void preprocess(int arr[],int n){
  preSum[0] = arr[0];
  for (int i = 1; i < n; i++) {
      preSum[i] = preSum[i - 1] + arr[i];
  }
}

int findSplit(int arr[], int n, int partu)
{
    int i;
    int index[n+1];
    int count = 0;
    int k = 0;
    int S = preSum[n - 1] / partu;
    // cout<<S<<"S ka value ";
    int f = 1;
    if(S == ((float)preSum[n - 1] / (float)partu))
    f=1;
    else
    f=0;
    // cout<<f<<"f value";

    for (i = 0; i < n; i++) {
        if (preSum[i] % S == 0 && f) {
            count++;
            index[k++] = i;
        }
    }

    if ( count==partu ) {
        return 1;
    }

    return 0;
}

int main()
{
int t;
cin>>t;
while(t--){
int arr[MAX]={0};
int ans[MAX]={0};
int n;
cin>>n;
for(int i=0;i<n;i++)cin>>arr[i];
ans[1]=1;
preprocess(arr,n);
for(int i=2;i<=n;i++){
    if (findSplit(arr, n, i) == 1){
        ans[i]=1;
    }
    else{
        ans[i]=0;
    }
}
for(int i=1;i<=n;i++){
    cout<<ans[i];
}
cout<<"\n";
}
return 0;
}
/*

Output:

10100
1101
1010
*/
