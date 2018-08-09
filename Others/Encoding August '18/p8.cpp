#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define PB push_back
#define N 2000100
#define LB lower_bound
#define M 1000000007
#define UB upper_bound
#define MP make_pair
#define LD long double
#define F first
#define S second
    
int main() {
    // your code goes here
    LL i,j,k,l,m,t,x,y,z,f,d,q,a[N],n;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>t;
    while(t--)
    {
        cin>>x>>y;
        queue<pair<LL,LL>> q;
        LL vis[3001];
        fill(vis,vis+3001,0);
        q.push(MP(x,0));
        d=0;
        while(!q.empty())
        {
            pair<LL,LL> cur=q.front();
            q.pop();
            z=cur.F;
            d=cur.S;
            vis[z]=1;
            if(z==y)
                break;
            if(z-1>=0)
                if(vis[z-1]==0)
                    q.push(MP(z-1,d+1));
            if(z+3<=3000)
                if(vis[z+3]==0)
                    q.push(MP(z+3,d+1));
            if(z*2<=3000)
                if(vis[z*2]==0)
                    q.push(MP(z*2,d+1));
        }
        cout<<d<<"\n";
    }
    return 0;
} 