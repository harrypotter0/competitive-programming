// lazy propogation for multiple updates

#include<bits/stdc++.h>
#define mod 1000000007
#define N 400010
using namespace std;
long long sum[N],cov[N],cvo[N];
int L,R,n,m,i,x,t,v,c1,c2;
void update(int x,int cur)
{
	c1=cur<<1;c2=c1|1;
	sum[c1]=(sum[c1]*cvo[cur]+cov[cur]*(x+1>>1))%mod;
	sum[c2]=(sum[c2]*cvo[cur]+cov[cur]*(x>>1))%mod;
	(cvo[c1]*=cvo[cur])%=mod;(cvo[c2]*=cvo[cur])%=mod;
	cov[c1]=(cov[c1]*cvo[cur]+cov[cur])%mod;
	cov[c2]=(cov[c2]*cvo[cur]+cov[cur])%mod;
	cov[cur]=0;cvo[cur]=1;
}
void change(int l,int r,int x,int cur)
{
	if(L<=l&&R>=r)
	{
		sum[cur]=1ll*x*(r-l+1)%mod;
		cov[cur]=x;cvo[cur]=0;
		return;
	}
	update(r-l+1,cur);
	int mid=(l+r)>>1;
	if(L<=mid)change(l,mid,x,cur<<1);
	if(R>mid)change(mid+1,r,x,cur<<1|1);
	sum[cur]=(sum[cur<<1]+sum[cur<<1|1])%mod;
}
void add(int l,int r,int x,int cur)
{
	if(L<=l&&R>=r)
	{
		(sum[cur]+=1ll*(r-l+1)*x%mod)%=mod;
		(cov[cur]+=x)%=mod;return;
	}
	update(r-l+1,cur);
	int mid=(l+r)>>1;
	if(L<=mid)add(l,mid,x,cur<<1);
	if(R>mid)add(mid+1,r,x,cur<<1|1);
	sum[cur]=(sum[cur<<1]+sum[cur<<1|1])%mod;
}
void multi(int l,int r,int x,int cur)
{
	if(L<=l&&R>=r)
	{
		(sum[cur]*=x)%=mod;
		(cov[cur]*=x)%=mod;
		(cvo[cur]*=x)%=mod;return;
	}
	update(r-l+1,cur);
	int mid=(l+r)>>1;
	if(L<=mid)multi(l,mid,x,cur<<1);
	if(R>mid)multi(mid+1,r,x,cur<<1|1);
	sum[cur]=(sum[cur<<1]+sum[cur<<1|1])%mod;
}
int query(int l,int r,int cur)
{
	if(L<=l&&R>=r)return sum[cur];
	update(r-l+1,cur);
	int mid=(l+r)>>1,ans=0;
	if(L<=mid)ans=query(l,mid,cur<<1);
	if(R>mid)ans+=query(mid+1,r,cur<<1|1);
	return ans%mod;
}
int main()
{
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&x);L=R=i;
		change(1,n,x,1);
	}
	while(m--)
	{
		scanf("%d%d%d",&t,&L,&R);
		if(t==1)
		{
			scanf("%d",&v);
			add(1,n,v,1);
		}
		if(t==2)
		{
			scanf("%d",&v);
			multi(1,n,v,1);
		}
		if(t==3)
		{
			scanf("%d",&v);
			change(1,n,v,1);
		}
		if(t==4)printf("%d\n",query(1,n,1));
	}
}