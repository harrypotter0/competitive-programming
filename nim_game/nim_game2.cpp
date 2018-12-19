// Normal Nim : the player that cannot make a move loses
#pragma GCC optimize("O3", "unroll-loops")
// God help me !!
#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <deque>
#include <queue>
#include <unordered_set>
#include <unordered_map>
#include <ctime>
#include <complex>
#include <random>
#include <bitset>
#include <algorithm>
#include <fstream>
#include <tuple>
#include <sstream>
#include <functional>
using namespace std;
 
#define FILES freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout)
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define FIXED cout << fixed << setprecision(20)
#define RANDOM srand(time(nullptr))
#define pb push_back
#define pf push_front
#define popb pop_back
#define popf pop_front
#define mp make_pair
#define hashmap unordered_map
#define hashset unordered_set
#define ll long long
#define ld long double
#define ui unsigned int
#define ull unsigned ll
#define pii pair<int, int>
#define pll pair<ll, ll>
#define graph vector<vector<int>>
#define eps 1e-9
#define MOD 1000000007
#define inf 1000000000000000007ll
#define intinf ((1 << 31) - 1)
#define f first
#define s second
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define sz(a) int(a.size())
#define shuffle(a) \
    for (int i = -sz(a); i < sz(a); ++i) \
        swap(a[rand() % sz(a)], a[rand() % sz(a)])
#define N5 3000005
#define N3 3005
#define watch(x) cout << (#x) << " is " << (x) << endl

template<class T> inline void sort(T &a) { sort(all(a)); }
template<class T> inline void rsort(T &a) { sort(rall(a)); }
template<class T> inline void reverse(T &a) { reverse(all(a)); }
template<class T, class U> inline void checkmin(T &x, U y) { if (x > y) x = y; }
template<class T, class U> inline void checkmax(T &x, U y) { if (x < y) x = y; }


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
    return (long long) a * b % MOD;
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

/*
2
2 Dee
101
010
2 Dum
101
010

*/
string solve_util(const vector<string>& stacks, const string& first){
    int a=0, b=0;
    for(const auto& stack : stacks){
        if(stack[0]=='0')a+=count(stack.begin(), stack.end(), '0'); // counting the number of 0's in a stack as the player startng with the 0's will try to utilize all the 0's in a stack 
        if(stack[0]=='1')b+=count(stack.begin(), stack.end(), '1'); // viceversa
    }
    if(a==b)return (first=="Dee" ? "Dum":"Dee"); // if similar no of moves possible for a and b then the answer is the second player to start // Normal Nim 
    else return(a>b ? "Dee": "Dum"); // else the one with more moves
}

void solve()
{
    int n;cin>>n;
    string str;cin>>str;
    vector<string> vec(n);
    for(int i=0;i<n;i++){
        cin>>vec[i];
    }
    cout<<solve_util(vec,str)<<endl;
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
    // cout << "time taken :" << time_t2 - time_t1 << endl;
    return 0;
}