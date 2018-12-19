#pragma GCC optimize("O3", "unroll-loops")
// God Help me !!
#include <bits/stdc++.h>
using namespace std;
// #define watch(x) cout << (#x) << " is " << (x) << endl

#define FILES freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout)
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define FIXED cout << fixed << setprecision(20)
#define RANDOM srand(time(nullptr))
#define int long long
#define MOD 1000000007
#define sz(a) (ll)a.size()
#define pll pair<ll,ll>
#define rep(i,a,b) for(int i=(int)a;i<(int)b;i++)
#define sep(i,a,b) for(int i=(int)a;i>=(int)b;i--)
#define mll map<int,int>
#define vl vector<int>
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define all(a) a.begin(),a.end()
#define F first
#define S second
#define endl "\n"
#define MAXN6 3000005
#define MAXN3 3005
#define MAXN5 300005

#define watch(...) ZZ(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1> void ZZ(const char* name, Arg1&& arg1){std::cerr << name << " = " << arg1 << endl;}
template <typename Arg1, typename... Args>void ZZ(const char* names, Arg1&& arg1, Args&&... args)
{
	const char* comma = strchr(names + 1, ',');
	std::cerr.write(names, comma - names) << " = " << arg1;
	ZZ(comma, args...);
}
 
inline int add(int a, int b) {
    a += b;
    if (a >= MOD) a -= MOD;
    return a;
}
inline int sub(int a, int b) {
    a -= b;
    if (a < 0) a += MOD;
    return a;
}
inline int mul(int a, int b) {
    return (int) a * b % MOD;
}
inline int mpow(int base, int ex, int mod = MOD) {
    int res = 1;
    while (ex > 0) {
        if (ex & 1) res = (long long) res * base % mod;
        base = (long long) base * base % mod;
        ex >>= 1;
    }
    return res;
}

void solve()
{
    int n,i,j,m,k;
    cin>>n;

}

signed main()
{
    FAST; FIXED; RANDOM;
    int i, t=1, j, x;

    cin>>t;
    time_t time_t1, time_t2;
    time_t1 = clock();

    while(t--)
        solve();

    time_t2 = clock();
    cerr << "time taken :" << time_t2 - time_t1 << endl;
    return 0;
}

