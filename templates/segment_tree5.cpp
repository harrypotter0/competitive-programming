

#include <bits/stdc++.h>
#define f(i,a,b) for (ll i = a; i <= b; i++)
#define debug(x) cout<<#x<<" "<<x<<endl;
    
using namespace std;
    
typedef long long ll;
    
const ll mod = 1e9 + 7;
    
const ll RIGHT = 131072;
const ll SIZE = 255005;
ll N, Q, K[SIZE], D[SIZE], LK[SIZE], LD[SIZE], S[SIZE];
    
ll query(ll l, ll r, ll n = 1, ll a = 1, ll b = RIGHT)
{
    
    if(a > r || b < l) return 0;
    if(a >= l && b <= r) return S[n];
    
    if(LK[n] != 0 || LD[n] != 0)
    {
        ll sz = (b-a+1) / 2;
        K[2*n] += LK[n], K[2*n+1] += LK[n] + LD[n]*sz;
        D[2*n] += LD[n], D[2*n+1] += LD[n];
        S[2*n] += LK[n]*sz + LD[n]*sz*(sz-1) / 2;
        S[2*n+1] += (LK[n] + LD[n]*sz)*sz + LD[n]*sz*(sz-1) / 2;
        LK[2*n] += LK[n], LK[2*n+1] += LK[n] + LD[n]*sz;
        LD[2*n] += LD[n], LD[2*n+1] += LD[n];
        LK[n] = LD[n] = 0;
    }
    
    ll mid = (a+b) / 2;
    return (query(l,r,2*n,a,mid) + query(l,r,2*n+1,mid+1,b))%mod;
}
    
void update(ll l, ll r, ll k, ll d, ll n = 1, ll a = 1, ll b = RIGHT)
{
    if(a >= l && b <= r)
    {
        K[n] += k, D[n] += d;
        LK[n] += k, LD[n] += d;
        ll sz = (b-a+1);
        S[n] += k*sz + d*sz*(sz-1) / 2;
        return;
    }
    
    if(LK[n] != 0 || LD[n] != 0)
    {
        ll sz = (b-a+1) / 2;
        K[2*n] += LK[n], K[2*n+1] += LK[n] + LD[n]*sz;
        D[2*n] += LD[n], D[2*n+1] += LD[n];
        S[2*n] += LK[n]*sz + LD[n]*sz*(sz-1) / 2;
        S[2*n+1] += (LK[n] + LD[n]*sz)*sz + LD[n]*sz*(sz-1) / 2;
        LK[2*n] += LK[n], LK[2*n+1] += LK[n] + LD[n]*sz;
        LD[2*n] += LD[n], LD[2*n+1] += LD[n];
        LK[n] = LD[n] = 0;
    }
    
    ll mid = (a+b) / 2;
    if(l <= mid) update(l,min(mid,r),k,d,2*n,a,mid);
    if(r > mid) update(max(mid+1,l),r,k + d*max(mid-l+1,0LL),d,2*n+1,mid+1,b);
    
    S[n] = S[2*n] + S[2*n+1];
}
    
int main()
{
    cin>>N>>Q;
    f(i,1,N){
        ll d;
        cin>>d;
        update(i,i,d,0);
    }
    query(1,N);
    while(Q--)
    {
        ll t;
        scanf("%d", &t);
        if(t == 1)
        {
            ll l,k;
            scanf("%lld %lld", &l, &k);
            if(l+k-1 <= N)
                update(l,l+k-1,k,-1);
            else{
                update(l,N,k,-1);
                k -= N - l + 1;
                ll times = k/N;
                ll a = k , l = k - times * N + N , d = -times;
                // debug(a); debug(l); debug(times);
                ll term = ((a + l)*times)>>1;
                term %= mod;
                //debug(term);
                if(times)update(1,N,term,d);
                k = l - N;
                if(k)update(1,1+k-1,k,-1);
            }
        }
        else
        {  // for(int i = 1; i<= N ;i++)cout<<query(i,i)<<' '; cout<<endl;
            ll l,r;
            scanf("%d %d", &l, &r);
            if(r>=l)
            printf("%lld\n", query(l,r)%mod);
            else{
                ll ans = query(1,N);
                if(r+1 <= l-1) ans -= query(r+1,l-1);
                printf("%lld\n", (ans+mod)%mod);
            }
        }
    }
}

Language: C++14
