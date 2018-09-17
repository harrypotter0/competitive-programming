#include<bits/stdc++.h>
using namespace std; 

int XorPairCount_map(int arr[], int n, int x){
    int result = 0;
    unordered_map<int,int>m;
    for(int i=0;i<n;i++){
        int curr_xor = x^arr[i];
        if(m.find(curr_xor)!=m.end())
            result += m[curr_xor];
        m[arr[i]]++;
    }
    return result;
}


// driver program
int main()
{
    int t;cin>>t;
    while(t--){
        int n ;cin>>n;
        int arr[100000] = {0};
        for(int i=0;i<n;i++)cin>>arr[i];

    }
    return 0;
}