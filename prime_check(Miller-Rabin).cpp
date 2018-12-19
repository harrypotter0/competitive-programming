__int128 modexp(__int128 base, __int128 power, __int128 mod=1000000007)
{
	__int128 res=1;
	while(power)
	{
		if(power&1) res=(res*base)%mod;
		power>>=1;
		base=(base*base)%mod;
	}
	return res;
}


bool miller_rabin(__int128 num, __int128 k)
{
	__int128 s=0,d=num-1,one=1,temp;
	while(!(d&1)) d>>=1,s++;

	bool flag=true;
	temp=modexp(k,d,num);
	if(temp==1 || temp==num-1) return 1;
	for(int i=0;i<s;i++)
	{
		temp=(temp*temp)%num;
		if(temp==1) return 0;
		if(temp==num-1) return 1;
	}
	return 0;
}

bool prime(__int128 num)
{
	vector<int>A{2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67};
	for(auto x:A) if(x==num) return 1;
	if(!(num&1)) return 0;

	bool flag=true;
	for(auto x:A) flag&=miller_rabin(num, x);
	return flag;
}