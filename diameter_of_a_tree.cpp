#include <bits/stdc++.h>
using namespace std;

#define SIZE 100001
vector< vector<int> >arr(SIZE, vector<int>());
vector< int >depth(SIZE);
vector< int >diameter_path;

void dfs(int from, int to)
{
	depth[to]=depth[from]+1;
	for(auto x:arr[to])
	{
		if(x!=from)
			dfs(to,x);
	}
}

void add_path(int from, int to, int last, vector<int>& v)
{
	if(diameter_path.size() > 0) return;

	v.push_back(to);
	if(to == last)
	{
		diameter_path.resize(v.size());
		for(int i=0;i<v.size();i++) diameter_path[i]=v[i];
		return;
	}

	for(auto x:arr[to])
	{
		if(x!=from)
			add_path(to,x,last,v);
	}
	v.pop_back();
}

void get_diameter()
{
	int leaf1,leaf2;
	dfs(0,1);
	leaf1=max_element(depth.begin(),depth.end())-depth.begin();
	dfs(0,leaf1);
	leaf2=max_element(depth.begin(),depth.end())-depth.begin();

	vector<int>v;
	add_path(0, leaf1, leaf2, v);
}