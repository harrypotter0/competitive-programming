#include "bits/stdc++.h"
using namespace std;

const int N = 1e5 + 5;

int n , m , l;
long long a[N];

struct node {
	int lef;
	int righ;
	int ans;
	node() {
		lef = 0;
		righ = 0;
		ans = 0;
	}
};

node get_new_node() {
	return node();
}

node segtree[N << 2];

node merges(node a , node b) {
	node res = node();
	res.lef = a.lef;
	res.righ = b.righ;
	if(a.righ == 1 and b.lef == 1) {
		res.ans = a.ans + b.ans - 1;
	} else {
		res.ans = a.ans + b.ans;
	}
	return res; 
}


void upd(int node , int u , int v , int idx) {
	if(u > v or u > idx or v < idx) return;
	if(u >= idx and v <= idx) {
		segtree[node].lef = 1;
		segtree[node].righ = 1;
		segtree[node].ans = 1;
		return;
	}
	int m = (u + v) / 2;
	upd(node * 2 , u , m , idx);
	upd(1 + (node * 2) , m + 1 , v , idx);
	segtree[node] = merges(segtree[node * 2] , segtree[1 + (node * 2)]);
}

node query(int node , int u , int v , int l , int r) {
	if(u > v or u > r or v < l) {
		return get_new_node();
	}
	if(u >= l and v <= r) {
		return segtree[node];
	}
	int m = (u + v) / 2;
	return merges(query(node * 2 , u , m , l , r) , query(1 + (node * 2) , m + 1 , v , l , r));
}


void solve() {
	for(int i = 0; i < N << 2; ++i) segtree[i] = node();
	scanf("%d%d%d" , &n, &m, &l);
	for(int i = 1; i <= n; ++i) scanf("%lld", a + i);
	for(int i = 1; i <= n; ++i) {
		if(a[i] > l) {
			upd(1 , 1 , n , i);
		}
	}
	while(m--) {
		int typ; scanf("%d", &typ);
		if(!typ) {
			printf("%d\n" , query(1 , 1 , n , 1 , n).ans);
		} else {
			int p, d; scanf("%d%d" , &p, &d);
			if(a[p] <= l) {
				a[p] += d;
				if(a[p] > l) {
					upd(1 , 1 , n , p);
				}
			}
		}
	}
}

int main() {
	solve();
	return 0;
}