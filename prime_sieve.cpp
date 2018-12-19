vector<bool>isprime(100000001,1);
void pre()
{
	for(int i=2;i<100000001;i++)
	{
		if(isprime[i])
		{
			if(i<10001)
			{
				for(int j=i*i;j<100000001;j+=i)
					isprime[j]=0;
			}
		}
	}
}
