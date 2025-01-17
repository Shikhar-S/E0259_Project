#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<int, int>;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using vll = vector<ll>;
using vvll = vector<vector<ll>>;
const double eps = 1e-10;
const int MOD = 1000000007;
const int INF = 1000000000;
const ll LINF = 1ll<<50;
template<typename T>
void printv(const vector<T>& s) {
  for(int i=0;i<(int)(s.size());++i) {
    cout << s[i];
    if(i == (int)(s.size())-1) cout << endl;
    else cout << " ";
  }
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout << fixed << setprecision(10);
  int t; cin >> t;
  while(t > 0) {
    t--;
    int n; cin >> n;
    vector<int> v(n);
    for(int i=0;i<n;++i) {
      cin >> v[i];
    }
    sort(v.begin(), v.end());
    int ans = n;
    for(int i=1;i<=n;++i) {
      if(v[n-i] < i) {
        ans = i-1;
        break;
      }
    }
    cout << ans << endl;
  }
}
