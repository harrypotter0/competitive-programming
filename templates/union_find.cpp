typedef long long ll;
typedef vector<int> VI;
typedef pair<int,int> PII;

#define REP(i,s,t) for(int i=(s);i<(t);i++)
#define FILL(x,v) memset(x,v,sizeof(x))

const int INF = (int)1E9;
#define MAXN 1005

int rep[MAXN];
int find(int x) {
  return rep[x] == x ? x : rep[x] = find(rep[x]);
}
void unionset(int x, int y) {
  int rx = find(x), ry = find(y);
  if (rx == ry) return;
  rep[rx] = ry;
}
class Solution {
public:
  int removeStones(vector<vector<int>>& st) {
    int n = st.size();
    REP(i,0,n) rep[i] = i;
    REP(i,0,n) {
      REP(j,i+1,n) {
        if (st[i][0] == st[j][0] || st[i][1] == st[j][1]) unionset(i, j);
      }
    }
    int ans = 0;
    REP(i,0,n) if (find(i) == i) ans++;
    return n - ans;
  }
};