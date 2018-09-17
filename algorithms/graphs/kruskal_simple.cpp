#include<stdio.h>
#include<limits.h>
#define n 5 
int parent[100];
int find(int i){
    while(parent[i])
        i=parent[i];
    return i;
}
int union1(int i,int j){
    if(i!=j){
        parent[j] = i;
        return 1;
    }
    return 0;
}

void kruskalMST(int cost[n][n]){
    int edge_count = 0;int min; int a,b; int mincost = 0;
    for(int i =0;i<n;i++)
        for(int j =0;j <n;j++){
            if (cost[i][j]==0)
                cost[i][j] = INT_MAX;                
        }
    printf("\n\n\n");
    while(edge_count< n-1){
        min = INT_MAX;
        for(int i =0 ; i<n;i++){
            for(int j =0;j<n;j++){
                if(cost[i][j]<min){
                    min = cost[i][j];
                    a = i;
                    b = j;
                }
            }
        }
        a = find(a);
        b = find(b);
        if(union1(a,b)){
            printf("Edge %d: (%d,%d) cost:%d \n",edge_count++, a, b, min);
            mincost+=min;
        }
        cost[a][b] = cost[b][a] = INT_MAX;
    }
    printf("\n Min Cost= %d\n", mincost);
}



// driver program to test above function
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
   int cost[n][n] = {{0, 2, 0, 6, 0},
                      {2, 0, 3, 8, 5},
                      {0, 3, 0, 0, 7},
                      {6, 8, 0, 0, 9},
                      {0, 5, 7, 9, 0},
                     };
  
    // Print the solution
    kruskalMST(cost);
  
    return 0;
}