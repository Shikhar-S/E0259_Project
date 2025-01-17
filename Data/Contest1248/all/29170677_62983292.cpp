#include <bits/stdc++.h>

using namespace std;

#define LL long long int
#define FASTIO ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

const int oo = 1e8;
// const LL oo = 1e16 + 5;
const int MOD = 1e9 + 7;
const int N = 1e6+5;
// const int MOD = 998244353;
// const long double PI = acos(-1);

LL v[N];
void solve() {
    int n, i, m;
    cin >> n;
    LL s = 0;
    for (i=0;i<n;i++) {
        cin >> v[i];
        s += v[i];
    }
    sort(v, v+n);
    LL x = 0, ans = 0;
    for (i=0;i<n/2;i++) {
        x += v[i];
    }
    ans = max(ans, x * x + (s - x) * (s - x));
    cout << ans << '\n';
}

int main() {
    FASTIO; int t = 1; 
    // cin >> t;
    for (int tc = 1; tc <= t; ++tc) {
        solve();
    }
    return 0;
}