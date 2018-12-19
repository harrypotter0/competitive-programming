void division(int num, int den)
{
	string s;
	int x=(num/den);
	s=to_string(x);
	num%=den;
	num*=10;
	if(num!=0)
	{
		s+=".";
		for(int i=1;i<1000;i++)
		{
			int r=(num%den);
			int d=(num/den);
			s+=(d+48);
			r*=10;
			num=r;
		}
	}
	
	cout<<s;
}