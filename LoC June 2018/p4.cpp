#include <bits/stdc++.h>
 
using namespace std;
 
constexpr int N = 1e6 + 10;
 
int n, ans, val;
stack <int> st;
 
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> val;
        while (!st.empty() && st.top() > val)
            st.pop();
        if (!st.size() || st.top() < val) {
            ans++;
            st.push(val);
        }
    }
    cout << ans << '\n';
    return 0;
}
