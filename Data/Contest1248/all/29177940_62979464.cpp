#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

#define FOR(i, N) for (int i = 0; i < (int)N; i++)
#define FORIN(i, a, b) for (int i = a; i < (int)b; i++)
#define ALL(x) (x).begin(), (x).end()
#define MOD 1000000007
#define INF (1 << 29)
#define LLINF (1LL << 60)
#define DEBUG(...) debug(__LINE__, ":" __VA_ARGS__)

using Pi = pair<int, int>;
using ll = long long;

string to_string(string s) { return s; }

template <class S, class T>
string to_string(pair<S, T> p) {
  return "{" + to_string(p.first) + "," + to_string(p.second) + "}";
}

template <class S>
string to_string(unordered_set<S> s) {
  string ret = "{";
  for (S x : s) ret += to_string(x) + ",";
  return ret + "}";
}

template <class S, class T>
string to_string(map<S, T> m) {
  string ret = "{";
  for (pair<S, T> x : m) ret += to_string(x) + ",";
  return ret + "}";
}

template <class T>
string to_string(vector<T> v) {
  string ret = "{";
  for (int i = 0; i < (int)v.size() - 1; ++i) {
    ret += to_string(v[i]) + ",";
  }
  if (v.size() > 0) {
    ret += to_string(v.back());
  }
  ret += "}";
  return ret;
}

void debug() { cerr << endl; }

template <class Head, class... Tail>
void debug(Head head, Tail... tail) {
  cerr << to_string(head) << " ";
  debug(tail...);
}

void print() { cout << endl; }

template <class Head, class... Tail>
void print(Head head, Tail... tail) {
  cout << to_string(head);
  print(tail...);
}

int main() {
  cin.tie(0);
  int n;
  cin >> n;
  vector<ll> a(n);
  FOR(i, n) cin >> a[i];
  sort(ALL(a));
  ll ans = 0, x = 0, y = 0;
  FOR(i, n / 2) { x += a[i]; }
  FORIN(i, n / 2, n) { y += a[i]; }
  cout << x * x + y * y << endl;
  return 0;
}