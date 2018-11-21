void manchar(string& str)
{
	string s="#";
	for(auto x:str) s=s+x+"#";

	vector<int>P(s.length(),0);
	int center=0,right=-1,radius;

	for(int i=0;i<s.length();i++)
	{
		if(i<=right)
			radius=min(P[2*center - i], right-i);
		else
			radius=0;

		while(i+radius<s.length() && i-radius>=0 && s[i+radius]==s[i-radius])
			radius++;

		P[i]=radius;
		if(i+radius-1 >right)
		{
			center=i;
			right=i+radius-1;
		}
	}
	for(int i=0;i<s.length();i++) 
	{
		if(i&1) P[i]=(P[i]-1);
		else P[i]=(P[i]-1);
	}

	for(auto x:P) cout<<x<<" "; cout<<"\n";
}