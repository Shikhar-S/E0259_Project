#define INTERACTIVE
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // gp_hash_table<int, int> == hash map
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
template <typename T> using min_heap = priority_queue<T, vector<T>, greater<T>>;
template <typename T> using max_heap = priority_queue<T, vector<T>, less<T>>;
template <typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>; 
template <typename K, typename V> using hashmap = gp_hash_table<K, V>;

template<typename A, typename B> ostream& operator<<(ostream& out, pair<A, B> p) { out << "(" << p.first << ", " << p.second << ")"; return out;}
template<typename T> ostream& operator<<(ostream& out, vector<T> v) { out << "["; for(auto& x : v) out << x << ", "; out << "]";return out;}
template<typename T> ostream& operator<<(ostream& out, deque<T> v) { out << "["; for(auto& x : v) out << x << ", "; out << "]";return out;}
template<typename T> ostream& operator<<(ostream& out, set<T> v) { out << "{"; for(auto& x : v) out << x << ", "; out << "}"; return out; }
template<typename K, typename V> ostream& operator<<(ostream& out, map<K, V> m) { out << "{"; for(auto& e : m) out << e.first << " -> " << e.second << ", "; out << "}"; return out; }
template<typename K, typename V> ostream& operator<<(ostream& out, hashmap<K, V> m) { out << "{"; for(auto& e : m) out << e.first << " -> " << e.second << ", "; out << "}"; return out; }

template<typename T> T read() {T x;cin >> x;return x;}
template<typename T> vector<T> read(int n) {vector<T> v(n);for(auto& x : v) cin >> x;return v;}
template<typename A, typename B>istream& operator>>(istream& in, pair<A, B>& p) {return in >> p.first >> p.second;}

#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr)
#define TESTS(t) int NUMBER_OF_TESTS; cin >> NUMBER_OF_TESTS; for(int t = 1; t <= NUMBER_OF_TESTS; t++)
#define FOR(i, begin, end) for (int i = (begin); i < (end); i++)
#define sgn(a)     ((a) > eps ? 1 : ((a) < -eps ? -1 : 0))
#define precise(x) fixed << setprecision(x)
#define all(a) a.begin(), a.end()
#define pb push_back
#define rnd(a, b) (uniform_int_distribution<int>((a), (b))(rng))
#ifndef LOCAL
    #define cerr if(0)cout
    #ifndef INTERACTIVE
        #define endl "\n"
    #endif
    #define debug(args...) if(0){}
#else
    #define debug(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); dbg(_it, true, args); }
    void dbg(istream_iterator<string> it, bool isStart) {cerr << "</debug>" << endl;}
    template<typename T, typename... Args>
    void dbg(istream_iterator<string> it, bool isStart, T a, Args... args) {
        if(isStart) cerr << "<debug>" << endl;
        cerr << "  " << *it << " = " << a << endl;
        dbg(++it, false, args...);
    }
#endif
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
std::chrono::steady_clock::time_point __clock__;
void startTime() {__clock__ = std::chrono::steady_clock::now();}
ld getTime() {
    auto end = std::chrono::steady_clock::now();
    auto t = std::chrono::duration_cast<std::chrono::microseconds> (end-__clock__).count();
    return ld(t)/1e6;
}
void timeit(string msg) {
    cerr << "> " << msg << ": " << precise(6) << getTime() << endl;
}
template<typename T> inline bool maxi(T& a, T b) { return b > a ? (a = b, true) : false; }
template<typename T> inline bool mini(T& a, T b) { return b < a ? (a = b, true) : false; }
const ld PI = asin(1) * 2;
const ld eps = 1e-6;
const int oo = 2e9;
const ll OO = 2e18;
const ll MOD = 1000000007;
const int MAXN = 200000;

void solve(int n, int a, int b, int c, string s) {
    int wins = 0;
    string ans = "";
    for(char x : s) {
        char toPlay = '?';
        if(x == 'R') {
            if(b > 0) {
                b--;
                wins++;
                toPlay = 'P';
            }
        }
        else if(x == 'P') {
            if(c > 0)  {
                c--;
                wins++;
                toPlay = 'S';
            }
        }
        else {
            if(a > 0) {
                a--;
                wins++;
                toPlay = 'R';
            }
        }
        ans.pb(toPlay);
    }
    int need = n/2+n%2;
    if(wins < need) {
        cout << "NO" << endl;
        return;
    }
    for(char& x : ans) {
        if(x == '?') {
            if(a > 0) {
                a--;
                x = 'R';
            } else if(b > 0) {
                b--;
                x = 'P';
            } else if(c > 0) {
                c--;
                x = 'S';
            } else {
                exit(1);
            }
        }
    }
    cout << "YES\n" << ans << endl;
}

int main()
{
    FAST_IO;
    startTime();

    TESTS(t) {
        int n;
        cin >> n;
        int a, b, c;
        cin >> a >> b >> c;
        string s;
        cin >> s;
        solve(n, a, b, c, s);
    }

    timeit("Finished");
    return 0;
}