typedef struct 
{
	int idx,firstRank,secondRank;
}data;

bool compare(data& p1, data& p2)
{
	if(p1.firstRank==p2.firstRank) return p1.secondRank<p2.secondRank;
	return p1.firstRank<p2.firstRank;
}

void suffix_array(string& s)
{
	vector< vector<int> >tab( 20, vector<int>(s.length() ) );

	for(int i=0; i<s.length(); i++)
		tab[0][i]=s[i]-'a';

	vector< data >arr(s.length());

	for(int cnt=1,step=1; cnt<s.length(); cnt*=2, ++step)
	{
		for(int i=0; i<s.length(); i++)
		{
			arr[i].firstRank = tab[step-1][i];
			arr[i].secondRank = (i+cnt)<s.length()? tab[step-1][i+cnt]: -1;
			arr[i].idx=i;
		}

		sort(arr.begin(),arr.end(),compare);
		tab[step][arr[0].idx] = 0;
		for(int i=1,rank=0; i<s.length(); ++i)
		{
			if(arr[i-1].firstRank != arr[i].firstRank || arr[i-1].secondRank != arr[i].secondRank) rank++;
			tab[step][arr[i].idx] = rank;
		}
	}

	for(int i=0;i<s.length();i++) 
	{
		cout<<arr[i].idx<<" ";
	}
}