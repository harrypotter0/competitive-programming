#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#define ll long long
#define M 1000000007
#define sz(a) (ll)a.size()
#define pll pair<ll,ll>
#define rep(i,a,b) for(ll i=(ll)a;i<(ll)b;i++)
#define sep(i,a,b) for(ll i=(ll)a;i>=(ll)b;i--)
#define mll map<ll,ll>
#define vl vector<ll>
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define all(a) a.begin(),a.end()
#define F first
#define S second
using namespace __gnu_pbds;
using namespace std;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
#define MAXN 100005
#define MAXLOG 20
ll par[MAXN][MAXLOG],h[MAXN],n;
vl adj[MAXN];
void dfs(ll i)
{
    for(auto j:adj[i])
    {
        if(j!=par[i][0])
        {
            par[j][0]=i;
            h[j]=h[i]+1;
            dfs(j);
        }
    }
}
void preprocess()
{
    dfs(1);
    rep(j,1,MAXLOG)
    {
        rep(i,1,n+1)
        {
            if(par[i][j-1]!=-1)
            par[i][j]=par[par[i][j-1]][j-1];
        }
    }
}
ll LCA(ll u,ll v)
{
    if(h[u] < h[v])
        swap(u,v) ;     
    ll dist = h[u] - h[v] ; 
    while(dist > 0)
    {
        ll raise_by = log2(dist);
        u = par[u][raise_by];
        dist -= (1<<raise_by) ; 
    }
    if(u == v)
        return u ; 
    for(ll j = MAXLOG-1 ; j >= 0 ; --j)
    {
        if((par[u][j] != -1) && (par[u][j] != par[v][j]))
        {
            u = par[u][j] ; 
            v = par[v][j] ; 
        }
    }
    return par[u][0];
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    ll u,v;
    rep(i,0,n-1)
    {
    	cin>>u>>v;
    	adj[u].pb(v);
    	adj[v].pb(u);
    }
    preprocess();
    ll q;
    cin>>q;
    while(q--)
    {
    	cin>>u>>v;
    	ll p=LCA(u,v);
    	if(u==v)
    		cout<<0<<"\n";
    	else if(p==u||p==v)
    		cout<<1<<"\n";
    	else
    		cout<<2<<"\n";
    }
}
