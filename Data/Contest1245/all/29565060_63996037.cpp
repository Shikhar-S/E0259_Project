//   __________________
//  | ________________ |
//  ||          ____  ||
//  ||   /\    |      ||
//  ||  /__\   |      ||
//  || /    \  |____  ||
//  ||________________||
//  |__________________|
//  \###################\
//   \###################\
//    \        ____       \
//     \_______\___\_______\
// An AC a day keeps the doctor away.

#include <bits/extc++.h>
#pragma GCC optimize("Ofast")
#pragma loop_opt(on)
#ifdef local
#define debug(x) (cerr<<#x<<" = "<<(x)<<'\n')
#else
#define debug(x) ((void)0)
#endif // local
#define all(v) begin(v),end(v)
#define siz(v) (ll(v.size()))
#define get_pos(v,x) (lower_bound(all(v),x)-begin(v))
#define sort_uni(v) sort(begin(v),end(v)),v.erase(unique(begin(v),end(v)),end(v))
#define pb emplace_back
#define ff first
#define ss second
#define mid (l+(r-l>>1))
#define mem(v,x) memset(v,x,sizeof v)

using namespace std;
using namespace __gnu_pbds;
typedef int64_t ll;
typedef long double ld;
typedef pair<ll,ll> pll;
typedef pair<ld,ld> pld;
template <typename T> using max_heap = __gnu_pbds::priority_queue<T,less<T> >;
template <typename T> using min_heap = __gnu_pbds::priority_queue<T,greater<T> >;
template <typename T> using rbt = tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;
constexpr ld PI = acos(-1), eps = 1e-9;
constexpr ll N = 1000026, INF = 1e18, MOD = 1000000, K = 5;
constexpr ll modpow(ll e,ll p,ll m=MOD) {ll r=1; for(;p;p>>=1,e=e*e%m) if(p&1) r=r*e%m; return r;}
constexpr inline ll cdiv(ll x, ll m) { return (x+m-1)/m; } // ceiling divide, x/m for flooring divide
template <typename T> void M(T &x, ll m=MOD){x%=m; if(x<0) x+=m;}

signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int t,a,b;
    string verd[2] = {"Finite\n","Infinite\n"};
    cin >> t;
    while(t--) cin >> a >> b, cout << verd[__gcd(a,b)!=1];
}
