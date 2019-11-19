#include <bits/stdc++.h>

using namespace std;
using ull = unsigned long long;
using ll = long long;
using ld = long double;
using D = double;
using ii = pair<int, int>;
using vi = vector<int>;
using vii = vector<ii>;
using vs = vector<string>;
using vvi = vector<vi>;
using vll = vector<ll>;

#define pb push_back
#define mp make_pair
#define all(x) x.begin(),x.end()
#define makeunique(x) sort(all(x)), (x).resize(unique(all(x)) - (x).begin())
#define rep(i, x)  for(int i = 0; i < (x); i++)
#define rrep(i, x) for(int i = (x - 1); i >= 0; i--)
#define sqrt(x) sqrt(abs(x))
#define y1 y1_1234413
#define j1 j1_235
#define y0 y0_235
#define j0 j0_256
#define fi first
#define se second
#define re return
#define prev PREV
#define next NEXT
#define sz(x) ((int)x.size())
#define vl v*2
#define vr v*2+1

template<typename T> T sqr(T a) { re a * a; }
template<typename T> T gcd(T a, T b) { re b ? gcd(b, a % b) : a; }
template<typename T> T sgn(T a) { re a > 0 ? 1 : (a < 0 ? -1 : 0); }
template<typename T> T abs(T a) { re a > 0 ? a : -a; }

const int inf = 2e9;
const ld st = 0.000001;
const ld pi = acos((ld)-1);

#define FILENAME ""

int n;
int m;

int main()
{
	ios::sync_with_stdio(0);
    cin.tie(NULL);
//	freopen(FILENAME ".in", "r", stdin);
//	freopen(FILENAME ".out", "w", stdout);
	cin >> n;
	vi v(n);
	ll a = 0, b = 0;
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	sort (all(v));

	for (int i = 0; i < n / 2 + (n % 2); i++) {
		b += v[n - i - 1];
		if (n - i - 1 != i) a += v[i];

		
	}

	cout << sqr(a) + sqr(b);

	re 0;
}     





