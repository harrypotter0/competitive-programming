
#include <bits/stdc++.h>
using namespace std;
    
#define ll long int
    
ll ar[100010];  
    
struct param{
    ll ans=0,pre=0,suff=0,tot=0;     
};
    
param tree[4*100010];  
    
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
    ll n,q,i,j,num=-1e10,l,r,fans,ans1,ans2,ans3,ans4;
    cin>>n>>q;
    for(i=0;i<n;i++){
        cin>>ar[i];    
        num=max(ar[i],num); 
    }
    build(0,0,n-1); 
    while(q--){
        param left,middle,right; 
        cin>>l>>r;
        middle=query(0,0,n-1,l-1,r-1);
        if(l>1)
        {
        left=query(0,0,n-1,0,l-2);
        } 
        if(r<n)
        {
        right=query(0,0,n-1,r,n-1);
        } 
        ans1=middle.suff+left.suff;
        ans2=middle.pre+right.pre;
        ans3=middle.tot+left.suff+right.pre;
        ans4=max(middle.ans,max(left.ans,right.ans));
        fans=max(max(max(ans1,ans2),ans3),ans4);
        if(fans==0)
            fans=num; 
        cout<<fans<<endl;
    }
    return 0;
}

