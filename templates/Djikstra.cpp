
//MIN HEAP 

vector< list< pair<int, int> > >adj;
void edge(int u, int v, int w)
{
	adj[u].push_back({w,v});
	// adj[v].push_back(w,u);
}
int dj(int src, int dest, int n)
{
	vector< int >dist(n+1,99999999);
	vector< bool >vis(n+1,0);
	priority_queue< pair<int,int> , vector<pair<int,int> >, greater< pair<int,int> > >pq;
	dist[src]=0;
	pq.push({0,src});

	int count=1;

	while(!pq.empty())
	{
		int ver=pq.top().second;
		int wt=pq.top().first;
		pq.pop();
		// if(ver==dest) break;
		if(vis[ver]) continue;
		vis[ver]=1;
		for(auto x:adj[ver])
		{
			if((wt+x.first)< dist[x.second])
			{
				dist[x.second]=wt+x.first;
				pq.push({dist[x.second],x.second});
			}
		}
	}
	return dist[dest];
}

//Adjacency Matrix

void djikstra(int **cost,int source, int n)
{
    vector<bool>visited(n+1,false);
    vector<int>dist(n+1,999999);
    dist[source]=0;
    for(int a=1;a<=n;a++)
    {
        int max=999999;
        for(int b=1;b<=n;b++)
        {
            if(!visited[b] &&dist[b]<max)
            {
                max=dist[b];
                source=b;
            }
        }
        visited[source]=true;
        for(int a=1;a<=n;a++)
        {
            if(dist[a]>(cost[source][a]+dist[source]) && !visited[a])
            {
                dist[a]=cost[source][a]+dist[source];
            }
        }
    }
    for(int a=1;a<=n;a++)
        cout<<a<<"\t"<<dist[a]<<endl;
    return ;
}
