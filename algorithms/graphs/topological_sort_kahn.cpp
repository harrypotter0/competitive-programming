// Step-1: Compute in-degree (number of incoming edges) for each of the vertex present in the DAG and initialize the count of visited nodes as 0.

// Step-2: Pick all the vertices with in-degree as 0 and add them into a queue (Enqueue operation)

// Step-3: Remove a vertex from the queue (Dequeue operation) and then.

//     Increment count of visited nodes by 1.
//     Decrease in-degree by 1 for all its neighboring nodes.
//     If in-degree of a neighboring nodes is reduced to zero, then add it to the queue.

// Step 5: Repeat Step 3 until the queue is empty.

// Step 5: If count of visited nodes is not equal to the number of nodes in the graph then the topological sort is not possible for the given graph.

#include<bits/stdc++.h>
using namespace std;

class Graph{
    int V;
    list<int>*adj;
    public:
        Graph(int V);
        void addEdge(int u, int v);
        void topologicalSort();
};

Graph::Graph(int V){
    this->V = V;
    adj = new list<int>V;
}

void Graph::addEdge(int u, int v){
    adj[u].push_back(v);
}

void Graph::topologicalSort(){
    vector<int> in_degree(V,0);
    for(int u =0;u<V;u++){
        list<int>::iterator itr;
        for(itr= adj[u].begin(); itr!=adj[].end(); itr++)
            in_degree[*itr]++;
    }
    queue<int>q;
    for(int i=0;i<V;i++)
        if(in_degree[i]==0)
            q.push(i);
    int cnt =0;
    
}
