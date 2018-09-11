#include<stdio.h>

int main()
{
	
	int T;
	int N;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&N);
		if(N%2)
		{
			printf("%d\n",N-1);
		}
		else
		{
			printf("%d\n",N);
		}
	}
	
	return 0;
}