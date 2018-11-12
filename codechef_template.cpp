#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
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
#define REP(i,s,t) for(int i=(s);i<(t);i++)
#define FILL(x,v) memset(x,v,sizeof(x))
#define ios ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define watch(x) cout << (#x) << " is " << (x) << endl
const int mod = 1e9+7;
const int N = 3e6+5;

typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
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
    int n,k;
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
