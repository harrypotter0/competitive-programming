long long kadane(auto& v)
{
	int n=v.size();
	long long msum=0,curr=0,least=-1000000;
	for(int i=0;i<n;i++)
	{
		least=max(least,v[i]);

		curr+=v[i];
		if(curr > msum) msum=curr;
		if(curr < 0) curr=0;
	}
	if(least>=0)
		return msum;
	else 
		return least;
}
