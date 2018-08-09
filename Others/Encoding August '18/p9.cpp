    #include <bits/stdc++.h>
    using namespace std;
    #define LL long long
    #define PB push_back
    #define N 2000100
    #define LB lower_bound
    #define M 1000000007
    #define UB upper_bound
    #define MP make_pair
    #define LD long double
    #define F first
    #define INF LONG_MAX
    #define S second
     
    int main() {
    	// your code goes here
    	LL i,j,k,l,m,t,x,y,z,f,d,q,a[N],n;
    	ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        cin>>t;
        while(t--)
        {
            cin>>n>>m;
            vector<pair<LL,LL>>adj[n+1];
            for(i=0;i<m;i++)
            {
                cin>>x>>y;
                adj[x].PB(MP(y,0));
                adj[y].PB(MP(x,1));
            }
            cin>>x>>y;
            multiset< pair<LL, LL> > setds;
            vector<LL> dist(n+1, INF);
            setds.insert(make_pair(0, x));
            dist[x] = 0;
            while (!setds.empty())
            {
                pair<LL, LL> tmp = *(setds.begin());
                setds.erase(setds.begin());
                LL u = tmp.second;
                // cout<<u<<endl;
                vector< pair<LL, LL> >::iterator it;
                for (it = adj[u].begin(); it != adj[u].end(); it++)
                {
                    LL v = (*it).first;
                    // cout<<v<<endl;
                    LL weight = (*it).second;
                    if (dist[v] > dist[u] + weight)
                    {
                        if (dist[v] != INF)
                            setds.erase(setds.find(make_pair(dist[v], v)));
                        dist[v] = dist[u] + weight;
                        setds.insert(make_pair(dist[v], v));
                    }
                }
            }
            if(dist[y]==INF)
                cout<<-1<<endl;
            else    
                cout<<dist[y]<<endl;
        }
    	return 0;
    } 

