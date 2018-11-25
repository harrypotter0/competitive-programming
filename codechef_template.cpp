#pragma GCC optimize("O3", "unroll-loops")
/////////////////////////////////////////////
// Yeah, yeah oh
// Yeah, yeah baby
// Yeah, yeah yeah yeah
// No, no, no, no, yeah
// Girl your body is legit
// Mama made you thick
// Don't know why you wonder why them other hoes talk shit
// I see sex in your eyes
// Sex between your thighs
// I don't play no games
// You're my candy crush all night
// Can I put my face in your water?
// I know it's out of order
// He can't do the things that I do
// Know the tricks that I knew
// Don't know why you acting brand new
// She can't get the Snickers from another nigga
// She know what I did with the Twix
// My ex girlfriend can't stand her
// 'Cause a new man hit her with a Jolly Rancher
// And I want ya, call me your Willy Wonka (Willy Wonka)
// And I want ya, call me your Willy Wonka, girl
// And I want ya, call me your Willy Wonka
// Yeah I know they after me
// I got that chocolate factory
// Come through, come through, lil' mama come through
// If you know what's good for you
// If you know what's good for you
// Come through, come through, lil' shawty come through
// If you know what's good for you
// If you know what's good for you
// Girl your body is legit
// Mama made you thick
// Don't know why you wonder why your ex man so sick
// She want Pretty Ricky and Plies, every time she rides
// Back shots to Jodeci, that's 9 to 5 all night
// Don't really know if I love her, mmm mmm, but I love when she's going under
// Taste like Aquafina baby, '98 Trina
// Girl, I want you three back in, I get her to lead her, you
// She can't get the Snickers from another nigga
// She know what I did with the Twix
// My ex girlfriend can't stand her
// 'Cause a new man hit her with that Jolly Rancher
// And I want ya, call me your Willy Wonka (Willy Wonka)
// And I want ya, call me your Willy Wonka, girl
// And I want ya, call me your Willy Wonka
// Yeah I know they after me
// I got that chocolate factory
// Come through, come through, lil' mama come through
// If you know what's good for you
// If you know what's good for you
// Come through, come through, lil' shawty come through
// If you know what's good for you
// If you know what's good for you
// Ah, yeah, oh, ah, yeah, come through baby
// 'Cause I got, oh, I got what you need, I got what you need, oh, hey, oh, yeah
// She can't get the Snickers from another nigga
// She know what I did with the Twix, aha
// My ex girlfriend can't stand her (she can't stand her)
// 'Cause a new man hit her with that Jolly Rancher, oh
// And I want ya, call me your Willy Wonka, ah
// And I want ya, call me your Willy Wonka (Willy Wonka)
// And I want ya, call me your Willy Wonka
// Yeah I know they after me
// I got that chocolate factory
// Come through, come through, lil' mama come through
// If you know what's good for you
// If you know what's good for you
// Come through, come through, lil' shawty come through
// If you know what's good for you
// If you know what's good for you (yeah)
/////////////////////////////////////////////////

#include <bits/stdc++.h>
using namespace std;
 
#define FILES freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout)
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define FIXED cout << fixed << setprecision(20)
#define RANDOM srand(time(nullptr))
#define ll long long
#define MOD 1000000007
#define sz(a) (ll)a.size()
#define pll pair<ll,ll>
#define rep(i,a,b) for(ll i=(ll)a;i<(ll)b;i++)
#define sep(i,a,b) for(ll i=(ll)a;i>=(ll)b;i--)
#define mll map<ll,ll>
#define vl vector<ll>
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define all(a) a.begin(),a.end()
#define F first
#define S second
#define MAXN6 3000005
#define MAXN3 3005
#define MAXN5 300005
#define watch(x) cout << (#x) << " is " << (x) << endl

inline ll add(ll a, ll b) {
    a += b;
    if (a >= MOD) a -= MOD;
    return a;
}
inline ll sub(ll a, ll b) {
    a -= b;
    if (a < 0) a += MOD;
    return a;
}
inline ll mul(ll a, ll b) {
    return (ll) a * b % MOD;
}
inline ll mpow(ll base, ll ex, ll mod = MOD) {
    ll res = 1;
    while (ex > 0) {
        if (ex & 1) res = (long long) res * base % mod;
        base = (long long) base * base % mod;
        ex >>= 1;
    }
    return res;
}

void solve()
{
    ll n,i,j,m,k;
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
    // cerr << "time taken :" << time_t2 - time_t1 << endl;
    return 0;
}

