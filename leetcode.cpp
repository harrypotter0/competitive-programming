// God Help me !!
#pragma GCC optimize ("O3")
#include<bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define FILES freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout)
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define FIXED cout << fixed << setprecision(20)
#define RANDOM srand(time(nullptr))
#define sz(a) (int)a.size()
// #define int long long 

#define V vector
typedef long double LD;
typedef pair<int, int> pii;
typedef V<int> vi;
typedef V<string> vs;
typedef V<double> vd;
#define pi pair<int,int>
typedef V<pi> vpi;
#define pii pair<int,pi>
#define pqq priority_queue<pi, vector<pi>, greater<pi> > 

#define rep(i,a,b) for(int i=(int)a;i<=(int)b;i++)
#define sep(i,a,b) for(int i=(int)a;i>=(int)b;i--)
#define inf 0x3f3f3f3f
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define pf push_front
#define popb pop_back
#define popf pop_front
#define lb lower_bound
#define ub upper_bound
#define all(a) a.begin(),a.end()
#define ff first
#define ss second
#define endl "\n"
#define n6 3000005
#define n3 3005
#define n5 300005

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
// template<typename T>
// using ordered_set = __gnu_pbds::tree<T, __gnu_pbds::null_type, less<T>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>; // find_by_order(), order_of_key()
template <class T> inline void ckmax(T &x, T y) {if (y > x) x = y; }
template <class T> inline void ckmin(T &x, T y) {if (y < x) x = y; }

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


const int MOD = 1e9 + 7;
const long long INF = 1e18;
const double EPS = 1e-6;
/*******************************************************************************//*******************************************************************************/
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
inline int power(int a, long long b) {
  int res = 1;
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



void solve_util(int x, int y){

}


void solve(){

    
}


class Solution {
public:
    int maxWidthRamp(vector<int>& arr) {
        int n = arr.size();
        vpi v;
        rep(i,0,n-1){
            v.pb({arr[i],i});
        }
        sort(all(v));
        int ans=0,v1=v[0].ss;
        rep(i,0,n-1){
            ckmax(ans,v[i].ss-v1);
            ckmin(v1,v[i].ss);
        }
        return ans;
    }
};


