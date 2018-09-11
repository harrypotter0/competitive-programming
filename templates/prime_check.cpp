#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL),cout.tie(NULL);
    ll i,j,k;
    ll a[100007]={0};
    for(i=2;i<=100000;i++)
    {
        for(j=2*i;j<=100000;j+=i)
        a[j]++;
    }
    ll t;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        if(a[n]==0)
        cout<<-1;
        else
        cout<<a[n];
        cout<<endl;
    }
    return 0;
} 
