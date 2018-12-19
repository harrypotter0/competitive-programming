int counter=0;

void cycle(int i, auto& disc, auto& low, auto& adj, auto& path, auto& vis)
{
	disc[i]=low[i]=++counter;
	path.push(i);
	vis[i]=true;

	for(auto x:adj[i])
	{
		if(disc[x]==-1)
		{
			cycle(x,disc,low,adj,path,vis);
			low[i]=min(low[i],low[x]);
		}
		else if(vis[x])
		{
			low[i]=min(low[i],disc[x]);
		}
	}

	if(low[i]==disc[i])
	{
		while(path.top()!=i)
		{
			cout<<path.top()<<" ";
			vis[path.top()]=false;
			path.pop();
		}
		cout<<i<<"\n";
		vis[i]=false;
		path.pop();
	}
}

void tarjan_scc(vector< list<int> >& adj)
{
	int n=adj.size();

	vector<int>low(n,-1);
	vector<int>disc(n,-1);
	stack<int>path;
	vector<bool>vis(n,0);

	for(int i=1;i<n;i++)
	{
		if(disc[i]==-1)
		{
			cycle(i,disc,low,adj,path,vis);
		}
	}
}