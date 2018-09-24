#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int LCS(char*X, char*Y, int m, int n){
    int L[m+1][n+1];
    for(int i=0;i<=m;i++){
        for(int j=0;j<=n;j++){
            if(i==0 || j==0)
                L[i][j]=0;
            else if (X[i-1]==Y[j-1])
                L[i][j]=L[i-1][j-1]+1;
            else 
                L[i][j]=max(L[i][j-1],L[i-1][j]);
        }
    }
    // for(int i=0;i<=m;i++){
    //     for(int j=0;j<=n;j++){
    //         cout<<L[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    return L[m][n];
}
int main()
 {
	//code
	int t;cin>>t;
	char a[1005],b[1005];
    
	while(t--){
        int n,m;cin>>m>>n;
        cin>>a>>b;
        int ans = LCS(a,b,m,n);
        cout<<ans<<endl;
	}
	return 0;
}