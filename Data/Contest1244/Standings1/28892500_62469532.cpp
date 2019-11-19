#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  int ans = n;
  for (int i = 0; i < n; ++i) {
    if (s[i] == '1') {
      ans = max(ans, max(i + 1, n - i) * 2);
    }
  }
  cout << ans;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  int t;
  cin >> t;
  while (t--) {
    solve();
    cout << '\n';
  }

  return 0;
}