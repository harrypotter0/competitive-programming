#include <bits/stdc++.h>
using namespace std;
const int inf = 1e9;
// Poori Duniya bhadwi hai
int dp[15][100][1 << 15];
int n;

struct edge {
    int u, v, w, energy;
    edge(int a, int b, int c, int d) {
        u = a, v = b, w = c, energy = d;
    }
};

vector<edge> graph[20];

// O(2^n*n^2*E)
int solve(int u, int mask, int energy) {
    if (mask == ((1 << n) - 1)) // if mask is the last one return 0 or inf for addition
        return energy >= 0 ? 0 : inf;
    if (energy <= 0) //if energy is negative you can't reach
        return inf;
    int& ret = dp[u][energy][mask];
    if (ret != -1) return ret;

    ret = inf;
    // main loop for recursive calls 
    for (edge e: graph[u]) {// O(E)
        int v = e.v, w = e.w, req_energy = e.energy;
        if (mask & (1 << v)) // check is vth bit is set
            continue;
        else
            ret = min(ret, solve(v, mask | (1 << v), energy - req_energy) + w); //O(2^n*n^2)
    }
    return ret;
}

int main(void) {
    int  m, energy;
    memset(dp, -1, sizeof(dp));
    scanf("%d %d %d", &n, &m, &energy);
    for (int i = 0; i < m; i++) {
        int u, v, w, en;
        scanf("%d %d %d %d", &u, &v, &w, &en);
        u--; v--;
        graph[u].push_back(edge(u, v, w, en));
        graph[v].push_back(edge(v, u, w, en));
    }
    int ans = solve(0, 1, energy);
    printf("%d\n", ans >= inf ? -1 : ans);
    return 0;
}
