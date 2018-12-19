vector<int>phi(1000001);
void pre()
{
	for(int i=1;i<=1000000;i++) phi[i]=i;
	for(int i=2;i<=1000000;i++)
	{
		if(phi[i]==i)
		{
			phi[i]-=1;
			for(int j=i+i;j<1000001;j+=i)
			{
				phi[j]-=(phi[j]/i);
			}
		}
	}
}