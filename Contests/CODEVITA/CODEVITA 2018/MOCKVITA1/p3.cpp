// REF: geeksforgeeks.org/topological-sorting-indegree-based-solution/
#include <iostream>
#include <vector>
#include <list>
#include <queue>
using namespace std;
class Graph {
private:
    unsigned vertices;
    std::list<unsigned> *adj_list;
public:
    Graph(unsigned);
    ~Graph();
    void add_edge(unsigned, unsigned);
    string topsort();
};

Graph::Graph(unsigned v)
{
    vertices = v;
    adj_list = new std::list<unsigned>[v];
}

Graph::~Graph()
{
    delete [] adj_list;
}

void Graph::add_edge(unsigned src, unsigned dst)
{
    adj_list[src].push_back(dst);
}

string Graph::topsort()
{
    /* create a vector to store in-degree of all vertices
     *  vector sized `vertices'  all initialized to zero
     * */
    std::vector<unsigned> in_degree(vertices, 0);
    std::string a,b;

    /* traverse adjacency lists to fill up in_degree[]
     *  this step takes O(V+E) time
     * */
    std::list<unsigned>::iterator it;
    for (unsigned i = 0; i < vertices; i++)
        for (it = adj_list[i].begin(); it != adj_list[i].end(); it++)
            in_degree[*it]++;

    /* create a queue and enqueue all vertices with in-degree 0 */
    std::queue<unsigned> que;
    for (unsigned i = 0; i < vertices; i++){
        if (in_degree[i] == 0){
        que.push(i);  
        b += char(65+i);
        cout<<"b"<<b<<endl;
        } 
    }
    if (que.size()>=2){
        a += b;
    }
    b = "";
        

    /* bookkepping for count of visited vertices */
    unsigned visited = 0;
    /* vector to store topological sort result */
    std::vector<unsigned> top_order;

    while (que.size()) {
        /* extract front of queue(dequeue) and add it to result vector */
        unsigned top = que.front();
        que.pop();
        top_order.push_back(top);

        /* iterate all its(top's) adjacent vertices and
         *  decrease their in-degree by 1
         * */
        for (it = adj_list[top].begin(); it != adj_list[top].end(); it++)
            /* once in-degree becomes zero  push it to queue */
            if (--in_degree[*it] == 0)
                que.push(*it);

        visited++;      /* update visited vertices */
    }

    /* if visited not equal to #vertices  there is a cycle */
    if (visited != vertices) {
        std::cerr << "[ERROR] There exists a cycle in the graph\n";
        return "bkchodi";
    }

    /* print out topological sort result */
    // for (unsigned i = 0; i < vertices; i++)
    //     std::cout << top_order[i] << ' ';
    // std::cout << '\n';
    return a;
}

int main()
{
    int n,m;
    cin>>n>>m;
    Graph g(n);
    // g.topsort();
    string str,ans;

    for (int i=0;i<m;i++){
        cin>>str;
        for (int index = 0; index < str.length()-2; index+=2)
        {
            int src = int(str[index])-65;
            int dest = int(str[index+2])-65;
            g.add_edge(src,dest);
        }
    }

    ans = g.topsort();
    if(ans.length())
        for(int i=0;i<ans.length();i++)
            cout<<ans[i]<<" ";
    else
        cout<<"N/A"<<endl;

    return 0;
}