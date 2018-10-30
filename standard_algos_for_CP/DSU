//Graph_UnionFindCycleDetect.cpp
/*
	Author: HITMAN_47
	Union - Find Algo to detect cycle
*/
#include<bits/stdc++.h>
using namespace std;
#define pii pair<int,int>

int n,m;

int find(int parent[],int x)
{
	if(parent[x]==-1)
		return x;
	return find(parent,parent[x]);
}

void union1(int parent[],int x,int y)
{
	int xs = find(parent,x);
	int ys = find(parent,y);
	parent[xs] = ys;
}

int iscyclic(pii p[])
{
	int parent[n+1];
	memset(parent,-1,sizeof parent);

	for(int i=0;i<m;i++)
	{
		int x = find(parent,p[i].first);
		int y = find(parent,p[i].second);

		if(x==y)
			return 1;
		union1(parent,x,y);
	}
	return 0;
}

int main()
{	
//	int n,m;
	cin>>n>>m;
	pair<int,int> p[n+1];
	int a,b;
	for(int i=0;i<m;i++){
		cin>>a>>b;
		p[i] = {a,b};
	}
	if(iscyclic(p))
		cout<<"Cycle is Present\n";
	else
		cout<<"No cycle is present";
	
	return 0;
}