//#pragma GCC optimize ("-O3","unroll-loops")
#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<queue>
#include<map>
#include<math.h>
#include<iomanip>
#include<set>
#include<numeric>
#include<cstring>
#include<cstdio>
#include<functional>
#include<bitset>
#include<limits.h>
#include<cassert>
#include<iterator>
#include<complex>
#include<stack>
#include<unordered_map>
#include<unordered_set>
#include<time.h>
#include <random>

using namespace std;

#define REP(i, n) for(int i = 0;i < n;i++)
#define REPR(i, n) for(int i = n;i >= 0;i--)
#define FOR(i, m, n) for(int i = m;i < n;i++)
#define FORR(i, m, n) for(int i = m;i >= n;i--)
#define SORT(v, n) sort(v, v+n);
#define VSORT(v) sort(v.begin(), v.end());
#define REVERSE(v,n) reverse(v,v+n);
#define VREVERSE(v) reverse(v.begin(), v.end());
#define ll long long
#define pb(a) push_back(a)
#define print(x) cout<<x<<'\n';
#define pe(x) cout<<x<<" ";
#define lb(v,n) lower_bound(v.begin(), v.end(), n);
#define ub(v,n) upper_bound(v.begin(), v.end(), n);
#define int long long
#define all(x) (x).begin(), (x).end()
#define print_space(v) REP(i,v.size())cout << v[i] << ((i == v.size() - 1) ? "\n" : " ");
//#define double long double

template<typename T1, typename T2> inline void chmin(T1 & a, T2 b) { if (a > b) a = b; }
template<typename T1, typename T2> inline void chmax(T1& a, T2 b) { if (a < b) a = b; }
typedef pair<int, int>P;
const int MOD = 1e9 + 7;
const int MAX = 200060;
const double pi = acos(-1);

long long gcd(long long x, long long y) {
	long long m = max(x, y), n = min(x, y);
	if (m%n == 0)return n;
	else return gcd(m%n, n);
}
long long extGCD(long long a, long long b, long long &x, long long &y) {
	if (b == 0) {
		x = 1;
		y = 0;
		return a;
	}
	long long d = extGCD(b, a%b, y, x);
	y -= a / b * x;
	return d;
}

vector<int>G[100010];
int deg[100010];
int c[3][100010];
int cols[100010];
int dp[100010][3];
vector<int>v;
void init(int n, int pre) {
	v.push_back(n);
	for (auto nex : G[n]) {
		if (nex == pre)continue;
		init(nex, n);
	}
}
int pre[100010][3];
void solve() {
	int N; cin >> N;
	REP(i, 3) {
		REP(j, N) {
			cin >> c[i][j];
		}
	}
	int mx = 0;
	REP(i, N - 1) {
		int u, v; cin >> u >> v; u--, v--;
		deg[u]++, deg[v]++;
		G[u].pb(v);
		G[v].pb(u);
		mx = max({ mx, deg[u], deg[v] });
	}
	if (mx >= 3) {
		print(-1); return;
	}
	REP(i, N) {
		if (deg[i] == 1) {
			init(i,i); break;
		}
	}
	//print_space(v);
	//print("here");
	ll ans = 1e16;
	ll tmp = 0;
	REP(i, N) {
		tmp += c[i % 3][v[i]];
	}
	int color = 3;
	if (tmp < ans) {
		color = 0;
	}
	ans = min(ans, tmp);

	tmp = 0;
	REP(i, N ) {
		if (i % 3 == 0) {
			tmp += c[0][v[i]];
		}
		else if (i % 3 == 1)tmp += c[2][v[i]];
		else tmp += c[1][v[i]];
	}
	if (tmp < ans) {
		color = 1;
	}
	ans = min(ans, tmp);

	tmp = 0;
	REP(i, N) {
		if (i % 3 == 0)tmp += c[1][v[i]];
		else if (i % 3 == 1)tmp += c[0][v[i]];
		else tmp += c[2][v[i]];
	}
	if (tmp < ans) {
		color = 2;
	}
	ans = min(ans, tmp);

	tmp = 0;
	REP(i, N) {
		if (i % 3 == 0)tmp += c[1][v[i]];
		else if (i % 3 == 1)tmp += c[2][v[i]];
		else tmp += c[0][v[i]];
	}
	if (tmp < ans) {
		color = 3;
	}
	ans = min(ans, tmp);

	tmp = 0;
	REP(i, N) {
		if (i % 3 == 0)tmp += c[2][v[i]];
		else if (i % 3 == 1)tmp += c[0][v[i]];
		else tmp += c[1][v[i]];
	}
	if (tmp < ans) {
		color = 4;
	}
	ans = min(ans, tmp);

	tmp = 0;
	REP(i, N) {
		if (i % 3 == 0)tmp += c[2][v[i]];
		else if (i % 3 == 1)tmp += c[1][v[i]];
		else tmp += c[0][v[i]];
	}
	if (tmp < ans) {
		color = 5;
	}
	ans = min(ans, tmp);


	print(ans);

	if (color == 0) {
		REP(i, N) {
			if (i % 3 == 0)cols[v[i]] = 0;
			else if (i % 3 == 1)cols[v[i]] = 1;
			else cols[v[i]] = 2;
		}
	}
	else if (color == 1) {
		REP(i, N) {
			if (i % 3 == 0)cols[v[i]] = 0;
			else if (i % 3 == 1)cols[v[i]] = 2;
			else cols[v[i]] = 1;
		}
	}
	else if (color == 2) {
		REP(i, N) {
			if (i % 3 == 0)cols[v[i]] = 1;
			else if (i % 3 == 1)cols[v[i]] = 0;
			else cols[v[i]] = 2;
		}
	}
	else if (color == 3) {
		REP(i, N) {
			if (i % 3 == 0)cols[v[i]] = 1;
			else if (i % 3 == 1)cols[v[i]] = 2;
			else cols[v[i]] = 0;
		}
	}
	else if (color == 4) {
		REP(i, N) {
			if (i % 3 == 0)cols[v[i]] = 2;
			else if (i % 3 == 1)cols[v[i]] = 0;
			else cols[v[i]] = 1;
		}
	}
	else if (color == 5) {
		REP(i, N) {
			if (i % 3 == 0)cols[v[i]] = 2;
			else if (i % 3 == 1)cols[v[i]] = 1;
			else cols[v[i]] = 0;
		}
	}

	REP(i, N) {
		pe(cols[i]+1);
	}cout << endl;
}

signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	solve();
}