__int128 in()
{
	__int128 temp=0;
	string s;
	cin>>s;
	for(char c:s)
	{
		temp*=10;
		temp+=(c-'0');
	}
	return temp;
}

void out(__int128 x)
{
	stack<char>s;
	while(x)
	{
		s.push((x%10 +'0'));
		x/=10;
	}
	while(!s.empty())
	{
		cout<<s.top();
		s.pop();
	}
}