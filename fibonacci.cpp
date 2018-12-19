#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;
#define int long long
void multi(int F[2][2], int M[2][2]);
void power(int F[2][2], int n);

int fib(int n)
{
	int F[2][2]  = {{1,1},{1,0}};
	if(n == 0)
		return 0;
	power(F, n-1);

	return F[0][0];
}

void multi(int F[2][2], int M[2][2])
{
	int x = ((F[0][0])%MOD *(M[0][0])%MOD + (F[0][1])%MOD*(M[1][0])%MOD )%MOD;
	int y = ((F[0][0])%MOD *(M[0][1])%MOD + (F[0][1])%MOD*(M[1][1])%MOD )%MOD;
	int z = ((F[1][0])%MOD *(M[0][0])%MOD + (F[1][1])%MOD*(M[1][0])%MOD )%MOD;
	int w = ((F[1][0])%MOD *(M[0][1])%MOD + (F[1][1])%MOD*(M[1][1])%MOD )%MOD;

	F[0][0] = (int)(x%MOD);
	F[0][1] = (int)(y%MOD);
	F[1][0] = (int)(z%MOD);
	F[1][1] = (int)(w%MOD);
}

void power(int F[2][2], int n)
{
	if(n == 0 || n == 1)
		return;

	int M[2][2] = {{1,1}, {1,0}};

	power(F, n/2);
	multi(F, F);

	if( n%2 != 0)
		multi(F, M);

}

signed main()
{
	int test, n; cin >> test;
	while(test--)
	{
	    cin >> n;
	    cout << fib(n+2)%MOD << endl;
	}

	return 0;
}