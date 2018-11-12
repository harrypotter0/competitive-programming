// Interval update Interval Query

#include <bits/stdc++.h>
#define MAX 1000005
 
using namespace std;
 
vector < pair <int, int> > v[MAX];
vector <int> primes;
vector < pair <int, pair <int, int> > > vv;
int A[MAX];
 
struct node {
	int val;
	node *left, *right;
	node() { }
	node(int val, node *left, node *right)
	{
		this->val = val, this->left = left, this->right = right;
	}
};
 
node *segment[2000005];
 
void pre()
{
	for ( int i = 2; i <= 1000000; i++ ) {
		if ( !v[i].empty() ) continue;
		for ( int j = i; j <= 1000000; j += i ) {
			int k = j, cnt = 0;
			while ( k % i == 0 ) k /= i, cnt++;
			v[j].push_back(make_pair(i, cnt));
		}
	}
	return;
}
 
void update(node *prev, node *curr, int left, int right, int idx, int val)
{
	if ( left > right || left > idx || right < idx ) return;
	if ( left == right ) {
		curr->val = prev->val + val;
		return;
	}
	int mid = (left + right)/2;
	if ( idx <= mid ) {
		curr->right = prev->right;
		curr->left = new node(0, NULL, NULL);
		update(prev->left, curr->left, left, mid, idx, val);
	}
	else {
		curr->left = prev->left;
		curr->right = new node(0, NULL, NULL);
		update(prev->right, curr->right, mid + 1, right, idx, val);
	}
	curr->val = curr->left->val + curr->right->val;
}
 
int query(node *curr, int left, int right, int i, int j)
{
	if ( left > right || left > j || right < i ) return 0;
	if ( left >= i && right <= j ) return curr->val;
	int mid = (left + right)/2;
	return query(curr->left, left, mid, i, j) + query(curr->right, mid + 1, right, i, j);
}
 
void build(node *curr, int left, int right)
{
	curr->right = curr->left = new node(0, NULL, NULL);
	if ( left == right ) return;
	int mid = (left + right)/2;
	build(curr->left, left, mid);
	build(curr->right, mid + 1, right);
}
 
int main()
{
	int n, q, l, r, x, y;
	pre();
	
	scanf("%d", &n);
	
	for ( int i = 0; i < n; i++ ) {
		scanf("%d", &A[i]);
		for ( int j = 0; j < (int)v[A[i]].size(); j++ ) {
			vv.push_back(make_pair(v[A[i]][j].first, make_pair(v[A[i]][j].second, i)));
		}
	}
	
	sort(vv.begin(), vv.end());
	
	node *root = new node(0, NULL, NULL);
	build(root, 0, n - 1);
	
	segment[0] = root;
	
	
	for ( int i = 0; i < vv.size(); i++ ) {
		primes.push_back(vv[i].first);
		segment[i + 1] = new node(0, NULL, NULL);
		update(segment[i], segment[i + 1], 0, n - 1, vv[i].second.second, vv[i].second.first);
	}
	
	
	scanf("%d", &q);
	
	while ( q-- ) {
		scanf("%d%d%d%d", &l, &r, &x, &y);
		l--, r--;
		
		int idx1 = upper_bound(primes.begin(), primes.end(), y) - primes.begin();
		int idx2 = lower_bound(primes.begin(), primes.end(), x) - primes.begin();
		
		printf("%d\n", query(segment[idx1], 0, n - 1, l, r) - query(segment[idx2], 0, n - 1, l, r));
		
	}
	
	return 0;
} 