#include<bits/stdc++.h>
using namespace std;
// Poori Duniya bhadwi hai
#define assn(n,a,b) assert(n<=b && n>=a)
#define pb push_back
#define mp make_pair
#define clr(x) x.clear()
#define sz(x) ((int)(x).size())
#define F first
#define S second
#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,b) for(i=0;i<b;i++)
#define rep1(i,b) for(i=1;i<=b;i++)
#define pdn(n) printf("%d\n",n)
#define sl(n) scanf("%lld",&n)
#define sd(n) scanf("%d",&n)
#define pn printf("\n")
typedef pair<int,int> PII;
typedef vector<PII> VPII;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef long long LL;
#define MOD 1000000007
LL mpow(LL a, LL n) 
{LL ret=1;LL b=a;while(n) {if(n&1) 
	ret=(ret*b)%MOD;b=(b*b)%MOD;n>>=1;}
return (LL)ret;}
int prime[16]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47};
int dp[102][(1<<15)+10]={};
int arr[105];
int p,n;

O(2^15*15*n)
int solve(int cur, int mask)
{
	if(cur==n || mask==((1<<n)-1))return 0;
	if(dp[cur][mask]!=-1)return dp[cur][mask];
	int q=solve(cur+1,mask);
	if(arr[cur]==1)return dp[cur][mask]=q+1;
	int temp=mask;
	for(int i=0; i<15; i++)
		if(arr[cur]%prime[i]==0)
		{
			if(mask&(1<<i))return dp[cur][temp]=q;
			mask=mask|(1<<i);
		}
	return dp[cur][temp]=max(1+solve(cur+1,mask),q);
}

int main()
{
	int t;
	cin >> t;
	assn(t,1,10);
	// cout << t << endl;
	while(t--)
	{
		cin >> n;
		// cout << n << endl;
		assn(n,1,50);
		for(int i=0; i<n; i++)
		{
			cin >> arr[i];
			// if(i!=n-1)cout << arr[i] << " ";
			// else cout << arr[i] << "\n";
			assn(arr[i],1,50);
		}
		//p=(1<<n)-1;
		memset(dp,-1,sizeof(dp));
		cout << solve(0,0) << endl;
	}
	return 0;
}

