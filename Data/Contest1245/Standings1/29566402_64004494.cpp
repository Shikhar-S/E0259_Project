#include<bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp> // Common file
//#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update

using namespace std;
//using namespace __gnu_pbds;
//typedef tree<
//        pair<long long, int>, // change type
//        null_type,
//        less<pair<long long, int> >, // change type
//        rb_tree_tag,
//        tree_order_statistics_node_update>
//        ordered_set;

//template<class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;

typedef long long ll;
#define rep(i, start, end) for(int i = start; i < end; ++i)
#define sz(x) (int)(x).size()
#define pb push_back
#define X first
#define Y second
#define all(x) x.begin(), x.end()
#define clr(d, v) memset(d, v, sizeof(d))
#define pii pair<int, int>
#define debug(x) cerr << #x << " : " << (x) << endl
const double PI = 3.14159265358979323846;
const double eps = (1e-5);
int isGreater(long double x, long double y)
{
    if (abs(x - y) < eps)
        return 0;
    if (x > y)
        return 1;
    return -1;
}


int n;
enum{R, P, S};
int cnt[3];
const int MAX_N = 105;
int a[MAX_N];
int win[3];
int nr, np, ns;
string s;

int f(int x, int y){
    int cnt = 0;
    for (int i = 0; i < n && cnt < win[x]; ++i){
        if (a[i] == y){
            ++cnt;
            if (x == R)
                s[i] = 'R';
            else if (x == P)
                s[i] = 'P';
            else
                s[i] = 'S';
        }
    }
    return cnt;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
//    freopen("facebook.txt", "w", stdout);
#endif
    int tc;
    cin >> tc;
    while(tc--){
        cin >> n >> nr >> np >> ns;
        clr(cnt, 0);
        rep(i,0,n){
            char c;
            cin >> c;
            if (c == 'R')
                a[i] = R;
            else if (c == 'P')
                a[i] = P;
            else
                a[i] = S;
            cnt[a[i]]++;
        }

        win[R] = min(cnt[S], nr);
        win[S] = min(cnt[P], ns);
        win[P] = min(cnt[R], np);

        nr -= win[R];
        ns -= win[S];
        np -= win[P];
        s.clear();
        s.resize(n, 0);
        int ans = f(R, S) + f(S, P) + f(P, R);
        if (ans >= (n + 1)/2)
        {
            cout << "YES\n";
            for (int i = 0; i < n; ++i){
                if (s[i] == 0)
                {
                    if (nr)
                        s[i] = 'R', --nr;
                    else if (np)
                        s[i] = 'P', --np;
                    else if (ns)
                        s[i] = 'S', --ns;
                }
            }
            cout << s << '\n';
        }
        else
            cout << "NO\n";


    }
    return 0;
}