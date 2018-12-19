vector< vector<lld> >mat(4, vector<lld>(4,1));

void multiply(auto& m1, auto& m2)
{
	int n=m1.size();
	vector< vector< lld> >temp(n, vector<lld>(n,0));

	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			for(int k=0;k<n;k++)
				temp[i][j]=(temp[i][j] + m1[i][k] * m2[k][j])%MOD;

	m1=temp;
}

vector< vector<lld> > power_matrix(auto mat, int n)
{
	auto res=mat;
	n--;

	while(n)
	{
		if(n&1) multiply(res,mat);
		n>>=1;
		multiply(mat,mat);
	}
	return res;
}