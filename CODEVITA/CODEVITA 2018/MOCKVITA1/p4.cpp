#include<bits/stdc++.h>
using namespace std;
 
const int mod = 1009;
#define pb push_back
#define F first
#define S second
#define fills(x,y) memset(x,y,sizeof x)
#define rep(i,n) for(i=0;i<n;++i)
#define REP(i,k,n) for(i=k;i<=n;++i)
#define tr(i,c) for(auto &i:c)
#define fastio          ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define inchar          getchar
#define outchar(x)      putchar(x)
#define bitcounts(n) __builtin_popcountll(n)
#define sz(a) int((a).size())
#define endl "\n"
template<typename T, typename U> static void amin(T &x, U y) { if(y < x) x = y; }
template<typename T, typename U> static void amax(T &x, U y) { if(x < y) x = y; }
template<typename T> void scan(T &x){x=0;bool neg=0;register T c=inchar();if(c=='-')
neg=1,c=inchar();while((c<48)||(c>57))c=inchar();for(;c<48||c>57;c=inchar());
for(;c>47&&c<58;c=inchar())x=(x<<3)+(x<<1)+(c&15);if(neg)x*=-1;}
template<typename T> void output(T n){bool neg=0;if(n<0)n*=-1,neg=1;char snum[65];int i=0;do {snum[i++]=n%10+'0';n/=10;}\
while(n);i=i-1; if(neg)putchar('-'); while(i>=0)outchar(snum[i--]);outchar('\n');}
inline void instr(char *str){register char c=0;register int i=0;while(c<33)c=inchar();while (c!='\n'&&c!=' '&&c!=EOF){\
str[i]=c;c=inchar();++i;}str[i]='\0';}
template<typename T> T lcm(T a, T b){return (a*(b/__gcd(a,b)));}
template<typename T> inline T MOD(T a, T b) {return (a<b ? a : a%b);}
template<typename T> T add(T a, T b, T c){T x=a+b;return (x>=c ? x-c : x);}
template<typename T> T mod_neg(T a, T b) {a=MOD(a, b);if(a<0){a+=b;}return a;}
template<typename T> T expo(T e, T n){T x=1,p=e;while(n){if(n&1)x=x*p;p=p*p;n>>=1;}return x;}
template<typename T> T power(T e, T n, T m){T x=1,p=e;while(n){if(n&1)x=MOD(x*p,m);p=MOD(p*p,m);n>>=1;}return x;}
template<typename T> T exted_euclid(T a, T b, T &x, T &y){T xx=0,yy=1;y=0;x=1;while(b){T q=a/b,t=b;b=a%b;a=t;t=xx;\
xx=x-q*xx;x=t;t=yy;yy=y-q*yy;y=t;}return a;}
template<typename T> T mod_inverse(T a, T n){T x,y;T d = exted_euclid(a, n, x, y);return (d>1?-1:mod_neg(x,n));}
#define tcsolve() int tcs; cin>>tcs;while(tcs--) solve();
 
const int MAX=500;
int arr[MAX];
 
void solve()
{
int m,n,i,j,a,p,q,x=0,y=0,both=0, rem = 0;
scanf("%d,%d,%d",&n,&p,&q);
 
for(int i=0; i<n; ++i){
    scanf("%d,", &a);
    if(a % (p*q) == 0)
        ++both;
    else if(a%p==0 && a%q!=0)
        ++x;
    else if(a % q == 0)
        ++y;
    else
        ++rem;
}
 
long long  ans = ((power(2,x,mod) -1 )* (power(2,y,mod) - 1)) % mod  * (power(2,rem, mod));
ans = (ans%mod +  (power(2,both, mod) - 1) * power(2,rem+y+x, mod)) % mod;
 
cout << ans;
}
 
int  main()
{
#ifdef LOCAL
freopen("in.c","r",stdin);
//freopen("out.c","w",stdout);
#endif
solve();
return 0;
}