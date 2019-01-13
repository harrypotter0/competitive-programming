#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define sp ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
#define cps CLOCKS_PER_SEC
#define mod (ll)1000000007
#define f first
#define s second
#define debug1(x) cerr<<x<<"\n"
#define debug2(x,y) cerr<<x<<" "<<y<<"\n"
#define debug3(x,y,z) cerr<<x<<" "<<y<<" "<<z<<"\n"
#define nl cerr<<"\n";
#define pq priority_queue
#define inf 0x3f3f3f3f
#define test cerr<<"abcd\n";
#define pi pair<ll,ll>
#define pii pair<int,pi>
#define pb push_back
#define mxn 200005
ll a[mxn],l1[mxn],l2[mxn],r1[mxn],r2[mxn];
unordered_map<ll,ll> mp1,mp2;

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



void showstack(stack <int> s) 
{ 
    while (!s.empty()) 
    { 
        cout << ' ' << s.top(); 
        s.pop(); 
    } 
    cout << '\n'; 
} 

int main(){
    sp;

    int n,q;
    cin>>n>>q;

    for(int i=0; i<n; ++i){
        cin>>a[i];
    }

    ll x;
    stack<int> s;
    for(int i=0; i<n; ++i){
        l1[i]=l2[i]=-1;
        r1[i]=r2[i]=n;
    }
    
    // calculate min upto iteration 
    // arr[] agar chota hai toh keep popping 
    for(int i=0; i<n; ++i){
        while(!s.empty()&&a[s.top()]>=a[i])
            s.pop();
        if(!s.empty())l1[i]=s.top();
        s.push(i);
    showstack(s);
    }
    dbga(l1,n);
    while(!s.empty())s.pop();

    // calculate min backwards 
    for(int i=n-1; i>=0; --i){
        while(!s.empty()&&a[s.top()]>a[i])
            s.pop();
        if(!s.empty())r1[i]=s.top();
        s.push(i);
    showstack(s);
    }
    dbga(r1,n);
    while(!s.empty())s.pop();

    // calculate max upto iteration 
    for(int i=0; i<n; ++i){
        while(!s.empty()&&a[s.top()]<=a[i])
            s.pop();
        if(!s.empty())l2[i]=s.top();
        s.push(i);
    showstack(s);
    }
    dbga(l2,n);
    while(!s.empty())s.pop();

    // calculate max backwards 
    for(int i=n-1; i>=0; --i){
        while(!s.empty()&&a[s.top()]<a[i])
            s.pop();
        if(!s.empty())r2[i]=s.top();
        s.push(i);
    showstack(s);
    }
    dbga(r2,n);

    // min calculation
    for(int i=0; i<n; ++i){
        ll a1=i-l1[i]-1;
        ll a2=r1[i]-i-1;
        ll p=1LL*a1*a2+a1+a2+1;
        mp1[a[i]]+=p;
        // dbg5(a1, a2, mp1[a[i]], l1[i], r1[i]);
    }

    // max calculation
    for(int i=0; i<n; ++i){
        ll a1=i-l2[i]-1;
        ll a2=r2[i]-i-1;
        ll p=1LL*a1*a2+a1+a2+1;
        mp2[a[i]]+=p;
        // dbg5(a1, a2, mp2[a[i]], l2[i], r2[i]);
    }

    while(q--){
        cin>>x;
        assert(x>=1&&x<=1000000000);
        if(mp1.count(x)==0)
            cout<<"0 0\n";
        else cout<<mp2[x]<<" "<<mp1[x]<<"\n";
    }
return 0;
}


