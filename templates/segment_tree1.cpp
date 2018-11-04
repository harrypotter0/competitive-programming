#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define ui unsigned int
#define ull unsigned ll
#define vi vector<int>
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define pii pair<int,int>
#define pll pair<ll,ll>
#define vii vector<pii >
#define vll vector<ll >
#define vvi vector<vi >
#define vvl vector<vll >
#define cps CLOCKS_PER_SEC
#define eb emplace_back
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1)
#define all(a) (a).begin(), (a).end()
#define sz(a) int((a).size())
#define print(s) cout<<#s<<" : ";for(auto i:(s))cout<<i<<" ";cout<<"\n";
#define slld(t) scanf("%lld",&(t))
#define sd(t) scanf("%d",&(t))
#define pd(t) printf("%d\n",(t))
#define plld(t) printf("%lld\n",(t))
#define endl "\n"

const int maxn = 1e6+10;
const ll mod = 1e9+7;
const int N = 1e5;

int A[maxn]; // least prime factor
vi primes;
int a[maxn];
set<int> active;
int present[maxn];
int tree[5*maxn];
 
int segtree(int i ,int j,int ind)
{
    if(i==j)
    {
        tree[ind] = present[i];
        return tree[ind];
    }
    int mid = (i+j)>>1, ind1 = (ind<<1),ind2 = (ind1|1);
    tree[ind]=max(segtree(i,mid,ind1), segtree(mid+1,j,ind2));
    return tree[ind];
}
 
void update(int i, int val, int s,int e,int ind)
{
    if(i<s || i>e)
        return;
    if(s==e)
    {
        tree[ind] = val;
        return;
    }
    int mid = ((s+e)>>1), ind1 = (ind<<1),ind2 = (ind1|1);
    if(i <= mid)
        update(i,val,s,mid,ind1);
    else
        update(i,val,mid+1,e,ind2);
    tree[ind] = max(tree[ind1],tree[ind2]);
}

int query(int i , int j, int s,int e, int ind)
{
    if(i>e || j < s)
        return 0;
    if(s>=i && e <= j){
        return tree[ind];
    }
    int mid = ((s+e)>>1), ind1 = (ind<<1),ind2 = (ind1|1);
    return max(query(i,j,s,mid,ind1),query(i,j,mid+1,e,ind2));
}

int main()
{
    memset(A,0,sizeof A);

    for(int i = 2;i*i<maxn;i++)
        if(!A[i])
            for(int j = i*i;j<maxn;j+=i)
                if(!A[j])
                    A[j] = i;
    A[1] = 1;
    for(int i = 2;i<maxn;i++){
        if(!A[i])
            primes.eb(i),A[i] = i;
    }
    int t,l,r,n,m,type;
    cin>>t;
    while(t--)
    {
        sd(n),sd(m);
        active.clear();
        rep(i,1,n+1){
            sd(a[i]);
            if(a[i]!=1){
                active.insert(i);
            }
            present[i] = A[a[i]];
        }
        segtree(1,n,1);
        while(m--)
        {
            sd(type),sd(l),sd(r);
            if(!type)
            {
                vi vec;
                auto it1 = active.upper_bound(l-1);
                for(auto it = it1;(*it)  <=r && it!=active.end();it++)
                {
                    int x = *it;
                    a[x]/=present[x];
                    present[x] = A[a[x]];
                    update(x,present[x],1,n,1);
                    if(a[x] == 1)
                        vec.eb(x);
                }
                for(int j:vec)
                    active.erase(j);
            }
            else
            {
                printf("%d ", query(l,r,1,n,1));
            }
        }
    }        
}