#include <iostream>
#include <cstdio>
using namespace std;
int m,x,y,p,q;
double s;
int calc(int p,int i){
	int f=0,pos;
	if(p>=i-1)p-=i-1,f=1;
	s=i,s*=x,s/=y;
	pos=(int)s;
	if(p>=pos)p++;
	return p*2+f;
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		scanf("%d%d%d",&m,&x,&y);
		p=0,q=1;
		for(int i=2;i<=m/2;i++)p=calc(p,i),q=calc(q,i);
		printf("%d\n",(p+1)^(q+1));
	}
	return 0;
}
/*
Input:
1
6 1 2

Output:
4
*/
