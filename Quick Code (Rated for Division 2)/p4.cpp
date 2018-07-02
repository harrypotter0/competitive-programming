#include <bits/stdc++.h>
using namespace std;
long long bit[400005];
long long ans1,ans2;
// bits
void update(long long int idx,long long int val)
{
    cout<<"update";
    while(idx<=100004)
    {
        bit[idx]+=val;
        idx+=idx&(-idx);
        cout<<idx<<" ";
    }
    cout<<endl;
}
long long tree[400005];
long long a[100005];
void build(long long int start,long long int end1,long long int cur)
{
    if(start==end1)
    {
        tree[cur]=a[start];
        return ;
    }
    long long int mid=(start+end1)/2;
    build(start,mid,2*cur);
    build(mid+1,end1,2*cur+1);
    tree[cur]=max(tree[2*cur],tree[2*cur+1]);
}
long long query(long long int start,long long int end1,long long int l,long long int r,long long int cur)
{
    if(start>end1||end1<l||start>r)
    {
        return 0;
    }
    if(start>=l&&end1<=r)
    {
        return tree[cur];
    }
    long long int mid=(start+end1)/2;
    long long int h=query(start,mid,l,r,2*cur);
    long long int g=query(mid+1,end1,l,r,2*cur+1);
   // tree[cur]=max(tree[2*cur],tree[2*cur+1]);
   //cout<<g<<" "<<h<<endl;
    return max(g,h);
}
void update1(int ss,int se, int idx,long long int val,int node)
{
 
    if(ss==se&&ss==idx)
    {
        tree[node]=val;
        return ;
    }
 
    if(ss>idx||se<idx)
        return ;
 
    int mid=(ss+se)/2;
    update1(ss,mid,idx,val,2*node);
    update1(mid+1,se,idx,val,2*node+1);
    tree[node]=max(tree[2*node],tree[2*node+1]);
}
long long sum(int idx)
{
    long long sum1=0;
    cout<<"sum";

    while(idx>0)
    {
        sum1+=bit[idx];
        idx-=idx&(-idx);
        cout<<idx<<" ";
    }
    cout<<endl;
    return sum1;
}
 
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        ans1=0,ans2=0;
        map<long long,long long int>m;
        m.clear();
        long long int n,q;
        cin>>n>>q;
       // int a[n+1];
        long long int i;
        for(i=1;i<=n;i++)
        {
            cin>>a[i];
            m[a[i]]=i;
            update(i,a[i]);
        }
        build(1,n,1);
        while(q--)
        {
            int type,l,r;
            cin>>type>>l>>r;
            if(type==1)
            {
                long long x=sum(r)-sum(l-1);
                long long mod,median;
                //cout<<x<<endl;
                if(x%2!=0)
                {
                    long long g=x/2+1;
                    long long low=l,high=r;
                    while(low<=high)
                    {
                        long long mid=(low+high)/2;
                        long long dd=sum(mid)-sum(l-1);
                        if(dd>=g)
                        {
                            ans1=mid;
                            high=mid-1;
                        }
                        else
                        {
                            low=mid+1;
                        }
                    }
                    median=ans1;
                }
                else
                {
                    long long g=x/2;
                    long long low=l,high=r;
 
                    while(low<=high)
                    {
                        long long mid=(low+high)/2;
                        long long dd=sum(mid)-sum(l-1);
                        if(dd>=g)
                        {
                            ans1=mid;
                            high=mid-1;
                        }
                        else
                        {
                            low=mid+1;
                        }
                    }
                    g=x/2+1;
                    low=l,high=r;
                    while(low<=high)
                    {
                        long long mid=(low+high)/2;
                        if((sum(mid)-sum(l-1))>=g)
                        {
                            ans2=mid;
                            high=mid-1;
                        }
                        else
                        {
                            low=mid+1;
                        }
                    }
                    median=(ans1+ans2);
                    median/=2;
                }
                mod=query(1,n,l,r,1);
                mod=m[mod];
              //  cout<<mod<<" "<<median<<endl;
                long long rr=mod*median;
                long long pp=__gcd(mod,median);
                rr=rr/pp;
                cout<<rr<<endl;
 
            }
            else
            {
                update(l,-a[l]);
                update(l,r);
                update1(1,n,l,r,1);
                a[l]=r;
                m[r]=l;
            }
        }
        for(i=1;i<=4*n;i++)
        {
            tree[i]=0;
        }
        for(i=1;i<=100005;i++)
        {
            a[i]=0;
            bit[i]=0;
        }
        m.clear();
    }
}