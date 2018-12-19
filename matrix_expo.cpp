#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define debug cout<<"here"<<endl;
#define ll long long int
#define mp make_pair
#define pb push_back
const ll MOD=1e9+7;
#define MAX 100005
#define infi 1000000
#define PII pair<ll,ll>
#define input freopen("input.txt","r",stdin);
#define output freopen("output.txt","w",stdout);
using namespace std;

int val = 3;
ll result[val][val];
    
void matrixExp(ll n)
{
    for(int i=0;i<val;i++)
    {
        for(int j=0;j<val;j++)
        {
            if(i==j)
                result[i][j]=1;
            else
                result[i][j]=0;			
        }
    }
    
    ll trans[val][val]={
                        {1,1,1},
                        {1,0,0},
                        {0,1,0}
                    };
    
    while(n)
    {
        if(n&1)
        {
            ll tmp[val][val];
            for(int i=0;i<val;i++)
            {
                for(int j=0;j<val;j++)
                {
                    tmp[i][j]=0;
                    for(int k=0;k<val;k++)
                    {
                        tmp[i][j]=(tmp[i][j]+result[i][k]*trans[k][j])%MOD;
                    }
                }
            }
            for(int i=0;i<val;i++)
                for(int j=0;j<val;j++)
                    result[i][j]=tmp[i][j];
        }
    
        ll tmp[val][val];
        for(int i=0;i<val;i++)
        {
            for(int j=0;j<val;j++)
            {
                tmp[i][j]=0;
                for(int k=0;k<val;k++)
                {
                    tmp[i][j]=(tmp[i][j]+trans[i][k]*trans[k][j])%MOD;
                }
            }
        }
        for(int i=0;i<val;i++)
            for(int j=0;j<val;j++)
                trans[i][j]=tmp[i][j];
    
        n=n/2;
    
    }
}
int main()
{
    fast;
    int t;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        if(n<=val)
        {
            if(n==1)
                cout<<2<<endl;
            else if(n==2)
                cout<<4<<endl;
            else if(n==3)
                cout<<7<<endl;
            continue;
        }
        matrixExp(n-val);
        ll ans=(result[0][0]*7+result[0][1]*4+result[0][2]*2)%MOD;
        cout<<ans<<endl;
    }
    return 0;
}

