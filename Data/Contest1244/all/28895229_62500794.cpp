#pragma GCC target("avx2")
#pragma GCC optimize("O3")
   
#include <x86intrin.h>
#include <bits/stdc++.h>   
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
 
using namespace __gnu_pbds;
using namespace std;

template<typename T> using ordered_set = tree <T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
     
#define F first
#define S second           
#define lb lower_bound               
#define ub upper_bound
#define pb push_back
#define pf push_front    
#define ppb pop_back
#define mp make_pair
#define bpp __builtin_popcountll                                                                                        
#define sqr(x) ((x) * (x)) 
#define al 0x3F3F3F3F
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define in insert
#define ppf pop_front
#define endl '\n'
//#define int long long
 
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;
 
const int mod = (int)1e9 + 7;
const int N = (int)3e5 + 123;
const ll inf = (ll)1e18 + 1;

const double pi = acos (-1.0);
const double eps = 1e-7;                  
const int dx[] = {0, 0, 1, 0, -1};
const int dy[] = {0, 1, 0, -1, 0};

int n, used[2][1001], dp[2][1001];
char s[N];
vector <pii> order;

void dfs (int x = 0, int y = 1) {
   used[x][y] = 1;
   if (y < n && !used[x][y + 1]) dfs (x, y + 1);
   if (y > 1 && !used[x][y - 1]) dfs (x, y - 1);
   if (s[y] == '1' && !used[(x ^ 1)][y]) dfs ((x ^ 1), y);
   order.pb ({x, y});   
}

inline void boost () {                    
   ios_base :: sync_with_stdio (NULL);
   cin.tie (NULL), cout.tie (NULL);          
}                                                     

inline void Solve () {
   cin >> n >> s + 1;
   int res = n;
   for (int i = 1; i <= n; i ++) {
      if (s[i] == '1') {
         res = max (res, max (i, n - i + 1) + max (n - i + 1, i));      
      }
   }
   cout << res << endl;
}

main () {                                       
// freopen (".in", "r", stdin);    
// freopen (".out", "w", stdout);              
   boost ();
   int tt = 1;
   cin >> tt;   
   while (tt --) {
      Solve ();
   }                                               
   return 0;      
}
                          