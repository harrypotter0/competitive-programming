#define D 101

vector<int>mu(D,0);
vector<bool>isprime(D,1);

void pre()
{
	int sq=sqrt(D);
	for(int i=2;i<D;i++)
	{
		if(isprime[i])
		{
			mu[i]++;
			for(int j=(i<<1); j<D; j+=i)
			{
				isprime[j]=0;
				mu[j]++;
			}
		}
		if(mu[i]&1) mu[i]=-1;
		else mu[i]=1;
	}
	mu[1]=1;
	for(int i=2; i<=sq; i++)
	{
		if(isprime[i])
		{
			int k=i*i;
			for(int j=k; j<D; j+=k)
			{
				mu[j]=0;
			}
		}
	}
}