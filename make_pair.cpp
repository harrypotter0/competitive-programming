#include <bits/stdc++.h>
 
using namespace std;
 
int main()
{
	int tests;
	cin>>tests;
	while(tests--) {
		vector<pair<int,int>> books;
		vector<int> smallest;
		int prev=-1;
		long long curr=0;
		long long rem=0;
		long long total=0;
		int num;
		cin>>num;
		for(int i=0;i<num;i++) {
			int auth,happ;
			cin>>auth>>happ;
			books.push_back(make_pair(auth,happ));
		}
		sort(books.begin(),books.end()); //Groups books by same author together. Within the same groups, books are sorted from smallest happiness to largest happiness.
		for(const auto& book : books) {
			if(book.first==prev) {
				rem+=book.second;
			} else {
				smallest.push_back(book.second);
				prev=book.first;
			}
		}
		//pick smallest book from each author
		sort(smallest.begin(),smallest.end()); //sort these books from smallest to largest.
		for(const auto& small:smallest) {
			total+=(++curr)*small;
		}
		total+=rem*curr;
		cout<<total<<'\n';
	}
	return 0;
} 