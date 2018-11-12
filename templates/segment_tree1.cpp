#include <bits/stdc++.h>
#define author dipjal
using namespace std;

const int N = 1e5 + 5;
const int LGN = 25;
bool composite[N * 10];
int a[N];
int last [N * 10];
int tmp [LGN];
int lazy [N * 4];
int pt [N * 4];
pair < int , int > treemax [N * 4];
vector < int > tree [N * 4];
int mx [N * 4];
int tt , n , m , type , l , r;

void sieve() {
    composite[0] = composite[1] = true;
    memset(last , -1 , sizeof last);
    last[1] = 1;
    for(int i = 2; i < N * 10; ++i) {
        if(!composite[i]) {
            last[i] = i;
            for(int j = i * 2; j < N * 10; j += i) {
              composite[j] = true ;
               if(last[j] == -1) {
                last[j] = i;
              }
            }
        }
    }
}

pair < int , int > shift(pair < int , int > x , int y) {
    int u = x.first;
    int v = x.second;
    int w = y;
    for(int i = 1; i <= w; ++i) {
        u = u / last[u];
        v = last[u];
    }
    return make_pair(u , v);
}

pair < int , int > Merge(pair < int , int > u , pair < int , int > v) {
    if(u.second > v.second) return u;
    if(v.second > u.second) return v;
    if(last[u.first / u.second] <= last[v.first / v.second]) return u;
    return v;
}

void build(int node , int u , int v) {
    if(u > v) return;
    if(u == v) {
        int x = a[u];
        treemax[node] = make_pair(x , last[x]);
        return;
    }
    int m = (u + v) >> 1;
    build(node * 2 , u , m);
    build(1 + (node * 2) , m + 1 , v);
    treemax[node] = Merge(treemax[node * 2] , treemax[1 + (node * 2)]);
}

void update(int node , int u , int v , int l , int r ) {
    if(lazy[node] != 0) {
        treemax[node] = shift(treemax[node] , lazy[node]);
        if(u != v) {
            lazy[node * 2] += lazy[node];
            lazy[1 + (node * 2)] += lazy[node];
        }
        lazy[node] = 0;
    }
    if(u > v || u > r || v < l) return;
    if(u >= l && v <= r) {
        treemax[node] = shift(treemax[node] , 1);
        if(u != v) {
            lazy[node * 2] += 1;
            lazy[1 + (node * 2)] += 1;
        }
        return;
    }
    int m = (u + v) >> 1;
    update(node * 2 , u , m , l , r);
    update(1 + (node * 2) , m + 1 , v , l , r);
    treemax[node] = Merge(treemax[node * 2] , treemax[1 + (node * 2)]);
}

int query(int node , int u , int v , int l , int r) {
    if(lazy[node] != 0) {
        treemax[node] = shift(treemax[node] , lazy[node]);
        if(u != v) {
            lazy[node * 2] += lazy[node];
            lazy[1 + (node * 2)] += lazy[node];
        }
        lazy[node] = 0;
    }
    if(u > v || u > r || v < l) return 0;
    if(u >= l && v <= r) {
        return treemax[node].second;
    }
    int m = (u + v) >> 1;
    return max(query(node * 2 , u , m , l , r) , query(1 + (node * 2) , m + 1 , v , l , r) );
}

/*
1
6 7
2 5 8 10 3 44
*/

void Build(int node , int u , int v) {
    if(u > v) return;
    if(u == v) {
        mx[node] = last[a[u]];
       // printf("mx[%d] = %d\n" , node , mx[node]);
    } else {
    int m = (u + v) >> 1;
    Build(node * 2 , u , m);
    Build(1 + (node * 2) , m + 1 , v);
    mx[node] = max(mx[node * 2] , mx[1 + (node * 2)]);
    }
}

int Query(int node , int u , int v , int l , int r) {
    if(u > v || u > r || v < l) return 1;
    if(u >= l && v <= r) {
      //  printf("[%d %d] -> %d\n" , u , v , mx[node]);
        return mx[node];
    }
    int m = (u + v) >> 1;
    return max(Query(node * 2 , u , m , l , r) , Query(1 + (node * 2) , m + 1 , v , l , r) );
}

void Update(int node , int u , int v , int l , int r) {
    if(u > v || u > r || v < l) return;
    if(u == v) {
        a[u] /= last[a[u]];
        mx[node] = last[a[u]];
        return;
    }
    int x = Query(1 , 0 , n - 1 , u , v);
    if(x == 1) return;
    if(x > 1) {
        int m = (u + v) >> 1;
        Update(node * 2 , u , m , l , r);
        Update(1 + (2 * node) , m + 1 , v , l , r);
        mx[node] = max(mx[node * 2] , mx[1 + (node * 2)]);
    }
}

void print() {
    for(int i = 0; i < n && i < n; ++i) {
        printf("%d " , Query(1 , 0 , n - 1 , i , i) );
    }
    printf("\n");
}

int main() {
    sieve();
    scanf("%d" , &tt);
    vector < int > pps = vector < int > (25 , 1);
    while(tt--) {
       scanf("%d %d" , &n, &m);
       for(int i = 0; i < n; ++i) {
        scanf("%d" , &a[i]);
       }
       int tos = n * 4;
       for(int i = 0; i <= tos; ++i) {
        tree[i] = pps;
        lazy[i] = 0;
        pt[i] = 0;
        mx[i] = 0;
        treemax[i] = make_pair(1 , 1);
       }
       Build(1 , 0 , n - 1);
    //    print();
       for(; m ; --m) {
        scanf("%d %d %d" , &type , &l , &r);
        if(!type) {
           //printf("Before update : tree[%d][%d] = %d\n" , 3 , 0 , tree[3][0]);
           Update(1 , 0 , n - 1 , l - 1 , r - 1);
           //print();
           //printf("After update : tree[%d][%d] = %d\n" , 3 , 0 , tree[3][0]);
        } else {
            printf("%d\n" , Query(1 , 0 , n - 1 , l - 1 , r - 1) );
       }
    }
    }
    return 0;
}
