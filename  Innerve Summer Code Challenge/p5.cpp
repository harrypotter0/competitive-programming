#include <bits/stdc++.h>
 
#define ll long long
#define mx  200005
#define mod 1000000009
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
 
map<ll,int>mp;
 
int main(){
	ios_base::sync_with_stdio(false);
     int n,q;cin>>n>>q;
 
	while(n--)
	{
		ll a,b,c;cin>>a>>b;
		c=4*a*b+2*max(a,b);
		mp[c]++;
	}
 
	while(q--)
	{
		ll k;cin>>k;
		ll fre=mp[(k*(k+1))];
		if(fre)
		{
			cout<<power(fre,mod-2)<<"\n"; // inverse modulo
		}
		else
			cout<<"-1\n";
	}
	return 0;
}
