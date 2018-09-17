#include <bits/stdc++.h>
 
#define ll long long
#define mx  200005
#define mod 1000000007
#define lim 100
using namespace std;
 
 
ll power(ll a,ll b)
{
	ll x=1,y=a;
	while(b)
	{
		if(b%2)
		{
			x*=y;
			x%=mod;
		}
		b/=2;
		y*=y;
		y%=mod;
	}
	return x;
}
 
 
int main(){
	ios_base::sync_with_stdio(false);
 
	int t;cin>>t;
	while(t--)
	{
		ll n,k;cin>>n>>k;
 
		if(k==1)
		{
			cout<<1<<"\n";
			continue;
		} 
		ll nd=((1-power(k,n))+mod)%mod;
		ll rd=(power(1-k,mod-2)+mod)%mod;
        ll ans=(((rd*nd)%mod)*k)%mod;
 
		cout<<int(ans)<<"\n";
 
	}
	return 0;
}
