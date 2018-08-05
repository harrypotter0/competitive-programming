#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll gcd (ll a, ll b, ll & x, ll & y) {
    if (a == 0) {
        x = 0; y = 1;
        return b;
    }
    ll x1, y1;
    ll d = gcd (b%a, a, x1, y1);
    x = y1 - (b / a) * x1;
    y = x1;
    return d;
}

bool find_any_solution (ll a, ll b, ll c, ll & x0, ll & y0, ll & g) {
    g = gcd (abs(a), abs(b), x0, y0);
    if (c % g != 0)
        return false;
    x0 *= c / g;
    y0 *= c / g;
    if (a < 0)   x0 *= -1;
    if (b < 0)   y0 *= -1;
    return true;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t,a,b,c,x,y,g,a0,b0,c0,i;
    cin>>t;
    while(t--)
    {
        cin>>c>>b>>a;
        b*=-1;
        if(find_any_solution(a,b,c,x,y,g))
        {
            for(i=0;;i++)
            {
                if((x-i*b)>0&&(y+i*a)>0)
                {
                    cout<<(x-i*b)<<' ';
                    break;
                }
            }
            
        }
        else cout<<"-1 ";
    }
    return 0;
}


