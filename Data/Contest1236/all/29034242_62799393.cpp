#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define mod 1000000007
#define h1 7897897897897897
#define h2 7897466719774591
#define b1 98762051
#define b2 98765431
#define inf 1000000000
#define pi 3.1415926535897932384626
#define LMAX 9223372036854775807
#define ll long long
#define fi first
#define se second
#define pii pair<int, int>
#define pll pair<ll, ll>
#define vi vector<int>
#define vl vector<ll>
#define vp vector<pii>
#define SET(a, b) memset(a, b, sizeof(a));
#define all(x) (x).begin(), (x).end()
#define flush fflush(stdout)
#define debug printf("Hello\n")
#define FOR(i, a, b) for (int i = (a); i <= (b); i++)
#define FORD(i, a, b) for (int i = (a); i >= (b); i--)
int n, m, k, x, y, sum, cnt, ans, a[305][305];
int main () {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  FOR(i, 1, n) {
    FOR(j, 1, n/2) {
      a[i][j] = ++cnt;
    }
  }
  if (n%2==1) {
    FOR(i, 1, n) a[i][n/2+1] = ++cnt;
  }
  cnt = n * n;
  FOR(i, 1, n) {
    FORD(j, n, n - n/2 + 1) {
      a[i][j] = cnt--;
    }
  }
  FOR(i, 1, n) {
    FOR(j, 1, n) {
      cout << a[i][j];
      if (j == n) cout << endl;
      else cout << ' ';
    }
  }
  return 0;
}