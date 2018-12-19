long double power(long double x, long long y, int MOD=1000000007 )
{
	long double ans=1.0;
	while(y)
	{
		if(y&1)
			ans=ans*x%MOD;
		x=x*x%MOD;
		y>>1;
	}
	return ans;
}

long double power(long double x, int y)
{
	if(y==0) return 1;
	long double temp=power(x*x,y>>1);
	if(y&1)
	{
		if(y>0)
		return temp*x;
		return 1/(temp*x);
	}
	if(temp>0) return temp;
	return 1/temp;
}

unsigned long long powerl(unsigned long long x,unsigned long long y, unsigned long long int MOD=1000000009 )
{
	unsigned long long ans=1;
	while(y)
	{
		if(y&1)
			ans=ans*x%MOD;
		x=x*x%MOD;
		y>>=1;
	}
	return ans;
}

long double powerf(long double x, long long int y)
{
	if(y==0 || x==1) return 1;
	long long int pow=y;
	y=abs(y);
	long double ans=1;
	while(y)
	{
		if(y&1)
			ans=ans*x;
		x=x*x;
		y>>=1;
	}
	if(pow>0)
	return ans;
	return 1.0/ans;
}