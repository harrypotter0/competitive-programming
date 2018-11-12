
#include <bits/stdc++.h>
using namespace std;

#define pb emplace_back
#define mp make_pair
#define endl "\n"
#define sz(x) (int)x.size()
#define aint(v) v.begin(), v.end()
#define x first
#define y second
#define rep(i, j, k) for(i=j; i<k; i++)
#define sep(i, j, k) for(i=j; i>k; i--)
#define ios ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define watch(x) cout << (#x) << " is " << (x) << endl
const int mod = 1e9+7;
const int N = 3e6+5;

#define ll long int
    
ll ar[200010];  
    
struct param{
    ll ans=0,pre=0,suff=0,tot=0;     
};
    
param tree[4*200010];  
    
void build(ll node,ll start,ll end){
    if(start==end)
    {
        tree[node].tot=ar[start];
        tree[node].ans=ar[start];  
        tree[node].pre=ar[start];
        tree[node].suff=ar[start];
    }
    else
    {
    int mid=(start+end)/2;    
    build(2*node+1,start,mid);
    build(2*node+2,mid+1,end);
    tree[node].tot=tree[2*node+1].tot+tree[2*node+2].tot;
    tree[node].pre=max(tree[2*node+1].pre,tree[2*node+2].pre+tree[2*node+1].tot);
    tree[node].suff=max(tree[2*node+2].suff,tree[2*node+2].tot+tree[2*node+1].suff);
    tree[node].ans=max(tree[node].pre,max(tree[node].suff,max(tree[2*node+1].ans,max(tree[2*node+2].ans,tree[2*node+1].suff+tree[2*node+2].pre))));
    }
}
    
param query(ll node,ll start,ll end,ll l,ll r){
    param a;
    a.suff=a.tot=a.ans=a.pre=-10000000;
    if(start>r||end<l)
    {
        return a;  
    }
    if(start>=l&&end<=r)
    {
    return tree[node];   
    }
    ll mid=(start+end)/2;
    if(r<=mid)
    {
    return query(2*node+1,start,mid,l,r);   
    }
    if(l>mid)
    {
    return query(2*node+2,mid+1,end,l,r);   
    }
    param left=query(2*node+1,start,mid,l,r);
    param right=query(2*node+2,mid+1,end,l,r);
    a.tot=left.tot+right.tot;
    a.pre=max(left.pre,left.tot+right.pre);
    a.suff=max(right.suff,right.tot+left.suff);
    a.ans=max(a.pre,max(a.suff,max(left.suff+right.pre,max(right.ans,left.ans))));
    return a;	
}
    
int main() {
    ll n,q,k,i,j,num=-1e10,l,r,fans,ans1,ans2,ans3,ans4;
    cin>>n>>q>>k;
    for(i=0;i<n;i++){
        cin>>ar[i];    
        ar[i+n]=ar[i];
        if(!ar[i]){
            ar[i+n]=-100000000;
            ar[i]=-100000000;
        }
    }
    // for(i=0;i<2*n;i++){
    //     cout<<ar[i]<<" ";
    // }
    // cout<<endl;
    int x = n;
    build(0,0,2*n-1); 
    string str;
    cin>>str;
    // param middle;
    // middle=query(0,0,2*n-1,3,6);
    // fans = middle.ans;
    // cout<<fans<<endl;

    for(i=0;i<q;i++){
        param middle; 
        if(str[i]=='!'){
            x--;
            if(x==-1)x=n-1;
        }
        // watch(x);
        fans = 0;
        middle=query(0,0,2*n-1,x,x+n-1);
        fans = middle.ans;
        if(fans<0)fans=0;
        // cout<<fans<<endl;
        if(str[i]=='?')
        cout<<min(fans,k)<<endl;
    }

    return 0;
}

