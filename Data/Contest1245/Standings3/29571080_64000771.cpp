#include <bits/stdc++.h>

#define need_long 0

#define all(v) v.begin(), v.end()
#define vc vector
#define len(v) ((int) v.size())
#define pr pair
#define ld long double
#define mset multiset

using namespace std;

#if need_long == 1
#define int long long
#else
#endif
const int INF = (need_long) ? 1e18 : 2e9;
mt19937 gen(time(0));

template <class T> int upmax(T &a, T b) {
    return (b > a) ? a = b, 1 : 0;
}

template <class T> int upmin(T &a, T b) {
    return (b < a) ? a = b, 1 : 0;
}

template <class T> void output(vc<T>&a, ostream &out = cerr, string r = " ") {
    for (int i = 0; i < len(a); ++i) {
        cout << a[i] << r;
    }
    out << "\n";
}

const int MAXN = 3e5 + 40;
const int LOG = 30;

void solve() {
    int a, b;
    cin >> a >> b;
    if (gcd(a, b) == 1) {
        cout << "Finite\n";
    }
    else {
        cout << "Infinite\n";
    }
}

signed main() {
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}