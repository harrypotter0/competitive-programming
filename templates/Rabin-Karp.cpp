void solve(string& pat, string& s)
{
	n=pat.length();
	__int128 match1=0,match2=0,match3=0;
	for(long long i=1;i<=n;i++)
	{
		match1=(match1+ pat[i-1])%MOD;
		match2=(match2+ i*pat[i-1])%MOD;
		match3=(match3+ i*i*pat[i-1])%MOD;
	}

	vector<int>found;

	__int128 hash1=0,hash2=0,hash3=0,l=1,y=n+1,z=((n+1)*(n+1))%MOD;
	queue<char>slide;
	for(int i=0;i<s.length();i++)
	{
		char c=s[i];
		slide.push(c);
		if(l<=n)
		{
			hash1=(hash1+c)%MOD;
			hash2=(hash2+l*c)%MOD;
			hash3=(hash3+l*l*c)%MOD;
		}
		if(l>n)
		{
			hash1=(hash1+c)%MOD;
			hash2=(hash2+y*c)%MOD;
			hash3=(hash3+z*c)%MOD;
		}
		
		if(l>=n)
		{
			if(l>n)
			{
				hash3=(hash3 + hash1 - (hash2*2) +MOD)%MOD;
				hash2=(hash2 - hash1 + MOD)%MOD;
				hash1=(hash1 -slide.front() + MOD)%MOD;
				slide.pop();
			}

			if(hash1==match1 && hash2==match2 && hash3==match3) cout<<int(l-n)<<"\n";
		}
		l++;
	}

	if(found.size()>0)
	{
		for(auto x: found)
			cout<<x<<"\n";
	}
	else
		cout<<"\n";
}