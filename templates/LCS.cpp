int lcs(string& a, string& b)
{
	int n=a.length();
	int m=b.length();

	vector< vector< int > >sol(n+1, vector<int>(m+1,0));
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(a[i-1]==b[j-1])
				sol[i][j]=sol[i-1][j-1]+1;
			else
				sol[i][j]=max(sol[i-1][j],sol[i][j-1]);
		}
	}
	return sol[n][m];
}
