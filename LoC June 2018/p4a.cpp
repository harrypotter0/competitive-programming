    #include<bits/stdc++.h>
     
    #define ll          long long
    #define vi          vector<ll int>
    using namespace std;
     
    #define N  10005
     
    vi a(N,0),seg(4*N,0),lazy(4*N,-1);
    void build(ll cur,ll st,ll end)
    {
    	if(st==end)
    	{
    		seg[cur]=a[st];
    		return;
    	}
    	ll mid=(st+end)>>1;
    	build(2*cur,st,mid);
    	build(2*cur+1,mid+1,end);
    	seg[cur]=seg[2*cur]+seg[2*cur+1];					/* 1-change */
    }
    void updaterange(ll cur,ll st,ll end,ll l,ll r,ll val)
    {
    	if(lazy[cur]!=-1)                                    /* 2-change */
    	{
    		seg[cur]=(end-st+1)*lazy[cur];					/* 3-change */
    		if(st!=end)
    		{
    			lazy[2*cur]=lazy[cur];						/* 4-change */
    			lazy[2*cur+1]=lazy[cur];                   /* 5-change */
    		}
    		lazy[cur]=-1;                                    /* 6-change */
    	}
    	if(st>end||st>r||end<l) return;
    	if(l<=st&&end<=r)
    	{
    		seg[cur]=(end-st+1)*val;					    /* 7-change */
    		if(st!=end)
    		{
    			lazy[2*cur]=val;                           /* 8-change */
    			lazy[2*cur+1]=val;                         /* 9-change */
    		}
    		return;
    	}
    	ll mid=(st+end)>>1;
    	updaterange(2*cur,st,mid,l,r,val);
    	updaterange(2*cur+1,mid+1,end,l,r,val);
    	seg[cur]=seg[2*cur]+seg[2*cur+1];                  /* 10-change */
    }
    ll query(ll cur,ll st,ll end,ll l,ll r)
    {
    	if(st>end||st>r||end<l) return 0;
    	if(lazy[cur]!=-1)
    	{
    		seg[cur]=(end-st+1)*lazy[cur];                /* 11-change */
    		if(st!=end)
    		{
    			lazy[2*cur]=lazy[cur];                    /* 12-change */
    			lazy[2*cur+1]=lazy[cur];                  /* 13-change */
    		}
    		lazy[cur]=-1;
    	}
    	if(st>=l&&end<=r) return seg[cur];
    	ll mid=(st+end)>>1;
    	ll ans1=query(2*cur,st,mid,l,r);
    	ll ans2=query(2*cur+1,mid+1,end,l,r);
    	return ans1+ans2;                                 /* 14-change */
    }
     
    int main()
    {
    	ios_base::sync_with_stdio(false);
    	cin.tie(0);
    	cout.tie(0);
    	int TESTS=1;
    //	cin>>TESTS;
    	while(TESTS--)
    	{
    		ll int n;
    		cin>>n;
    		build(1,1,10000);
    		ll int ans=0;
    		for(ll int i=1;i<=n;i++)
    		{
    			ll int tmp;
    			cin>>tmp;
    			ans+=query(1,1,10000,tmp+1,N);
    			updaterange(1,1,10000,tmp+1,N,0);
    			updaterange(1,1,10000,tmp,tmp,1);
    		}
    		ans+=query(1,1,10000,1,10000);
    		updaterange(1,1,10000,1,10000,0);
    		cout<<ans;
    	}
    	return 0;
    } 