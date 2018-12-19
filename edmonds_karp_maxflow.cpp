#define INF 1000000

vector< int >par;
vector< vector<int> >adj,cap;

int bfs(int src, int dest)
{
	fill(par.begin(),par.end(),-1);
	par[src]=-2;

	queue< pair<int,int> >q;
	q.push({src,INF});

	int cur,val,nval;
	while(!q.empty())
	{
		cur = q.front().first;
		val = q.front().second;
		q.pop();
		// cout<<"curr: "<<cur<<"\n";
		for(auto x:adj[cur])
		{
			if(par[x]==-1 && cap[cur][x]>0)
			{
				par[x]=cur;
				nval = min(val, cap[cur][x]);

				if(x==dest) return nval;

				q.push({x,nval});
			}
		}
	}
	return 0;
}

int maxflow(int src, int dest)
{
	int flow = 0;
	int newflow;

	while(newflow = bfs(src,dest))
	{
		// cout<<newflow<<"\t newflow \n";
		flow += newflow;
		for(int i=dest; i!=src; i=par[i])
		{
			// cout<<"par:"<<par[i]<<" idx:"<<i<<"\n";
			cap[par[i]][i] -= newflow;
			cap[i][par[i]] += newflow;
		}
	}
	return flow;
} 

void input(int ver, int edges)
{
	par.resize(ver+1);
	adj.resize(ver+1);
	cap.resize(ver+1);
	for(int i=1;i<=ver;i++) cap[i].resize(ver+1);

	int from,to,weight;
	for(int i=1; i<=edges; i++)
	{
		cin>>from>>to>>weight;
		cap[from][to] = weight;
		adj[from].push_back(to);
		adj[to].push_back(from);
	}
}