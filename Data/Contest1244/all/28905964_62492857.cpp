#include <bits/stdc++.h>
using namespace std;
#define SZ(v) int((v).size())
#define ALL(vec) begin(vec), end(vec)
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
template<typename T, typename V = __gnu_pbds::null_type>
using ordered_set = __gnu_pbds::tree<T, V, less<T>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;
// find_by_order(), order_of_key()

typedef long long i64;
template<typename T> inline bool uax(T &x, T y) {return (y > x) ? x = y, true : false;}
template<typename T> inline bool uin(T &x, T y) {return (y < x) ? x = y, true : false;}
#define error(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); \
  stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }
string to_string(char c) { return "'" + string(1, c) + "'";}
string to_string(string s) { return '"' + s + '"';}
string to_string(const char* s) { return to_string((string) s);}
template<typename A> string to_string(A);
template<typename A, typename B> string to_string(pair<A, B> p){
  return "(" + to_string(p.first) + ": " + to_string(p.second) + ")";}
template<typename A> string to_string(A v) {bool f = false; string r = "{"; 
  for (auto x: v) {if (f) r += ", "; r += to_string(x); f = true;} return r += "}";}
template<typename A> string to_string(vector<vector<A>> v) {string r; 
  for (auto x: v) r += "\n" + to_string(x); return r;}
void err(istream_iterator<string>) { cerr << endl; }
template<typename T,typename... Args> void err(istream_iterator<string> it, T a, Args... args) {
  cerr << *it << " =: " << to_string(a) << "\n"; err(++it, args...); }
template<typename T> void kek(T ans) {cout << ans << endl; exit(0);}
int const MOD = 1e9 + 7;
long long const INF = 1e18 + 42;
/*************************************/

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  
  int n; cin >> n;
  i64 k; cin >> k;
  vector<i64> a(n);
  for (auto &z : a) cin >> z;
  sort(ALL(a));
  vector<i64> b(n - 1);
  for (int i = 0; i < n - 1; ++i) {
    b[i] = a[i + 1] - a[i];
  } 
  i64 ans = a.back() - a[0];
  int l = 0, r = n - 2, p = 1;
  while (l < r) {
    vector<i64> c = {b[l], b[r]};
    sort(ALL(c));
    for (i64 x : c) {
      i64 take = min(k, x * p);
      ans -= take / p;
      k -= take;
    }
    ++p, ++l, --r;
  }
  if (l == r) {
    i64 take = min(k, b[l] * p);
    ans -= take / p;
    k -= take;
  }
  assert (ans >= 0);
  kek(ans);
  
  return 0;
}
