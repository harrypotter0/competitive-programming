#include "bits/stdc++.h"
using namespace std;

int t;
deque<pair<long long int, int> > q;

int main() {
  cin >> t;
  while (t--) {
    q.clear();
    long long int n,d;
    scanf("%lld%lld", &n, &d);
    long long int sum = 0;
    q.push_back(make_pair(sum, -1));
    int ans = INT_MAX;
    for (int i = 0; i < n; i++) {
      long long int a;
      scanf("%lld", &a);
      sum += a;
      while (q.size()&&sum - q.front().first >= d) {
        ans = min(ans, i - q.front().second);
        q.pop_front();
      }
      while (q.size() && q.back().first > sum) {
        q.pop_back();
      }
      q.push_back(make_pair(sum, i));
    }
    if (ans == INT_MAX) {
      ans = -1;
    }
    printf("%d\n", ans);
  }
  return 0;
} 
