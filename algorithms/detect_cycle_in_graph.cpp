// DFS can be used
#include<iostream>
#include<limits.h>
#include<list>

using namespace std;

class Graph{
    int V;
    list<int> *adj;
    bool isCyclicUtil(int v, bool visited[], bool *rs);
    public:
        Graph(int V); //constructor
        void addEdge(int v, int w);
        bool isCyclic();
};

Graph::Graph(int V){
    this->V = V;
    adj = new list<int>[V];
}

void Graph::addEdge(int v, int w){
    adj[v].push_back(w);
}

/*
To detect a back edge, we can keep track of vertices currently in recursion stack of function for DFS traversal. 
If we reach a vertex that is already in the recursion stack, then there is a cycle in the tree. 
The edge that connects current vertex to the vertex in the recursion stack is a back edge. 
We have used recStack[] array to keep track of vertices in the recursion stack.
*/

bool Graph::isCyclicUtil(int v, bool visited[], bool *recStack){
    if(visited[v]==false){
        visited[v] = true;
        recStack[v] = true;
        list<int>::iterator i;
        for(i=adj[v].begin();i!=adj[v].end();i++){
            if(!visited[*i] && isCyclicUtil(*i, visited,recStack))
                return true;
            else if (recStack[*i])
                return true;
        }
    }
    recStack[v] = false;
    return false;
}

bool Graph::isCyclic(){
    bool *visited = new bool[V];
    bool *recStack = new bool[V];
    for(int i=0;i<V;i++){
        visited[i] = false;
        recStack[i] = false;
    }
    for(int i=0;i<V;i++)
        if(isCyclicUtil(i, visited, recStack))
            return true;
    return false;
}

int main()
{
    // Create a graph given in the above diagram
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);
 
    if(g.isCyclic())
        cout << "Graph contains cycle";
    else
        cout << "Graph doesn't contain cycle";
    return 0;
}
