#include <iostream>
#include <vector>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <cmath>
#include <string>
#include <queue>

using namespace std;

#define sz(a) static_cast<int>((a).size())
#define f first
#define s second
#define els(v) for (auto &el : (v))


#ifdef KIRYA
#define dbg(...) _dbg(#__VA_ARGS__, __VA_ARGS__)
#else
#define dbg(...)
#endif

template<typename T>
void _dbg(const char* _s, T _h) {
    cerr << _s << " = " << _h << "\n";
}

template<typename T, typename... Ts>
void _dbg(const char*_s, T _h, Ts... _t) {
    int _b = 0;
    
    while (((_b += *_s == '(') -= *_s == ')') != 0 || *_s != ',')
        cerr << *_s++;
    
    cerr << " = " << _h << ",";
    _dbg(_s + 1, _t...);
}

const int64_t INF = static_cast<int64_t>(1e9) + 7;
const int64_t LINF = INF * INF;
const int MAXN = static_cast<int>(1e6) + 17;

void solve() {
    int n;
    cin >> n;
    int64_t n_ev = 0, n_od = 0;
    for (int i = 0; i < n; ++i) {
        int val;
        cin >> val;
        n_ev += (val % 2 == 0);
        n_od += (val % 2 == 1);
    }
    int m;
    cin >> m;
    int64_t m_ev = 0, m_od = 0;
    for (int i = 0; i < m; ++i) {
        int val;
        cin >> val;
        m_ev += (val % 2 == 0);
        m_od += (val % 2 == 1);
    }
    cout << n_ev * m_ev + m_od * n_od << '\n';
}

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int q = 1;
    cin >> q;
    for (int i = 0; i < q; ++i) {
        solve();
    }
}
