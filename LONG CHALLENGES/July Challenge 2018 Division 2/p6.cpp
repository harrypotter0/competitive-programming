/*
*
********************************************************************************************
* AUTHOR : Vijju123                                                                        *
* Language: C++14                                                                          *
* Purpose: -                                                                               *
* IDE used: Codechef IDE.                                                                  *
********************************************************************************************
*
Comments will be included in practice problems if it helps ^^
*/



#include <iostream>
#include<bits/stdc++.h>
using namespace std;

struct DSU{
int u;
int parent;
int parity;
int root;
int size=1;
int neighbour=0;
void set(int a,int b,int c,int d)
{
    u=a;
    parent=b;
    parity=c;
    root=d;
}
};

int isBlocked[100001],arr[100001];
DSU ans[100001],tempd;

pair<int,int> findRoot(DSU a)
{
pair<int,int> temp;
//cout<<"A.u="<<a.u<<" a.root="<<a.root<<endl;
if(a.root!=a.u)
{
    int parity=ans[a.u].parity;
    temp=findRoot(ans[a.root]);
    ans[a.u].root=temp.first;
    ans[a.u].parity=temp.second^parity;
}
//cout<<"For a="<<a.u<<" returning {"<<ans[a.u].root<<","<<ans[a.u].parity<<"}"<<endl;
return {ans[a.u].root,ans[a.u].parity};
}

void swap(DSU &a, DSU &b)
{
tempd=a;
a=b;
b=tempd;
}

void connect(DSU a, DSU b)
{
pair<int,int> tempa,tempb;
tempa=findRoot(a);
tempb=findRoot(b);
ans[a.u].neighbour++;
ans[b.u].neighbour++;
int roota=tempa.first;
int rootb=tempb.first;
int x=tempa.second;
int y=tempb.second;

if(roota==rootb and x==y)
{
    isBlocked[rootb]=1;
}
if(a.size<b.size)
    swap(a,b);
    
ans[roota].size+=ans[rootb].size;
ans[rootb].root=roota;
ans[rootb].parity=x^y^1;
isBlocked[roota]=isBlocked[rootb]=isBlocked[roota] or isBlocked[rootb];
}

int main() {
// your code goes here
#ifdef JUDGE
freopen("input.txt", "rt", stdin);
freopen("output.txt", "wt", stdout);
#endif
ios_base::sync_with_stdio(0);
cin.tie(NULL);
cout.tie(NULL);
int n,m;
cin>>n>>m;
int i;
arr[0]=0;

for(i=1;i<=n;i++)
{
    cin>>arr[i];
}
for(i=0;i<=n;i++)
    ans[i].set(i,i,0,i);
int t,x,y,v,para,parb;
long long gcd;
long long num,den;
pair<int,int> tempx,tempy;
while(m--)
{
    cin>>t>>x>>y;
    if(t==1)
    {
        arr[x]=y;
    }
    else if(t==2)
    {
        connect(ans[x],ans[y]);
    }
    else
    {
        cin>>v;
        tempx=findRoot(ans[x]);
        tempy=findRoot(ans[y]);
        int roota=tempx.first;
        int rootb=tempy.first;
        if(rootb!=roota or isBlocked[roota])
            cout<<0<<"\n";
        else
        {
            num=v*1LL*arr[x];
            den=arr[y];
            para=tempx.second;
            parb=tempy.second;
            gcd=__gcd(num,den);
            assert(gcd>0);
            num/=gcd;
            den/=gcd;
            
            if(para!=parb)
                num*=-1;
            cout<<num<<"/"<<den<<"\n";
        }
    }
    
    
}
return 0;
}