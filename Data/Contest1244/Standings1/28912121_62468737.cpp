# include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    string s;
    cin >> n >> s;
    int ans = n;
    for (int i = 0; i < n; i++) {
        if (s[i] == '1') {
            int ret = max (i + 1, n - i) * 2;
            ans = max(ans, ret);
        }
    }
    cout << ans << endl;
}

int t;

int main() {
    cin >> t;

    while (t --){
        solve();
    }
}
