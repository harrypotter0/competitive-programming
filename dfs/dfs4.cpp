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
ll n,m,a[100005];
bool f(ll p)
{
	ll g=0;
	rep(i,0,n)
		g+=(p/a[i]);
	return g>=m;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll t;
    cin>>t;
    while(t--)
    {
    	cin>>n>>m;
    	rep(i,0,n)
    	cin>>a[i];
    	ll l=1,h=10000000000000000LL;
    	while(h-l>1)
    	{
    		ll mid=(l+h)/2;
    		if(f(mid))
    			h=mid;
    		else
    			l=mid;
    	}
    	if(f(l))
    		cout<<l<<"\n";
    	else
    		cout<<h<<"\n";
    }
    
}
