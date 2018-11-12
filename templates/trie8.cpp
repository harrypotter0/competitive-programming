/*
5 4
100
101
1
1011
11
2 3 10
1 5 1100
3 5 1010
1 5 11100

*/

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
using namespace std;

// #pragma comment(linker, "/stack:200000000")
#pragma GCC optimize ("O3")
// #pragma GCC optimize ("O2")
// #pragma GCC optimize("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#define int long long 
#define pb emplace_back
#define mp make_pair
#define endl "\n"
#define sz(x) (int)x.size()
#define aint(v) v.begin(), v.end()
#define x first
#define y second
#define REP(i,s,t) for(int i=(s);i<(t);i++)
#define FILL(x,v) memset(x,v,sizeof(x))
#define ios ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define watch(x) cout << (#x) << " is " << (x) << endl
const int mod = 1e9+7;
const int N = 3e6+5;

typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef set<int> si;
typedef map<int,int> mii;

int fast_pow(int a, int b){
	int res = a, ret = 1;
	while(b>0){
		if(b%2)
			ret = (ret*res)%mod;
		res = (res*res)%mod;b/=2;
	}
	return ret;
}

int repeat_count = 0;

struct Interval {
    int start, end;
    Interval(int s) : start(s), end(s) {}
    Interval(int p, int s) : start(p), end(s) {}

    bool increment_for(int k) { // leaf node insertion
        if (end + 1 == k) {
            end = k;
            return true;
        } else
            return false;
    }

    bool overlaps_with(const Interval &other) const {
        if (this->start <= other.start && this->end >= other.start) return true;
        if (this->start <= other.end && this->end >= other.end) return true;
        return false;
    }

    bool binary_search(vector<Interval> &e) {
        int start = 0;
        int end = e.size() - 1;
        int middle = (start + end) / 2;
        while (start <= end) {
            if (this->overlaps_with(e[middle]) || e[middle].overlaps_with(*this))
                return true;
            if (this->end < e[middle].start) {
                end = middle - 1;
                middle = (start + end) / 2;
            } else {
                start = middle + 1;
                middle = (start + end) / 2;
            }
        }
        return false;
    }
};

struct trie_node {
    trie_node *left, *right;
    bool val;
    Interval *active;
    vector<Interval> R;
    int repeat;
    vector<Interval *> pool;

    trie_node(bool i, int index) : val(i), active(new Interval(index)) {
        left = nullptr;
        right = nullptr;
        repeat = 0;
    }

    void append(int init) {
        if (!active->increment_for(init)) {
            R.push_back(*active);
            pool.push_back(active);
            active = new Interval(init);
        }
    }

    ~trie_node() {
        delete active;
        for (auto &e : pool) delete e;
    }
} *root = nullptr;

// insert(root, e, i++, max_len, max_len2);
void insert(trie_node *pos, string ss, int idx, size_t max_len,
            size_t max2) {
    if (pos == nullptr)
        root = pos = new trie_node(true, idx);
    else {
        trie_node *parent = pos;
        if (max_len - max2 < 40000) {
            int less_by = static_cast<int>(max_len - ss.size());
            for (int p = 0; p < less_by; p++) {
                if (parent->left == nullptr)
                    parent->left = new trie_node(false, idx);
                else
                    parent->left->append(idx);
                parent = parent->left;
            }
        } else {
            // throw std::runtime_error("stub");
            if (ss.size() != max_len) {
                if (parent->left == nullptr) {
                    parent->left = new trie_node(false, idx);
                    parent->left->repeat = max_len - max2 - 1;
                    repeat_count = max_len - max2 - 1;
                } else {
                    parent->left->append(idx);
                    parent->left->repeat = max_len - max2 - 1;
                }
                parent = parent->left;
                int less_by = static_cast<int>(max2 - ss.size());
                for (int p = 0; p < less_by; p++) {
                    if (parent->left == nullptr)
                        parent->left = new trie_node(false, idx);
                    else
                        parent->left->append(idx);
                    parent = parent->left;
                }
            }
    // END_HERE
        }

        for (char a : ss) {
            if (a == '0') {
                if (parent->left == nullptr)
                parent->left = new trie_node(false, idx);
                else
                parent->left->append(idx);
                parent = parent->left;

            } else {
                if (parent->right == nullptr)
                parent->right = new trie_node(true, idx);
                else
                parent->right->append(idx);
                parent = parent->right;
            }
            }
    }
}

