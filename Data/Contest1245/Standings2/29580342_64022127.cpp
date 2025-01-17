#include <bits/stdc++.h>

using namespace std;

#define LL long long int
#define FASTIO ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

const int oo = 1e9;
// const LL oo = 1e18;
const int MOD = 1e9 + 7;
// const int MOD = 998244353;
const int N = 2005;
// const long double PI = acos(-1);


struct Edge {
    int u, v;
    LL wt;
    Edge(int u, int v, LL wt) : u(u), v(v), wt(wt) {}
};

int x[N], y[N], c[N], k[N];

LL dist(int i, int j) {
    LL d = abs(x[i] - x[j]) + abs(y[i] - y[j]);
    return d * (k[i] + k[j]);
}

int p[N], sub[N];

int root(int u) {
    while(p[u] != u) {
        p[u] = p[p[u]];
        u = p[u];
    }
    return u;
}

bool merge(int uu, int vv) {
    int u = root(uu), v = root(vv);
    if (u == v) return false;
    if (sub[u] < sub[v]) swap(u, v);
    p[v] = u;
    sub[u] += sub[v];
    return true;
}

void solve() {
    int n, i, j;
    cin >> n;
    for (i=1;i<=n;i++) {
        cin >> x[i] >> y[i];
        p[i] = i;
        sub[i] = 0;
    }
    p[n+1] = n+1; sub[n+1] = 0;
    for (i=1;i<=n;i++) cin >> c[i];
    for (i=1;i<=n;i++) cin >> k[i];

    vector<Edge> v;
    for (i=1;i<=n;i++) for (j=i+1;j<=n+1;j++) {
        LL wt;
        if (j == n + 1) wt = c[i];
        else wt = dist(i, j);
        v.push_back(Edge(i, j, wt));
    }
    sort(v.begin(), v.end(), [](Edge a, Edge b) {
        return a.wt < b.wt;
    });
    LL ans = 0;
    vector<int> stations;
    vector<Edge> connection;
    for (auto it : v) {
        if (merge(it.u, it.v)) {
            ans += it.wt;
            if (it.v == n+1) stations.push_back(it.u);
            else connection.push_back(it);
        }
    }
    cout << ans << '\n';
    cout << (int)stations.size() << '\n';
    for (auto it : stations) cout << it << " ";
    cout << '\n';
    cout << (int)connection.size() << '\n';
    for (auto it : connection) cout << it.u << " " << it.v << '\n';
}

int main() {
    FASTIO; 
    int t = 1; 
    // cin >> t;
    for (int tc = 1; tc <= t; ++tc) {
        solve();
    }
    return 0;
}