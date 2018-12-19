long long modexp(long long base, long long power, long long mod=1000000007)
{
	long long res=1;
	while(power)
	{
		if(power&1) res=(res*base)%mod;
		power>>=1;
		base=(base*base)%mod;
	}
	return res;
}

long long invmod(long long num, long long mod=1000000007)
{
	return modexp(num,mod-2,mod);
}

double logpow(double base, long long exp)
{
	double res=0.0;
	while(exp)
	{
		if(exp&1)	res+=base;
		exp>>=1;
		base+=base;
	}
	return res;
}
