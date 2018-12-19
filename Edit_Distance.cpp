int levenshtein_distance(string& a, string& b)
{
	int n=a.length(),m=b.length();

	vector< vector<int> >cost(n+1, vector<int> (m+1,0));
	for(int i=1;i<=n;i++)
	{
		cost[i][0]=i;
	}
	for(int i=1;i<=m;i++)
	{
		cost[0][i]=i;
	}

	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=n;j++)
		{
			cost[j][i]=min({cost[j-1][i]+1, cost[j][i-1]+1, cost[j-1][i-1]+(a[j-1]!=b[i-1])});
		}
	}
	return cost[n][m];
}
