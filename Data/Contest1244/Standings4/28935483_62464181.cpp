#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#define debug(x) cerr << #x << " = " << x << endl;
#define ddebug(x, y) cerr << #x << " = " << x << ", " << #y << " = " << y << endl;
#else
#define debug(x);
#define ddebug(x, y);
#endif

#define ld long double
#define ll long long
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define FOR(i, a, b) for(int i = (int)(a); i < (int)(b); i++)
#define FORD(i, a, b) for(int i = (int)(a); i > (int)(b); i--)
#define sz(a) (int)a.size()
#define all(a) a.begin(), a.end()
#define sq(a) ((a) * (a))
#define vi vector <int>
#define pii pair <int, int>
#define vl vector <long long>
#define pll pair <long long, long long>
#define MMIN(a, b) a = min(a, b)
#define MMAX(a, b) a = max(a, b)

template <typename T>  
ostream& operator <<(ostream &out, vector<T> a){ 
    FOR(i, 0, sz(a)) 
        if(i != sz(a) - 1)
            out << a[i] << " ";   
        else
            out << a[i] << endl;   
    return out; 
} 
template <typename T1, typename T2> 
istream& operator >>(istream &in, pair<T1, T2> & a){
    in >> a.fi >> a.se;
    return in;
}

template <typename T1, typename T2> 
ostream& operator <<(ostream & out, pair<T1, T2> & a){
    out << a.fi << " " << a.se;
    return out;
}

struct fastio{
    fastio(){
#ifndef LOCAL
        string filename = "";
        if(filename.size()){
            string inp = filename + ".in";
            string out = filename + ".out";
            freopen(inp.c_str(), "r", stdin);
            freopen(out.c_str(), "w", stdout);
        }
#endif
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout << showpoint;
        cout << setprecision(12);
        cout << fixed;    

        cerr << showpoint;
        cerr << setprecision(3);
        cerr << fixed;    
    }
}_____;

const int MAX = 2e6 + 10;
const ll INF = 1e9 + 10;
const ld EPS = 1e-8;
const ll MOD = 1e9 + 7;    
           
void solve(){
	int T;
	cin >> T;
	FOR(____, 0, T){
		int a, b, c, d, k;
		cin >> a >> b >> c >> d >> k;
		int fi = (a - 1) / c + 1;
		int se = (b - 1) / d + 1;
		if(fi + se > k)
			cout << -1 << endl;
		else
			cout << fi << " " << se << endl;
  
    }
}

             
int main(){ 
    #ifdef LOCAL
    clock_t beg = clock(); 
    #endif
    solve();
    #ifdef LOCAL
    clock_t end = clock();
    ld elapsed_secs = (ld)(end - beg) / CLOCKS_PER_SEC;
    debug(elapsed_secs);
    #endif
    return 0;
}