int query(trie_node *from, string &sk, Interval p, int max_len) {
    if (p.start == p.end) return p.end;
    trie_node *iter = from;
    int extra_len = sk.size() > max_len ? sk.size() - max_len : 0;
    int ops = static_cast<int>(max_len - sk.size());
    for (int pp = 0; pp < ops; pp++) {
        if (iter->repeat != 0) {
            if (ops - pp <= iter->repeat) {
                pp = ops - 1;
                iter->repeat -= pp;
                continue;
            } else {
                pp += iter->repeat - 1;
                iter->repeat = 0;
                continue;
            }
        }
        if (iter->right != nullptr) {
        bool can_move_right = p.overlaps_with(*(iter->right->active)) ||
                                iter->right->active->overlaps_with(p);
        if (!can_move_right) can_move_right = p.binary_search(iter->right->R);
        if (can_move_right) {
            if (iter->repeat == 0)
                iter = iter->right;
            else
                iter->repeat--;
        } else {
            if (iter->repeat == 0)
                iter = iter->left;
            else
                iter->repeat--;
        }
        } else {
            if (iter->repeat == 0)
                iter = iter->left;
            else
                iter->repeat--;
        }
    }
    for (int hik = extra_len; hik < sk.size(); hik++) {
        if (iter->repeat != 0) {
        if (sk.size() - hik <= iter->repeat) {
            hik = sk.size() - 1;
            iter->repeat -= hik;
            continue;
        } else {
            hik += iter->repeat - 1;
            iter->repeat = 0;
            continue;
        }
        }
        char a = sk[hik];
        if (a == '0') {
        if (iter->right != nullptr) {
            bool can_move_right = p.overlaps_with(*(iter->right->active)) ||
                                iter->right->active->overlaps_with(p);
            if (!can_move_right) can_move_right = p.binary_search(iter->right->R);
            if (can_move_right) {
            if (iter->repeat == 0)
                iter = iter->right;
            else
                iter->repeat--;
            } else {
            if (iter->repeat == 0)
                iter = iter->left;
            else
                iter->repeat--;
            }
        } else {
            if (iter->repeat == 0)
            iter = iter->left;
            else
            iter->repeat--;
        }
        } else {
        if (iter->left != nullptr) {
            bool can_move_left = false;
            can_move_left = p.overlaps_with(*(iter->left->active)) ||
                            iter->left->active->overlaps_with(p);
            if (!can_move_left) can_move_left = p.binary_search(iter->left->R);
            if (can_move_left) {
            if (iter->repeat == 0)
                iter = iter->left;
            else
                iter->repeat--;
            } else {
            if (iter->repeat == 0)
                iter = iter->right;
            else
                iter->repeat--;
            }
        } else {
            if (iter->repeat == 0)
            iter = iter->right;
            else
            iter->repeat--;
        }
        }
    }
    for (auto &e : iter->R)
        if (e.end >= p.start)
        for (int x = e.start; x <= e.end; x++)
            if (p.overlaps_with(Interval(x))) return x;
    for (int t = iter->active->start; t <= iter->active->end; t++)
        if (p.overlaps_with(Interval(t))) return t;
    return -1;
}



void solve() {
    int n, q;
    cin >> n >> q;
    string ss;
    insert(root, "1", 0, 0, 0);
    int max_len = 0, max_len2 = 0;
    vector<string> psk;
    for (int p = 0; p < n; p++)
    {
        cin >> ss;
        psk.push_back(ss);
        if (max_len <= ss.size())
        {
            max_len2 = max_len;  // second max length of input string
            max_len = ss.size(); // maximum length of the input string 
            continue;
        }
        if (max_len2 < ss.size()) max_len2 = ss.size(); // second max length of input string
    }
    //cout<<"Max : "<<max_len<<": "<<max_len2;

    int i = 1;
    for (auto &e : psk) insert(root, e, i++, max_len, max_len2);
    int a, b;
    std::string st;

    for (int s = 0; s < q; s++) {
        cin >> a >> b;
        cin >> st;
        cout << query(root, st, Interval(a, b), max_len) << "\n";
        if (repeat_count != 0) root->left->repeat = repeat_count;
    }
}

signed main()
{
    ios
    int i, t=1, j, x;
    // cin>>t;
    time_t time_t1, time_t2;
    time_t1 = clock();

    while(t--)
        solve();

    time_t2 = clock();
    // cout << "time taken :" << time_t2 - time_t1 << endl;
    return 0;
}
