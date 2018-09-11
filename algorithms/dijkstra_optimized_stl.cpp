#include<bits/stdc++.h>
using namespace std;
# define INF 0x3f3f3f3f

class Graph{
    int V;
    list<pair<int,int>> *adj;
    public:
        Graph(int V);
        void addEdge(int u, int v, int w);
        void shortestPath(int s);
};
//memory for adjacency list
Graph::Graph(int V){
    this->V = V;
    adj = new list<pair<int,int>>[V];
}

void Graph::addEdge(int u, int v, int w){
    adj[u].push_back(make_pair(v,w));
    adj[v].push_back(make_pair(u,w));
}

void Graph::shortestPath(int src){
    set<pair<int,int>> setds;
    vector<int> dist(V, INF);       
    setds.insert(make_pair(0, src));
    dist[src] = 0;
    while(!setds.empty()){
        pair<int,int> tmp = *(setds.begin());
        setds.erase(setds.begin());
        int u = tmp.second;
        
    }
}


