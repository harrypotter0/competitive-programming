#pragma GCC optimize("O3", "unroll-loops")
// God Help me !!
#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define FILES freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout)
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define FIXED cout << fixed << setprecision(20)
#define RANDOM srand(time(nullptr))
#define sz(a) (int)a.size()
#define CLR(d) memset(d, 0, sizeof(d))

#define ll long long
#define ld long double
#define ui unsigned int
#define ull unsigned ll

#define graph vector<vector<int>>
#define V vector
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef V<int> vi;
typedef V<ll> vll;
typedef V<string> vs;
typedef V<double> vd;
typedef V<pii> vpii;             
typedef V<pll> vpll;             
typedef pair<int,pii> piii;             
typedef priority_queue<pii, vector<pii>, greater<pii> > pqq;             

#define shuffle(a) \
    for (int i = -sz(a); i < sz(a); ++i) \
        swap(a[rand() % sz(a)], a[rand() % sz(a)])

#define rep(i,a,b) for(int i=(int)a;i<=(int)b;i++)
#define sep(i,a,b) for(int i=(int)a;i>=(int)b;i--)
#define mp make_pair
#define eb emplace_back
#define pb push_back
#define pf push_front
#define popb pop_back
#define popf pop_front
#define hashmap unordered_map
#define hashset unordered_set
#define lb lower_bound
#define ub upper_bound
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define ff first
#define ss second
#define endl "\n"
#define n6 3000005
#define n7 30000005
#define n8 300000005
#define n3 3005
#define n5 300005
#define lbpos(v,x)              (int)(lower_bound(all(v),x)-v.begin())//=v.size()==>No LB 
#define ubpos(v,x)              (int)(upper_bound(all(v),x)-v.begin())//=v.size()==>No UB
/*******************************************************************************//*******************************************************************************/
#define dbg1(x)                cout << #x << ": " << x << endl;
#define dbg2(x, y)             cout << #x << ": " << x << " | " << #y << ": " << y << endl;
#define dbg3(x, y, z)          cout << #x << ": " << x << " | " << #y << ": " << y << " | " << #z << ": " << z << endl;
#define dbg4(a, b, c, d)       cout << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << endl;
#define dbg5(a, b, c, d, e)    cout << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << " | " << #e << ": " << e << endl;
#define dbg6(a, b, c, d, e, f) cout << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << " | " << #e << ": " << e << " | " << #f << ": " << f << endl;

#define dbg(...) fprintf(stderr, __VA_ARGS__)
#define dbgv(x) cout << #x << " = " << x << endl
#define dbga(arr, len) {cout << #arr << " = "; for (int _ = 0; _ < len; _++)cout << arr[_] << " "; cout << endl;}
#define dbgi(it) {cout << #it << " = "; for (const auto& _ : it)cout << _ << " "; cout << endl;}
/*******************************************************************************//*******************************************************************************/
template<class T> inline void sort(T &a) { sort(all(a)); }
template<class T> inline void rsort(T &a) { sort(rall(a)); }
template<class T> inline void reverse(T &a) { reverse(all(a)); }
template<class T, class U> inline void amin(T &x, U y) { if (x > y) x = y; }
template<class T, class U> inline void amax(T &x, U y) { if (x < y) x = y; }
/*******************************************************************************//*******************************************************************************/
#define error(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }
void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
	cout << *it << " =: " << a << endl;
	err(++it, args...);
}
template <typename T1, typename T2>
inline std::ostream& operator << (std::ostream& os, const std::pair<T1, T2>& buf) {
    return os << "(" << buf.first << ": " << buf.second << ")";
}
template<typename T>
inline std::ostream &operator << (std::ostream & os,const std::vector<T>& v) {
    bool first = true;
    os << "[";
    for(unsigned int i = 0; i < v.size(); i++) {
        if(!first) os << ", ";
        os << v[i];
        first = false;
    }
    return os << "]";
}
template<typename T>
inline std::ostream &operator << (std::ostream & os,const std::set<T>& v) {
    bool first = true;
    os << "{";
    for (typename std::set<T>::const_iterator ii = v.begin(); ii != v.end(); ++ii) {
        if(!first) os << ", ";
        os << *ii;
        first = false;
    }
    return os << "}";
}
template<typename T1, typename T2>
inline std::ostream &operator << (std::ostream & os,const std::map<T1, T2>& v) {
    bool first = true;
    os << "{";
    for (typename std::map<T1, T2>::const_iterator ii = v.begin(); ii != v.end(); ++ii) {
        if(!first) os << ", ";
        os << *ii ;
        first = false;
    }
    return os << "}";
}
template<typename T>
inline std::ostream &operator << (std::ostream & os,const vector<vector<T>>& v) {
    os << '\n';
    for (auto &u: v) os << u << '\n';
    return os;
}
/*******************************************************************************//*******************************************************************************/
template <size_t r, size_t c>
void printmatrix(int (&arr)[r][c], int r1, int c1)
{

	for (size_t i = 1; i <= r1; i++)
	{
		for (size_t j = 1; j <= c1; j++){
		    cout<<arr[i][j]<<" ";
		}
    	cout<<"\n";
	}
	cout<<"\n***********\n";
}
void showdq(deque <int> g) 
{ 
    for (auto it = g.begin(); it != g.end(); ++it) 
        cout << *it << ' ' ; 
    cout << '\n'; 
} 

void showstack(stack <int> s) 
{ 
    while(!s.empty()){
        cout << s.top() << ' ';
        s.pop();
    }    
    cout << '\n';
    
} 

void showqueue(queue<int> q)
{
    while(!q.empty()){
        cout << q.front() << ' ';
        q.pop();
    }    
    cout << '\n';
}

void showpq(priority_queue <int> gq) 
{ 
    priority_queue <int> g = gq; 
    while (!g.empty()) 
    { 
        cout << '\t' << g.top(); 
        g.pop(); 
    } 
    cout << '\n'; 
} 
/*******************************************************************************//*******************************************************************************/
const int mod = 1e9 + 7;
const double eps = 1e-9;
#define inf 1000000000000000007ll
#define intinf ((1 << 31) - 1)
/*******************************************************************************//*******************************************************************************/
inline ll add(ll a, ll b) {
    a += b;
    if (a >= mod) a -= mod;
    return a;
}
inline ll sub(ll a, ll b) {
    a -= b;
    if (a < 0) a += mod;
    return a;
}
inline ll mul(ll a, ll b) {
    return (long long) a * b % mod;
}
inline ll power(ll a, ll b) {
  ll res = 1;
  while (b > 0) {
    if (b & 1) {
      res = mul(res, a);
    }
    a = mul(a, a);
    b >>= 1;
  }
  return res;
}
/*******************************************************************************//*******************************************************************************/

// sort(vp.begin(), vp.end(), [](auto &l, auto &r){
//     if(l.second!=r.second)
//         return l.second > r.second;
//     return l.first < r.first;
// }); 

// > descend
// < ascend


void solve(){

}


signed main()
{
    FAST; FIXED; RANDOM;
    int t=1;
    // cin>>t;
    // time_t time_t1, time_t2;
    // time_t1 = clock();
    while(t--)
        solve();

    // time_t2 = clock();
    // cout << "time taken :" << time_t2 - time_t1 << endl;
    return 0;
}