// O(V^2)
#include<stdio.h>
#include<limits.h>
#define V 5

int minkey(int key[], bool mstSet[]){
    int min = INT_MAX, min_index;
    for(int v=0;v<V;v++)
        if(mstSet[v]==false && key[v]<min)
            min = key[v], min_index = v;
    return min_index;
}

int printMST(int parent[], int n, int graph[V][V]){
    printf("Edge Weight");
    for(int i=1;i<V;i++)
        printf("%d - %d  %d\n",parent[i], i, graph[i][parent[i]]);
}

void primMST(int graph[V][V]){
    int parent[V]; // array to store constructed MST 
    int key[V]; // key values used to pick min weight edge in cut
    bool mstSet[V]; // to represent set of vertices not yet included in MST

    for(int i=0;i<V;i++)
        key[i] = INT_MAX, mstSet[i]=false;

    key[0] = 0;
    parent[0] = -1;
    for(int count = 0 ;count<V-1; count++){
        int u = minkey(key, mstSet);
        mstSet[u] = true;
        for(int v=0;v<V;v++)
            if(graph[u][v] && mstSet[v]==false && graph[u][v]<key[v])
                parent[v] = u, key[v] = graph[u][v];
    }
    printMST(parent, V, graph);
}


int main()
{
   /* Let us create the following graph
          2    3
      (0)--(1)--(2)
       |   / \   |
      6| 8/   \5 |7
       | /     \ |
      (3)-------(4)
            9          */
   int graph[V][V] = {{0, 2, 0, 6, 0},
                      {2, 0, 3, 8, 5},
                      {0, 3, 0, 0, 7},
                      {6, 8, 0, 0, 9},
                      {0, 5, 7, 9, 0},
                     };
 
    // Print the solution
    primMST(graph);
 
    return 0;
}