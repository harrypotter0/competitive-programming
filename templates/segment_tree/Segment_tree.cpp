//Bottom-up

vector<long long>tree(2*(1e5+1));
 
void build(long long n)
{
	for(long long i=n-1;i>0;--i)
		tree[i]=tree[i<<1]+tree[i<<1|1];
}
 
void modify(long long pos, long long val, long long n)
{
	pos+=n;
	for(tree[pos]=val; pos>1; pos>>=1)
	{
		tree[pos>>1]= (tree[pos] + tree[pos^1]);
	}
}
 
long long sum(long long l, long long r, long long n)
{
	long long ans=0;
	for(l+=n, r=r+n+1; l<r ; l>>=1, r>>=1)
	{
		if(l&1) ans+=tree[l++];
		if(r&1) ans+=tree[--r];
	}
	return ans;
}

//Top-down
