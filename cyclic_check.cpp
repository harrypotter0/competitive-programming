#include<bits/stdc++.h>
using namespace std;
vector<int>adj[100];
bool vis[100];
bool instack[100];
bool dfs(int v)
{
	vis[v]=1;
	instack[v]=1;
	for(int i=0;i<adj[v].size();i++)
	{
		int to=adj[v][i];
		if(!vis[to])
		{
			if(dfs(to))
			return true;
		}
		else if(instack[to])
		return true;
	}
	instack[v]=0;
	return false;
}
int main()
{
	int n,m;cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		int u,v;cin>>u>>v;
		adj[u].push_back(v);
	}
	bool flag=0;
	for(int i=0;i<n;i++)
	if(!vis[i])
	{
		flag=flag || dfs(i);
	}
	if(flag)
	cout<<"YES\n";
	else
	cout<<"NO\n";
}