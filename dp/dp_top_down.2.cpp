#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=405;

int n, k, x;
int a[N];
int cache[N][N];

int dp(int idx, int taken)
{
	if(taken>x)
		return -1e15;
	if(taken==x && idx+k-1>n)
		return 0;
	if(idx>n)
	{
		if(taken==x)
			return 0;
		return -1e15;
	}
	int &ans=cache[idx][taken];
	if(ans!=-1)
		return ans;
	ans=-1e15;
	for(int j=idx;j<=min(idx+k-1, n);j++)
		ans=max(ans, a[j] + dp(j+1, taken+1));
	return ans;
}

int32_t main()
{
	IOS;
	memset(cache, -1, sizeof(cache));
	cin>>n>>k>>x;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	int ans=dp(1, 0);
	if(ans<0)
		ans=-1;
	cout<<ans;
	return 0;
}

