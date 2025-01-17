#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define F first
#define S second
#define ld long double
#define ll long long
#define TIME 1.0*clock()/CLOCKS_PER_SEC

mt19937 gen(chrono::system_clock::now().time_since_epoch().count());

const int N = 3e5 + 10;
const ll MOD = 1e9 + 7;
const int rx[4] = {-1, 0, 1, 0};
const int ry[4] = {0, 1, 0, -1};
const int dx[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
const int dy[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
const int hx[8] = {-2, -2, -1, 1, 2, 2, 1, -1};
const int hy[8] = {-1, 1, 2, 2, 1, -1, -2, -2};
const ld eps = 1e-7;
const double pi = acos(-1.0);
const int INF = 2e9;

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#else
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin >> T;
    while (T --) {
        int n;
        cin >> n;
        int kn = 0, kch = 0;
        for (int i = 0; i < n; i++) {
            int p;
            cin >> p;
            if (p % 2 == 0) kch ++;
            else kn ++;
        }
        int m;
        cin >> m;
        ll ans = 0;
        for (int i = 0; i < m; i++) {
            int q;
            cin >> q;
            if (q % 2 == 0) ans += kch;
            else ans += kn;
        }
        cout << ans << endl;
    }
    return 0;
}
