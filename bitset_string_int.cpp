
int bitset_to_int(string s)
{
	int num = 0;
	for(int i=0; i<s.length(); i++)
	{
		if(s[i]=='1')
		{
			num += (1<<i);
		}
	}
	return num;
}

string int_to_bitset(int num)
{
	int n=0;
	while( (1<<n) < num ) n++;
	string s;
	s.resize(n);
	fill(s.begin(), s.end(), '0');
	for(int i=0;i<n;i++)
	{
		if(num & (1<<i)) s[i]='1';
	}
	return s;
}