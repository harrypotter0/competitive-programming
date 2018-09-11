#include <bits/stdc++.h>
 
using namespace std;
 
#define N 100005
 
map<int,int> vis;
map<int,vector<int>> adj;
 
void dfs(int node) {
    vis[node] = 1;
    for (int child : adj[node])
        if(!vis[child])
            dfs(child);
}
 
 
int main()
{
    int n,m ;
    long long sum = 0;
    scanf("%d%d" , &n , &m);
    vector<pair<int,int>> v(n);

    //forming paired graph
    for(int i = 0 ; i < n ; ++i){
        int num;
        scanf("%d" , &num);
        v[i].first = num;
        v[i].second = i+1;
    }

    //connecting pairs
    for(int i = 0 ; i < m ; ++i){
        int num , fri;
        scanf("%d%d" , &num,&fri);
        adj[num].push_back(fri);
        adj[fri].push_back(num);
    }
 
    sort(v.begin() , v.end());
 
    for(int i = 0 ; i < n ; ++i){
        if(!vis[v[i].second]){
            sum += v[i].first;
            dfs(v[i].second);
        }
    }
    
////    
    printf("%lld\n" , sum);
    return 0;
}
