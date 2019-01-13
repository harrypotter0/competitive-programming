#include <bits/stdc++.h>
using namespace std;
#define ii pair<int, int>
#define ff first 
#define ss second 
int guardHeights[100005];
int queryHeights[100005];
int invalid[100005];
int ans[100005];
struct node{
	bool query;
	int timer;
	bool start;
	int id;
	node(bool query, int timer, bool start, int id) : query(query), timer(timer), start(start), id(id) { }
};
bool cmp(node a, node b){
	if(a.timer != b.timer)
		return a.timer < b.timer;
	else
		return a.query < b.query;
}
int main(){
	int i,j,h,c,q,s,e,max_h;
	scanf("%d %d %d", &h, &c, &q);
	vector<node> timeSortedQueries;
	priority_queue<ii> pq;
	ii tp;
	for(i = 0; i < c; i++){
		scanf("%d %d %d", &guardHeights[i], &s, &e);
		timeSortedQueries.push_back(node(0, s, 1, i));
		timeSortedQueries.push_back(node(0, e + 1, 0, i));
	}
	for(i = 0; i < q; i++){
		scanf("%d %d", &queryHeights[i], &s);
		timeSortedQueries.push_back(node(1, s, 0, i));
	}
	sort(timeSortedQueries.begin(), timeSortedQueries.end(), cmp);
	for(auto el : timeSortedQueries){
		if(!el.query){
			if(el.start)
				pq.push({guardHeights[el.id], el.id});
			else
				invalid[el.id] = 1;
		}
		else{
			max_h = 0;
			while(!pq.empty()){
				tp = pq.top();
				if(!invalid[tp.ss]){
					max_h = tp.ff;
					break;
				}
				else
					pq.pop();
			}
			ans[el.id] = (queryHeights[el.id] > max_h);
		}
	}
	for(i = 0; i < q; i++)
		printf("%s\n", ans[i] ? "YES" : "NO");
    return 0;
}