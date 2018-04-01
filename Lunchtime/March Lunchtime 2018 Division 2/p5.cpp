#include<iostream>
#include<set>
#include<bits/stdc++.h>
#define ll long long
using namespace std;
int arr[100001];
multiset< int > seg[400001];
multiset< int > :: iterator it;
ll solve(int i, int j, ll b){
    ll A = - (b * b);
    ll B = (arr[i] + arr[j]);
    B *= b;
    ll C = -(arr[i] * 1LL * arr[j]);
    return A + B + C;
}

ll query(int node, int l, int r, int s, int e){
    if(s > r || l > e) return LONG_LONG_MIN;
    if(l >= s && r <= e){
        ll curr = LONG_LONG_MIN;
        // if(it != seg[node].end()){
        //   curr =  max(curr, solve());
        // }
        // if(it != seg[node].begin()){
        //     --it;
        //     curr = max(curr, solve(s, e, *it));
        // }
        for(int i=0;i<n;i++){
          g = __gcd(arr[i], arr[i%n]);
          curr = max(curr,g);
        }
        return curr;
     }
    ll p = query(2 * node, l , (l + r)/2 , s, e);
    ll q = query(2 * node + 1, (l + r)/2 + 1, r, s, e);
    return max(p, q);
}
void build(int node, int l, int r){
    if(l == r){
        seg[node].insert(arr[l]);
        return;
    }
    build(2 * node, l, (l + r)/2);
    build(2 * node + 1, (l + r)/2 + 1,  r);
    for(it = seg[2 * node].begin() ; it != seg[2 * node].end(); ++it) seg[node].insert(*it);
    for(it = seg[2 * node + 1].begin() ; it != seg[2 * node + 1].end(); ++it) seg[node].insert(*it);
}
int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        int n, q;
        scanf("%d %d", &n, &q);
        for(int i = 1 ; i <= 4 * n ; ++i) seg[i].clear();
        for(int i = 1 ; i <= n ; ++i){
            scanf("%d", arr + i);
        }
        build(1, 1, n);
        while(q--){
               int l, r;
                scanf("%d%d", &l, &r);
               // int b = (arr[l] + arr[r] + 1)/2;
               printf("%lld\n", query(1, 1, n, l, r));
        }
    }
}
/*

Output:

2
2
4
1
2
1
*/
