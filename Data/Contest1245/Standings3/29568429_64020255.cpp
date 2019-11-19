#pragma GCC target("avx2")
#pragma GCC optimize("O3")

# include <x86intrin.h>
# include <bits/stdc++.h>

# include <ext/pb_ds/assoc_container.hpp>
# include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;
 
template<typename T> using ordered_set = tree <T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define _USE_MATH_DEFINES_
#define ll long long
#define ld long double
#define Accepted 0
#define pb push_back
#define mp make_pair
#define sz(x) (int)(x.size())
#define every(x) x.begin(),x.end()
#define F first
#define S second
#define lb lower_bound
#define ub upper_bound
#define For(i,x,y)  for (ll i = x; i <= y; i ++) 
#define FOr(i,x,y)  for (ll i = x; i >= y; i --)
#define SpeedForce ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
// ROAD to...                                                                                                                                                                                                                Red

inline void Input_Output () {
	//freopen(".in", "r", stdin);
   //freopen(".out", "w", stdout);
}

const double eps = 0.000001;
const ld pi = acos(-1);
const int maxn = 1e7 + 9;
const int mod = 1e9 + 7;
const ll MOD = 1e18 + 9;
const ll INF = 1e18 + 123;
const int inf = 2e9 + 11;
const int mxn = 1e6 + 9;
const int N = 2123;                                          
const int M = 22;
const int pri = 997;
const int Magic = 2101;

const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, -1, 0, 1};
int n;
ll c[N], k[N];
ll x[N], y[N];
int p[N], h[N];
int mn[N];
int best[N];
vector < pair < int, int > > e;
vector < pair < ll, pair < int, int > > > kek;
vector < int > u;
bool was[N];

inline ll f(int i, int j) {
	return (abs(x[i] - x[j]) + (ll)abs(y[i] - y[j])) * (ll)(k[i] + k[j]);
} 

inline int get (int x) {
	if (p[x] != x) p[x] = get(p[x]);
	return p[x];
}

inline bool uni (int a, int b) {
	a = get(a);
	b = get(b);
	if (a== b) return 0;
	if (h[a] > h[b]) swap(a, b);
	if(c[mn[a]] < c[mn[b]]) mn[b] = mn[a];
	p[a] = b;
	if (h[a] == h[b]) h[b]++;
	return 1;
	
}

bool cmp (int x, int y) {
	return c[x] < c[y];
}

 main () {
   SpeedForce;
	cin >> n;
	for (int i = 1; i <= n; i ++) {
		cin >> x[i] >> y[i];
		p[i] = i;
		h[i] = 1;
	}
	for (int i = 1; i <= n; i ++) cin >> c[i], mn[i] = i;
	for (int i = 1; i <= n; i ++) {
		cin >> k[i];
	}
	ll ans = 0;
	for (int i = 1; i <= n; i ++) {
		int j = mn[i];
		for (int a = i + 1; a <= n; a ++) {
			int b = mn[a];
			kek.pb({f(j, b), {j, b}});
		}
	}
	sort(every(kek));
	for (auto it : kek) {
		int i = it.S.F, j = it.S.S;
		ll co = it.F;
		if (get(i) != get(j) && max(c[mn[get(i)]], c[mn[get(j)]]) >= co) { 
			//cout << i << ' ' << j << ' ' << co << 'n';
			uni(i, j);
			ans += co;
			e.pb({i, j});
		}
	}
	for (int i = 1; i <= n; i ++) {
		int j = get(i);
		if (was[j]) continue;
		ans += c[mn[j]];
		u.pb(mn[j]);
		was[mn[j]] = 1;
		was[j] = 1;
	}

	cout << ans << '\n';
	cout << sz(u) << '\n';
	for (auto it : u) cout << it << ' ';
	cout << '\n' << sz(e) << '\n';
	for (auto x : e) 
		cout << x.F << ' ' << x.S << '\n';

   return Accepted;
}

// B...a