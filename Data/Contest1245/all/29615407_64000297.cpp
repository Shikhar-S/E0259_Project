#include <bits/stdc++.h>
using namespace std;

string to_string(bool x) {
    return x ? "true" : "false";
}

string to_string(char x) {
    return string(1, x);
}

string to_string(string s) {
    return '"' + s + '"';
}

string to_string(const char *s) {
    return to_string((string) s);
}

template<typename A, typename B>
string to_string(pair<A, B> p) {
    return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}

template<typename A>
string to_string(A v) {
    bool first = true;
    string res = "{";
    for (const auto &x : v) {
        if (!first) {
            res += ", ";
        }
        first = false;
        res += to_string(x);
    }
    res += "}";
    return res;
}

void debug_out() {
    cerr << endl;
}

template<typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
    cerr << " " << to_string(H);
    debug_out(T...);
}

#ifdef LOCAL
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...) 42
#endif

#define all(x) (x).begin(), (x).end()
#define sz(a) (int)(a).size()
#define pb push_back
#define fi first
#define se second
#define two(a) (1LL << (a))
#define has(mask, i) ((mask >> i) & 1)

using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector < int >;
using vll = vector < ll >;
using vvi = vector < vector < int > >;
using vpii = vector < pii >;
using ld = long double;
using vs = vector < string >;

mt19937_64 rnd((unsigned long) chrono::high_resolution_clock::now().time_since_epoch().count());

const ll MOD = (ll)(1e9) + 7;

void solve() {
    string s; cin >> s;

    for(auto x : s) {
        if(x == 'w' || x == 'm') {
            cout << 0 << endl;
            return;
        }
    }

    vll aa(1e5 + 9);
    aa[0] = 1;
    aa[1] = 2;
    for(int i = 2; i < 1e5 + 9; i++) {
        aa[i] += aa[i - 1];
        if(i > 1) aa[i] += aa[i - 2];
        aa[i] %= MOD;
    }

    ll ans = 1;
    int len  = 1;
    char cur = s[0];
    for(int i = 1; i < sz(s); i++) {
        if(s[i - 1] == s[i]) {
            len++;
        }
        else {
            if(cur == 'u' || cur == 'n') {
                ans = (ans * aa[len - 1]) % MOD;
            }
            len = 1;
            cur = s[i];
        }
    }   

    if(cur == 'u' || cur == 'n') {
        ans = (ans * aa[len - 1]) % MOD;
    }

    cout << ans << endl;
}

int main() {
#ifdef LOCAL
    freopen("xxx.in", "r", stdin);
    freopen("xxx.out", "w", stdout);
    auto start_time = clock();
#else
    // ???
#endif

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.setf(ios::fixed | ios::showpoint);
    cout.precision(12);
    cerr.setf(ios::fixed | ios::showpoint);
    cerr.precision(4);

    solve();

#ifdef LOCAL
    auto end_time = clock();
    cerr << "time: " << (end_time - start_time) * 1.0 / CLOCKS_PER_SEC << endl;
#endif

    return 0;
}