#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=205;

int n, k, x;
int a[N];
int cache[N][N][N];

int dp(int idx, int prev, int taken)
{
	if(prev>=k)
		return -1e15;
	if(taken>x)
		return -1e15;
	if(idx==n+1)
	{
		if(taken==x)
			return 0;
		return -1e15;
	}
	int &ans=cache[idx][prev][taken];
	if(ans!=-1)
		return ans;
	ans=max(dp(idx+1, prev+1, taken), a[idx]+dp(idx+1, 0, taken+1));
	return ans;
}

int32_t main()
{
	IOS;
	memset(cache, -1, sizeof(cache));
	cin>>n>>k>>x;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	int ans=dp(1, 0, 0);
	if(ans<0)
		ans=-1;
	cout<<ans;
	return 0;
}