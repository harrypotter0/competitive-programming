#include <iostream>
#include <algorithm>
#include <vector>
#include <sstream>
#include <cmath>
#include <cstring>
#include <map>
#include <stack>
#include <queue>
#include <list>
#include <set>
#include <fstream>

#define PII pair<int,int>
#define PIVLLD pair<int, vector<long long int>
#define PIVI pair<int, vector<int> >
#define PIS pair<int, string>
#define VI vector<int>
#define VLLD vector<long long int>
#define VS vector<string>
#define OUT(it,x) for(auto (it)=(x).begin();(it)!=(x).end();(it)++) cout<<*(it)<<" "; cout<<"\n"
#define POUT(it,Begin,End) for(auto (it)=(Begin);(it)!=(END);(it)++) cout<<*(it)<<" "; cout<<"\n"
#define FOR(i,b,e) for(int (i)=(b); (i)<=(e); (i)++)
#define RFOR(i,b,e) for(int (i)=(b); (i)<=(e); (i)--)
#define ALL(x) (x).begin(),(x).end()

#define INF 0xfffffff

using namespace std;

class Graph
{
	int v;
	int **cost;
public:
	Graph(int v)
	{
		this->v=v;
		cost = new int* [v+1];
		FOR(i,1,v)
		cost[i]=new int[v];
		FOR(i,1,v)
		{
			FOR(j,1,v)
			cost[i][j]=INF;
		}
	}
	addCost(int u,int v, int w)
	{
		cost[u][v]=cost[v][u]=w;
	}
	void distance();
	void print()
	{
		FOR(i,1,v)
		{
			FOR(j,1,v)
			{
				cout<<cost[i][j]<<" ";
			}
			cout<<"\n";
		}
	}
};
void Graph::distance()
{
	FOR(k,1,v)
	{
		VI dist(v+1,INF);
		vector<bool> visited(v+1,false);
		int source=k;
		dist[source]=0;
		FOR(i,1,v)
		{
			int max=INF;
			FOR(j,1,v)
			{
				if(dist[j]<max && !visited[j])
				{
					max=dist[j];
					source=j;
				}
			}
			visited[source]=true;
			FOR(j,1,v)
			{
				if(dist[j]>(dist[source]+cost[source][j]) && !visited[j])
				{
					dist[j]=(dist[source]+cost[source][j]);	
				}
			}
		}
		FOR(j,1,v)
		{
			cost[k][j]=cost[j][k]=dist[j];
		}
	}
}

int main()
{
	cout<<"No of vertices\t";
	int n;
	cin>>n;
	Graph g(n);
	cout<<"No of edges\t";
	int e;
	cin>>e;
	FOR(i,1,e)
	{
		int x,y,z;
		cin>>x>>y>>z;
		g.addCost(x,y,z);
	}
	g.distance();
	g.print();
}