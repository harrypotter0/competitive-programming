#include<bits/stdc++.h>
#define ll long long
using namespace std;
vector<ll> adj[1000006];
ll a[1000006];
ll dp[1000006];
void dfs(ll s,ll p)
{
    dp[s]=dp[p]^a[s];
    for(ll i=0;i<adj[s].size();i++)
    {
        if(adj[s][i]!=p)
        {
            dfs(adj[s][i],s);
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll n,x,y,q;
    cin>>n;
    for(ll i=0;i<n-1;i++)
    {
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    for(ll i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    dfs(1,0);
    cin>>q;
    while(q--)
    {
        cin>>x>>y;
        cout<<(dp[x]^dp[y])<<"\n";
    }
}
