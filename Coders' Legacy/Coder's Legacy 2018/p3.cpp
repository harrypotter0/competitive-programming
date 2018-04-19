#include<bits/stdc++.h>
#define S second
#define F first
#define ll long long
#pragma GCC optimize("O3")
using namespace std;
ll z[300009],d[300009],f[300009],n,m;
vector<pair<ll,ll> > v[300009];
void upd(ll x, ll v){
  //  cout <<x<<" "<<v<<endl;
    while(x <= n){
        d[x] += v;
        x += (x&-x);
    }
}
ll cnt(ll x){
    ll sum = 0;
    while(x){
        sum += d[x];
        x -= (x&-x);
    }
    return sum;
}
main(){
    ll T;
    cin >> T;
    while(T--){
        scanf("%lld%lld",&n,&m);
        for (ll i= 1; i<= n; i++)
            scanf("%lld",&z[i]);
        for (ll i= 1; i<= n; i++)
            d[i] = 0,v[i].clear();
        for (ll i=  1; i<= m; i++){
            ll l, r, k;
            scanf("%lld%lld%lld",&l,&r, &k);
            v[l].push_back({r,k});
        }
        ll ans = 0;
        priority_queue<pair<ll,ll > > p;
        ll fl = 1;
        for (ll i = 1; i <= n; i++){
          //  cout << i << endl;
            for (ll j = 0; j < v[i].size(); j++)
                p.push(v[i][j]);
            while(1){
                ll R = z[i] - cnt(i);
                if(R <= 0) break;
                if(p.size() == 0 || p.top().F < i) {
                        fl = 0;
                        break;
                }

                auto t = p.top();
                p.pop();
                //cout << t.F<<" "<<t.S<<" "<<cnt(i)<<" "<<z[i]<<endl;
                //system("pause");
                ll X = min(R,t.S);
                ans += X;
                t.S -= X;
                upd(1, X);
                upd(t.F+1, -X);
                if(t.S) p.push(t);
            }
            if(!fl) break;
        }
        if(fl) cout <<"YES "<<ans << endl;
        else cout <<"NO" << endl;
    }
}
