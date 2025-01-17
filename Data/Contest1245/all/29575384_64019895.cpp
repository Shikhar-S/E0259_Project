/*
    Author: Nguyen Tan Bao
    Status:
    Idea:
*/
 
#include <bits/stdc++.h>
#define FI first
#define SE second
#define EPS 1e-9
#define ALL(a) a.begin(),a.end()
#define SZ(a) int((a).size())
#define MS(s, n) memset(s, n, sizeof(s))
#define FOR(i,a,b) for (int i = (a); i <= (b); i++)
#define FORE(i,a,b) for (int i = (a); i >= (b); i--)
#define FORALL(it, a) for (__typeof((a).begin()) it = (a).begin(); it != (a).end(); it++)
//__builtin_ffs(x) return 1 + index of least significant 1-bit of x
//__builtin_clz(x) return number of leading zeros of x
//__builtin_ctz(x) return number of trailing zeros of x
 
using namespace std;
using ll = long long;
using ld = double;
typedef pair<int, int> II;
typedef pair<int, II> III;
typedef complex<ld> cd;
typedef vector<cd> vcd;
 
const ll MODBASE = 1000000007LL;
const int MAXN = 2010;
const int MAXM = 10010;
const int MAXK = 110;
const int MAXQ = 200010;

struct Edge {
    int u, v;
    ll c;
    Edge(int u = 0, int v = 0, ll c = 0) : u(u), v(v), c(c) {}
};

bool operator< (Edge a, Edge b) {
    return a.c < b.c;
}

int n, lab[MAXN];
ll cost[MAXN][MAXN], c[MAXN], k[MAXN];
II a[MAXN];
vector<Edge> e;
vector<int> resA;
vector<II> resB;

ll getCost(int i, int j) {
    return (ll) (abs(a[i].FI - a[j].FI) + abs(a[i].SE - a[j].SE)) * (k[i] + k[j]);
}

int getRoot(int u) {
    while (lab[u] > 0) u = lab[u];
    return u;
}

void unionFind(int u, int v) {
    int x = lab[u] + lab[v];
    if (lab[u] < lab[v]) {
        lab[v] = u;
        lab[u] = x;
    }
    else {
        lab[u] = v;
        lab[v] = x;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    cin >> n;
    FOR(i,1,n) cin >> a[i].FI >> a[i].SE;
    FOR(i,1,n) cin >> c[i];
    FOR(i,1,n) cin >> k[i];

    FOR(i,1,n) {
        cost[0][i] = c[i];
        e.emplace_back(Edge(0, i, cost[0][i]));
    }

    FOR(i,1,n)
        FOR(j,i+1,n) {
            cost[i][j] = getCost(i, j);
            e.emplace_back(Edge(i, j, cost[i][j]));
        }
    
    sort(ALL(e));

    FOR(i,0,n) lab[i] = -1;

    ll sum = 0;
    FOR(i,0,SZ(e)-1) {
        int u = getRoot(e[i].u);
        int v = getRoot(e[i].v);

        if (u != v) {
            unionFind(u, v);
            sum += e[i].c;
            if (e[i].u == 0) resA.emplace_back(e[i].v);
            else resB.emplace_back(II(e[i].u, e[i].v));
        }
    }

    cout << sum << "\n";
    cout << SZ(resA) << "\n";
    FOR(i,0,SZ(resA)-1) cout << resA[i] << ' '; cout << endl;
    cout << SZ(resB) << "\n";
    FOR(i,0,SZ(resB)-1) cout << resB[i].FI << ' ' << resB[i].SE << "\n";
    return 0;
}
