    #include <iostream>
    using namespace std;
    #include <bits/stdc++.h>
    #define ll long long
    #define pll pair<int,int>
    #define REP(i, a, b) \
    	for (int i = int(a); i <= int(b); i++)
    #define case int t;cin>>t;while(t--)
    #define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    stack<int> s;
    bool visited[11] = {false};
    vector<int> v[11];
    void dfs(int n){
        visited[n] = true;
        sort(v[n].begin(),v[n].end(),greater<int>());
        REP(i,0,v[n].size()-1){
            if(visited[v[n][i]]==false){
                dfs(v[n][i]);
            }
        }
        s.push(n);
    }
    void topo(int n){
        dfs(n);
    }
    int main(){
        int n,m;
        cin>>n>>m;
        int x,y;
        REP(i,0,m-1){
            cin>>x>>y;
            v[x].push_back(y);
        }
        for(int i=n;i>=1;i--){
            if(!visited[i]){
                topo(i);
            }
        }
        while(!s.empty()){
            cout<<s.top()<<" ";
            s.pop();
        }
    }

    