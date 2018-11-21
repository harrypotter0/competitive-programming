void build(int n, vector<long long>&tree)
{
	for(int i=1;i<=n;i++)
	{
		if(i+(i&(-i))<=n)
		{
			tree[i+(i&(-i))]+=tree[i];
		}
	}
}

void update(int pos,long long val, int n, vector<long long>&tree)
{
	tree[pos]+=val;
	while(pos+pos&(-pos)<=n)
	{
		pos+=pos&(-pos);
		tree[pos]+=val;
	}
}

long long query(int idx, vector<long long>&tree)
{
	lld ans=tree[idx];
	while(idx-idx&(-idx)>0)
	{
		idx-=idx&(-idx);
		ans+=tree[idx];
	}
	return ans;
}