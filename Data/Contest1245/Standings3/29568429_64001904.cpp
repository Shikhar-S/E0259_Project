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
const int N = 6e5 + 123;                                          
const int M = 22;
const int pri = 997;
const int Magic = 2101;

const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, -1, 0, 1};
 
int n, m, k;
string s;
int dp[N];



int main () {
   SpeedForce;
	cin >> s;
	n = sz(s);
	dp[0] = 1;
	s = '#' + s;
	for (int i = 1; i <= n; i ++) {
		dp[i] = dp[i - 1];
		if (i > 1 && s[i] == 'u' && s[i-1] == 'u') {
			dp[i] += dp[i - 2];
		}
		if (i > 1 && s[i] == 'n' && s[i-1] == 'n') {
			dp[i] += dp[i - 2];
		}
		if(s[i] == 'm' || s[i] == 'w') {
			cout << 0;
			exit(0);
		}

		//cout << i << ' ' << dp[i] << '\n';
		if (dp[i] >= mod) dp[i] -= mod;
	}
	cout << dp[n];
   return Accepted;

}

// B...a