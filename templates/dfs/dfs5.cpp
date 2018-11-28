#include <bits/stdc++.h>
using namespace std;

#define LL long long
#define PB push_back
#define N 100010
#define MD 99991
#define SZ 201000
#define LB lower_bound
#define M 1000000007
#define UB upper_bound
#define MP make_pair
#define LD long double
#define F first
#define S second

LL fac[2*N],sm[N],smn[N];
vector<LL> adj[N];
LL dfs(LL x,LL p)
{
	LL cr=1;
	for(LL ch:adj[x])
		if(ch!=p)
			cr+=dfs(ch,x);
	sm[x]=cr;
	return cr;
}
LL dfs2(LL x,LL p)
{
	LL cr=sm[x];
	for(LL ch:adj[x])
		if(ch!=p)
			cr+=dfs2(ch,x);
	smn[x]=cr;
	return cr;
}
int main()
{
    LL lt,no,i,j,x,d,k,z,q,y,m,v,x1,y1,n,l,r,p;
    LL a[N],b[N];
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
	cin>>lt;
	fac[0]=1;
	for(i=1;i<2*N;i++)
		fac[i]=(fac[i-1]*i)%MD;
	while(lt--)
	{
		cin>>n;
		for(i=1;i<=n;i++)
			adj[i].clear();
		for(i=1;i<n;i++)
		{
			cin>>x>>y;
			adj[x].PB(y);
			adj[y].PB(x);
		}
		dfs(1,0);
		dfs2(1,0);
		cin>>q;
		while(q--)
		{
			cin>>x;
			y=smn[x];
			if(y<100000)
				cout<<fac[y]<<"\n";
			else
			cout<<"0\n";
		}
	}
}