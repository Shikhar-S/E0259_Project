#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
void solve () {
  int a, b, c, d, k;
  cin >> a >> b >> c >> d >> k;
  int x = (a + c - 1) / c;
  int y = (b + d - 1) / d;
  if (x + y <= k) {
    cout << x << " " << y << '\n';
  } else {
    cout << - 1 << '\n';
  }
}
signed main() { 
  ios::sync_with_stdio(false); cin.tie(0);
  //a
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}