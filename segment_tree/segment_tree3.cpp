// Single Element update Interval Query
#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

const int N = 100007;
const int TREE_SIZE = N*4 + 7;
const int SIZE = 50;

int n,q,arr[N];
vector < int > tree[TREE_SIZE];
vector < int > qry;
long long ans;

vector < int > merge_them(vector < int > a, vector < int > b) {
    int i=0,j=0;
    vector < int > ans;
    
    while(ans.size()<=SIZE && i<(int)(a.size()) && j<(int)(b.size())) {
        if(a[i]>=b[j]) ans.push_back(a[i++]);
        else ans.push_back(b[j++]);
    }
    
    while(ans.size()<=SIZE && i<(int)(a.size())) ans.push_back(a[i++]);
    while(ans.size()<=SIZE && j<(int)(b.size())) ans.push_back(b[j++]);

    return ans;
}

void build_tree(int a, int b, int node) {
    if(a>b) return;
    if(a==b) {
        tree[node].push_back(arr[a]);
        return;
    }
    build_tree(a,(a+b)>>1,node<<1);
    build_tree(((a+b)>>1)+1,b,(node<<1)|1);
    tree[node]=merge_them(tree[node<<1],tree[(node<<1)|1]);
}

void update_tree(int a, int b, int pos, int node, int value) {
    if(a>b || a>pos || b<pos) return;
    if(a==b) {
        tree[node].clear();
        tree[node].push_back(value);
        return;
    }
    update_tree(a,(a+b)>>1,pos,node<<1,value);
    update_tree(((a+b)>>1)+1,b,pos,(node<<1)|1,value);
    tree[node]=merge_them(tree[node<<1],tree[(node<<1)|1]);
}

vector < int > query_tree(int a, int b, int i, int j, int node) {
    if(a>b || a>j || b<i) return vector < int > ();
    if(a>=i && b<=j) return tree[node];
    return merge_them(query_tree(a,(a+b)>>1,i,j,node<<1),query_tree(((a+b)>>1)+1,b,i,j,(node<<1)|1));
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int i,type,x,y;
    
    scanf("%d %d", &n, &q);
    for(i=1;i<=n;i++) {
        scanf("%d", &arr[i]);
    }
    build_tree(1,n,1);
    while(q--) {
        scanf("%d %d %d", &type, &x, &y);
        if(type==1) {
            update_tree(1,n,x,1,y);
        }
        else {
            ans=0;
            qry=query_tree(1,n,x,y,1);
            for(i=0;i+2<(int)(qry.size());i++) {
                if(qry[i+1]+qry[i+2]>qry[i]) {
                    ans=0ll+qry[i]+qry[i+1]+qry[i+2];
                    break;
                }
            }
            printf("%lld\n", ans);
        }
    }
    
    return 0;
}
