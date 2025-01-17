#include <bits/stdc++.h>


using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;


#define int ll
#define rand shittttty_shit
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
mt19937_64 rng_64(chrono::steady_clock::now().time_since_epoch().count());


typedef pair<int, int> pii;
typedef pair<string, string> pst;
typedef pair<pii, pii> piii;
typedef vector<piii> vpii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector< vi > vvi;
typedef vector< vvi > vvvi;
typedef vector<pii> vpi;
typedef vector<short> vs;
typedef vector<vs> vvs;
typedef vector<vvs> vvvs;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef vector<vvl> vvvl;
typedef vector<ld> vld;
typedef vector<vld> vvld;
typedef vector<vvld> vvvld;
typedef vector<string> vst;
typedef vector<vst> vvst;
typedef pair<ld, ld> pld;
typedef pair<pld, pld> pldd;
typedef vector<pld> vpd;
typedef complex<double> base;


#define inmin(a, b) a = min(a, (b))
#define inmax(a, b) a = max(a, (b))
#define my_abs(a) (((a) >= 0) ? (a) : -(a))
#define mp(a, b) make_pair(a, (b))
#define ALL(a) a.begin(),a.end()
#define RALL(a) a.rbegin(),a.rend()
#define sqr(x) ((x) * (x))
#define fori(i, n) for(int i = 0; i < int(n); ++i)
#define SZ(a) ((int)((a).size()))
#define MODIK(a) (a >= M ? a - M : a)
#define triple(T) tuple<T, T, T>
#define quad(T) tuple<T, T, T, T>
#define watch(x) cout << (#x) << " = " << x << endl;
#ifdef MAX_HOME
#define cerr cout
#else
#define cerr if (false) cerr
#endif


const double PI = 2 * acos(0.0);

const string DIGITS = "0123456789";
const string ALPH = "abcdefghijklmnopqrstuvwxyz";

istream &operator >> (istream &in, pii &a)
{
    in >> a.first >> a.second;
    return in;
}


ostream &operator << (ostream &out, pii &a)
{
    out << a.first << ' ' << a.second;
    return out;
}


istream &operator >> (istream &in, pld &a)
{
    in >> a.first >> a.second;
    return in;
}


ostream &operator << (ostream &out, pld &a)
{
    out << a.first << ' ' << a.second;
    return out;
}


template <class T0, class T1>
inline ostream & operator << (ostream &out, pair<T0, T1> &a) {
    return out << "{" << a.first << ", " << a.second << "}";
}

template <class T0, class T1, class T2>
inline ostream & operator << (ostream &out, tuple<T0, T1, T2> &a) {
    return out << "{" << get<0>(a) << ", " << get<1>(a) << ", " << get<2>(a) << "}";
}

template <class T0, class T1, class T2, class T3>
inline ostream & operator << (ostream &out, tuple<T0, T1, T2, T3> &a) {
    return out << "{" << get<0>(a) << ", " << get<1>(a) <<
               ", " << get<2>(a) << ", " <<  get<3>(a) << "}";
}

template<class T>
inline ostream & operator << (ostream &out, vector<T> &a) {
    out << "[";
    fori (i, a.size())
        out << a[i] << vector<string>{", ", "]  "}[i + 1 == a.size()];
    return out;
}


void print(vi kek, int k)
{
    ofstream cout("output.txt");
    cout << SZ(kek) << ' ' << k << '\n';
    for (auto p : kek) {
        cout << p << ' ';
    }
    cout.close();
    exit(0);
}


void smain();

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

#ifdef ART_HOME
    freopen("input.txt", "r", stdin);
    clock_t start = clock();
#endif
    cout << setprecision(12) << fixed;
    smain();
#ifdef ART_HOME
    cout << "\n\n\n\nTOTAL EXECUTION TIME: " << float( clock () - start ) /  CLOCKS_PER_SEC << endl;
#endif
}


const int M1 = 1000000093, p1 = 27162;
const int M2 = 1000000087, p2 = 241;

const ld pi = atan2l(1, 0) * 2, EPS = 1e-8, PEPS = 1e-7, oo = 1e12 + 100;
const int N = 1e5 + 100, B = 50, M = 1e9 + 7, K = 110, psze = 17;


vi vertices[N];
int col[N][3];


int dfs(int v, const vi &lel, int cur, int p = -1)
{
    int ans = col[v - 1][lel[cur]];

    for (int u : vertices[v])
    {
        if (u == p)
            continue;

        ans += dfs(u, lel, (cur + 1) % 3, v);
    }

    return ans;
}


int colour[N];


void dfs2(int v, const vi &lel, int cur, int p = -1)
{
    colour[v] = lel[cur] + 1;

    for (int u : vertices[v])
    {
        if (u == p)
            continue;

        dfs2(u, lel, (cur + 1) % 3, v);
    }

}


void smain() {

    int n;
    cin >> n;

    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < n; ++j)
            cin >> col[j][i];

    for (int i = 1; i < n; ++i)
    {
        int a, b;
        cin >> a >> b;
        vertices[a].push_back(b);
        vertices[b].push_back(a);
    }

    int root = 0;
    for (int i = 1; i <= n; ++i)
    {
        if (SZ(vertices[i]) > 2)
        {
            cout << "-1\n";
            return;
        }
        else if (SZ(vertices[i]) == 1)
            root = i;
    }

    assert(root);

    vi lel(3);
    lel[0] = 0, lel[1] = 1, lel[2] = 2;
    int ans = 1e15;
    vi last;

    do {
        int cnt = dfs(root, lel, 0);
        if (cnt < ans)
        {
            last = lel;
            ans = cnt;
        }

    } while(next_permutation(ALL(lel)));

    dfs2(root, last, 0);
    cout << ans << '\n';
    for (int i = 1; i <= n; ++i)
        cout << colour[i] << ' ';
}