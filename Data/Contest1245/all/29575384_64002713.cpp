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
const int MAXN = 110;
const int MAXM = 10010;
const int MAXK = 110;
const int MAXQ = 200010;

int n, a[3], res[MAXN];
string s;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        FOR(i,0,2) cin >> a[i];
        cin >> s;
        FOR(i,0,SZ(s)-1) res[i] = -1;
        int cnt = 0;
        FOR(i,0,SZ(s)-1) {
            int g = 0;
            if (s[i] == 'R') g = 0;
            else if (s[i] == 'P') g = 1;
            else g = 2;

            g = (g + 1) % 3;

            if (a[g]) {
                a[g]--;
                res[i] = g;
                cnt++;
            }
        }
        FOR(i,0,SZ(s)-1)
            if (res[i] == -1)
                FOR(j,0,2)
                    if (a[j]) {
                        a[j]--;
                        res[i] = j;
                        break;
                    }
        if (cnt >= n / 2 + n % 2) {
            cout << "YES\n";
            FOR(i,0,SZ(s)-1)
                if (res[i] == 0) cout << 'R';
                else if (res[i] == 1) cout << 'P';
                else cout << 'S';
            cout << "\n";
        }
        else cout << "NO\n";
    }
    return 0;
}
