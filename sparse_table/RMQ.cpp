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
#define sz(a) (int)a.size()
#define rep(i,a,b) for(int i=(int)a;i<=(int)b;i++)
#define sep(i,a,b) for(int i=(int)a;i>=(int)b;i--)
#define inf 0x3f3f3f3f
#define pb push_back
#define mp make_pair
#define lb lower_bound
#define ub upper_bound
#define all(a) a.begin(),a.end()
#define x first
#define y second
#define endl "\n"
#define n6 3000005
#define n3 3005
#define n5 300005
 
#define pi pair<int,int>
#define pii pair<int,pi>
 
#define dbg1(x)                cout << #x << ": " << x << endl;
#define dbg2(x, y)             cout << #x << ": " << x << " | " << #y << ": " << y << endl;
#define dbg3(x, y, z)          cout << #x << ": " << x << " | " << #y << ": " << y << " | " << #z << ": " << z << endl;
#define dbg4(a, b, c, d)       cout << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << endl;
#define dbg5(a, b, c, d, e)    cout << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << " | " << #e << ": " << e << endl;
#define dbg6(a, b, c, d, e, f) cout << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << " | " << #e << ": " << e << " | " << #f << ": " << f << endl;
 
#define dbg(...) fprintf(stderr, __VA_ARGS__)
#define dbgv(x) cout << #x << " = " << x << endl
#define dbga(arr, len) {cout << #arr << " = "; for (int _ = 0; _ < len; _++)\
cout << arr[_] << " "; cout << endl;}
#define dbgi(it) {cout << #it << " = "; for (const auto& _ : it)\
cout << _ << " "; cout << endl;}
 
const int md = (int) 1e9 + 7;
 
inline void add(int &a, int b) {
  a += b;
  if (a >= md) a -= md;
}
 
inline void sub(int &a, int b) {
  a -= b;
  if (a < 0) a += md;
}
 
inline int mul(int a, int b) {
  return (int) ((long long) a * b % md);
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
 
 
void solve_util(int m, int &cnt, int &sum){
 
    
}
 
const int K = 27;
int st[n5][K];
int arr[n5];
const int ZERO = 0; // ZERO + x = x + ZERO = x (for any x)
int n;

int logi[n5];
void precompute_log(){
    logi[1] = 0;
    for (int i = 2; i <= n5; i++)
        logi[i] = logi[i/2] + 1;
}

int range_sum(int L, int R){
    long long sum = 0;
    for (int j = K; j >= 0; j--) {
        if ((1 << j) <= R - L + 1) {
            sum += st[L][j];
            L += 1 << j;
        }
    }
    return sum;
} 

int func(int a, int b){
    return __gcd(a,b);
}

// build Sparse Table
void build_sparse_table(){  
    
    for (int i = 0; i < n; i++)
        st[i][0] = arr[i];
    
    for (int j = 1; j <= K; j++)
        for (int i = 0; i + (1 << j) <= n; i++){
            st[i][j] = func(st[i][j-1], st[i + (1 << (j - 1))][j - 1]);
        }
            
}

// Query here !!
int ans = 0; 
int RMQ(int L, int R){

    int j = logi[R - L + 1];
    int maxi = func(st[L][j], st[R - (1 << j) + 1][j]);
    return maxi;
}


void solve(){
    int l, r, q;
    cin >> n; // array size
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    build_sparse_table();
    cin>>q;
    while(q--){
        cin>>l>>r;
        l--;r--;
        // dbgv(l);dbgv(r);
        cout<<RMQ(l,r)<<endl;
    }
    
}
 
signed main()
{
    FAST; FIXED; RANDOM;
    int t=1;
    precompute_log();
    // cin>>t;
    // time_t time_t1, time_t2;
    // time_t1 = clock();
    while(t--)
        solve();
 
    // time_t2 = clock();
    // cout << "time taken :" << time_t2 - time_t1 << endl;
    return 0;
} 