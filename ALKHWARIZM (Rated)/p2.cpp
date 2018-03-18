#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define M 1000000007
#define MAX 300005

//ll powmod(ll a,ll b) {ll res=1;a%=M; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%M;a=a*a%M;}return res%M;}


int main()
{

    ios::sync_with_stdio(false);

    int n,k;
    cin>>k>>n;

    int arr[n];

    ll sol[k+1][2];
    for(int i=0;i<=k;i++)
        sol[i][0]=LONG_LONG_MAX, sol[i][1]=LONG_LONG_MIN;


    for(int i=0;i<n;i++)
        cin>>arr[i];

    sol[0][0]=0, sol[0][1]=0;


    for(int i=0;i<n;i++){
        for(ll j=1;j*arr[i]<=k;j++){
            sol[j*arr[i]][0]=min(sol[j*arr[i]][0],j);
            sol[j*arr[i]][1]=max(sol[j*arr[i]][1],j);
        }
    }

    ll mi=LONG_LONG_MAX, ma=LONG_LONG_MIN;

    for(int i=0;i<k;i++){
        if(sol[i][0]!=LONG_LONG_MAX&&sol[k-i][0]!=LONG_LONG_MAX){
            mi=min(mi,sol[i][0]+sol[k-i][0]);
            ma=max(ma,sol[i][1]+sol[k-i][1]);
        }
    }

    if(mi==LONG_LONG_MAX)
        cout<<-1<<" "<<-1;
    else
    cout<<mi<<" "<<ma<<endl;

}
