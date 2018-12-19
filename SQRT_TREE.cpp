
inline int op(int val1, int val2)
{
	return (1LL*val1*val2)%prime;
}

vector<int>arr;
vector< vector<int> >prefix,suffix;

void build(int n)
{
	int layers = 0;
	while( (1<<layers) <n) layers++;
	layers++;

	suffix.resize(layers);
	prefix.resize(layers);

	for(int i=0;i<layers;i++)
	{
		suffix[i].resize(n);
		prefix[i].resize(n);
	}

	for(int sz=2,lev=1; sz<=n; sz<<=1,lev++)
	{
		for(int i=0; i<n; i+=sz)
		{
			suffix[lev][i]=arr[i];
			for(int j=1;j<sz;j++) suffix[lev][i+j] = op(suffix[lev][i+j-1], arr[i+j]);

			prefix[lev][i+sz-1]=arr[i+sz-1];
			for(int j=1;j<sz;j++) prefix[lev][i+sz-1-j] = op(prefix[lev][i+sz-j], arr[i+sz-1-j]); 
		}
	}
}

int query(int l, int r)
{
	if(l==r) return arr[l];
	if(l+1==r) return op(arr[l],arr[r]);

	int bit = (l^r);
	int msb = 31 - __builtin_clz(bit);

	if((l+(1<<msb-1)==r) && !((r+1)%(1<<msb))) 
	{
		return prefix[msb][l];
	}
	else
	{
		return op(prefix[msb][l], suffix[msb][r]);
	}
}
