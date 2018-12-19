#pragma GCC optimize("O3", "unroll-loops")
// God Help me !!
#include <bits/stdc++.h>
using namespace std;

#define FILES freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout)
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define FIXED cout << fixed << setprecision(20)
#define RANDOM srand(time(nullptr))
#define int long long
#define sz(a) (int)a.size()

// #define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
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

#define pi pair<int,int>
#define pii pair<int,pi>

/*******************************************************************************/
    #define debug(args...)     (Debugger()) , args
 
    class Debugger
    {
        public:
        Debugger(const std::string& _separator = ", ") :
        first(true), separator(_separator){}
        
        template<typename ObjectType>
        Debugger& operator , (const ObjectType& v)
        {
            if(!first)
                std::cout << separator;
            std::cout << v;
            first = false;
            return *this;
        }
        ~Debugger() {  std::cout << endl;}
        
        private:
        bool first;
        std::string separator;
    };
 
    template <typename T1, typename T2>
    inline std::ostream& operator << (std::ostream& os, const std::pair<T1, T2>& p)
    {
        return os << "(" << p.first << ", " << p.second << ")";
    }
 
    template<typename T>
    inline std::ostream &operator << (std::ostream & os,const std::vector<T>& v)
    {
        bool first = true;
        os << "[";
        for(unsigned int i = 0; i < v.size(); i++)
        {
            if(!first)
                os << ", ";
            os << v[i];
            first = false;
        }
        return os << "]";
    }
 
    template<typename T>
    inline std::ostream &operator << (std::ostream & os,const std::set<T>& v)
    {
        bool first = true;
        os << "[";
        for (typename std::set<T>::const_iterator ii = v.begin(); ii != v.end(); ++ii)
        {
            if(!first)
                os << ", ";
            os << *ii;
            first = false;
        }
        return os << "]";
    }
 
    template<typename T1, typename T2>
    inline std::ostream &operator << (std::ostream & os,const std::map<T1, T2>& v)
    {
        bool first = true;
        os << "[";
        for (typename std::map<T1, T2>::const_iterator ii = v.begin(); ii != v.end(); ++ii)
        {
            if(!first)
                os << ", ";
            os << *ii ;
            first = false;
        }
        return os << "]";
    }
    
    template<typename T>
    inline std::ostream &operator << (std::ostream & os,const vector<vector<T>>& v) {
        os << '\n';
        for (auto &u: v) os << u << '\n';
        return os;
    }
/*******************************************************************************/

// descending >
// asc <

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

void solve_util(int n, int cur){

    
}

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