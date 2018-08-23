
/*
 *
 ********************************************************************************************
 * AUTHOR : Akash Kandpal                                                                    *
 * Language: C++14                                                                          *
 * Motto : The master has failed more times than the beginner has even tried.               *                                                                *
 * IDE used: VSCode                                                                           *
 * My Domain : http://harrypotter.tech/                                                     *
 ********************************************************************************************
 *
 */
#include <iostream>     // std::cout
#include <algorithm>    // std::max
#include<bits/stdc++.h>
using namespace std;
#define ll          long long
#define pb          push_back
#define	endl		    '\n'
#define mod         1000000007
#define lbnd        lower_bound
#define ubnd        upper_bound
#define bs          binary_search
#define mp          make_pair
#define prec(n) fixed<<setprecision(n)
#define mem(dp,value) memset(dp,value,sizeof(dp))
const int inf =1e9;
#define MAX  100005

using namespace std;

ll exp(ll a,ll b)
{
	ll tem=1;
	while(b)
	{
		if(b%2)
			tem=(tem*a)% mod;
		a=(a*a)% mod;
		b=b/2;
	}
	return tem;
}
ll takemod(ll num)
{
    if(num<0)
	    num+= mod;
    num=num% mod;
    return num;
}

ll fast_pow(long long base, long long n,long long M)
{
	if(n==0)
		return 1;
	if(n==1)
		return base;
	long long halfn=fast_pow(base,n/2,M);
	if(n%2==0)
		return ( halfn * halfn ) % M;
	else
		return ( ( ( halfn * halfn ) % M ) * base ) % M;
}

int dad[100010];
int find(int x){
    if(dad[x]==x) return x;
    return dad[x]=find(dad[x]);
}
void uni(int x,int y){
    int X=find(x),Y=find(y);
    dad[X]=Y;
}

bool isOperand(char c) { return (c >= '0' && c <= '9'); }

// utility function to find value of and operand
int value(char c) {  return (c - '0'); }

int evaluate(char *exp)
{
    if (*exp == '\0')  return -1;

    int res = value(exp[0]);

    for (int i = 1; exp[i]; i += 2)
    {
        char opr = exp[i], opd = exp[i+1];

        if (!isOperand(opd))  return -1;

        if (opr == '+')       res += value(opd);
        else if (opr == '-')  res -= value(opd);
        else if (opr == '*')  res *= value(opd);
        else if (opr == '/')  res /= value(opd);

        else                  return -1;
    }
    return res;
}

ll  modInverse(ll y){
    return fast_pow(y,  mod-2,  mod);
}

ll subtraction_modulo(ll x, ll y ){
        return ( ( (x - y) %  mod ) +  mod ) %  mod;
    }

map<int,long long> dp;
long long optcoins(int n){
    if(n<12)
        return n;
    if(dp.count(n))
        return dp[n];
    dp[n]=optcoins(n/2)+optcoins(n/3)+optcoins(n/4);
    return dp[n];
}
// int main(){
//     int x;
//     while(scanf("%d",&x)!=EOF)
//         printf("%lld\n",optcoins(x));
//     return 0;
// }

int main() {
    // your code goes here
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    int x;
    while(scanf("%d",&x)!=EOF)
        cout<<optcoins(x)<<"\n";
    // ll t;
    // cin>>t;
    // while(t--)
    // {
    //     ll n,k;
    //     string s;
    //     cin>>s;
    //     memset(G,0,sizeof(G[0][0])*26*100001);
        

    //     // cout << setprecision(3) << dis << "\n";
    // }

return 0;
}

