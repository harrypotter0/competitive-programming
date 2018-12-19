vector< int >cycle;
int v1=0,v2=0;

void dfs(int i, auto& adj, auto& vis, auto& in_stack, auto& path)
{
	// cout<<i<<" "<<vis[i]<<" "<<in_stack[i]<<"\n";
	if(cycle.size()>0) return;
	if(in_stack[i])
	{
		cycle.push_back(i);
		while(path.top()!=i)
		{
			cycle.push_back(path.top());
			in_stack[path.top()]=0;
			path.pop();
		}
		cycle.push_back(i);
		in_stack[i]=0;
		return;
	}
	if(vis[i]) return;

	vis[i]=1;
	in_stack[i]=1;
	path.push(i);
	for(auto x:adj[i])
	{
		if(i==v1 && x==v2) continue;
		dfs(x,adj,vis,in_stack,path);
	}
	in_stack[i]=0;
	if(!path.empty() && path.top()==i)
		path.pop();
}

void find_cycle(vector< list<int> >& adj)
{
	int n=adj.size();
	vector<bool>vis(n,0),in_stack(n,0);
	for(int i=1;i<n;i++)
	{
		if(!vis[i])
		{
			stack<int>path;
			dfs(i,adj,vis,in_stack,path);
		}
	}
}