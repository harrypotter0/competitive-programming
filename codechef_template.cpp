#include <bits/stdc++.h>
using namespace std;

#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize ("O3")
#pragma GCC optimize ("O2")
#pragma GCC optimize("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")


#define int long long
#define pb emplace_back
#define mp make_pair
#define endl "\n"
#define sz(x) (int)x.size()
#define aint(v) v.begin(), v.end()
#define x first
#define y second
#define rep(i, j, k) for(i=j; i<k; i++)
#define sep(i, j, k) for(i=j; i>k; i--)
#define ios ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define watch(x) cout << (#x) << " is " << (x) << endl
const int mod = 1e9+7;
const int N = 1e6+5;

typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vll;
typedef set<int> si;
typedef map<int,int> mii;

int fast_pow(int a, int b){
	int res = a, ret = 1;
	while(b>0){
		if(b%2)
			ret = (ret*res)%mod;
		res = (res*res)%mod;b/=2;
	}
	return ret;
}

void solve()
{
    int i, j,k, a, b, sum = 0,c=0;
    int n, m,l;
    int arr[N];
    cin>>n>>k;
    
}

signed main()
{
    ios
    int i, t=1, j, x;
    cin>>t;
    time_t time_t1, time_t2;
    time_t1 = clock();

    while(t--)
        solve();

    time_t2 = clock();
    // cout << "time taken :" << time_t2 - time_t1 << endl;
    return 0;
}
