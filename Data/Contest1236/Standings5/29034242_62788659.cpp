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
int k, x, y, sum, cnt, ans;
ll n, m;
ll bigmod(ll b, ll p) {
  if (p == 0) return 1 % mod;
  if (p == 1) return b % mod;
  ll t = bigmod(b, p/2);
  if (p%2==0) return t * t % mod;
  t = (t * t) % mod;
  return t * b % mod;
}
int main () {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m;
  ll a = bigmod(2, m);
  a--;
  if (a < 0) a+=mod;
  cout << bigmod(a, n) << endl;
  return 0;
}