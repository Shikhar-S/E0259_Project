#include <bits/stdc++.h>

#include <ext/pb_ds/detail/standard_policies.hpp>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("O3")

#define F first
#define S second
#define pb push_back
#define llong  long long
#define int llong
#define ld long double
#define endl '\n'


#ifdef ARINOCHKA
const int N = 1 + 100;
#else
#define cerr if(0) cerr
const int N = 1e5 + 1;
#endif




using namespace std;
using namespace __gnu_pbds;


mt19937 gen(chrono::high_resolution_clock::now().time_since_epoch().count());


const int M = 16 + 5;
const int B = 2100;
const int add1 = 39;
const llong per = 1e10;
const llong INF = 1e10;
const int MOD1 = 998244353;
const int MOD = 1e9 + 7;
const int rx[4] = {0, 1, -1, 0};
const int ry[4] = {1, 0, 0, -1};
const char rr[5]= {'5', 'N', 'E', 'S', 'W'};
template <typename T> using ordered_set = tree <T, null_type, less< T >, rb_tree_tag,tree_order_statistics_node_update>;

unordered_set <string> ss;


main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    srand(time(0));
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#else
//    freopen("parts.in", "r", stdin);
//    freopen("parts.out", "w", stdout);
#endif


    int t;
    cin >> t ;
    while(t--){
        int a, b, c, d, k;
        cin >> a >> b >> c >> d >> k;
        int P = 0, pp = 0, ok = 0;
        for(int pen = 1; pen <= k; pen++){
            int pencil = k - pen;
            int lek = c * pen;
            int pract = pencil * d;
            if (lek >= a && pract >= b){
                ok = 1;
                P = pen;
                pp = pencil;
            }
        }
        if (ok){
            cout << P << ' ' << pp << endl;
         }
         else{
            cout << -1 << endl;
         }
    }








    return 0;
}


