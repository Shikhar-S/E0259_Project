#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ll long long
#define ld long double
#define bitcount __builtin_popcountll
#define mod 1000000007
#define pii pair<int,int>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define s(n) scanf("%d",&n)
#define sll(n) scanf("%lld",&n)
#define all(v) v.begin(),v.end()
#define p(x) printf("%d ",x)
#define pll(x) printf("%lld",x)
#define pend printf("\n")
#define debug(x) cout << "> " << #x << " : " << x << "\n";
#define gur_chella ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define N 200005  
#define LN 18
#define infinity 4123456789123456789ll
#define CMOD 998244353
#define pall pair<ll,ll>
typedef tree<
int,
null_type,
less<int>,
rb_tree_tag,
tree_order_statistics_node_update>
ordered_set;
ll powfi(ll x, ll y, ll p)
{
    ll ans = 1;
    x%=p;
    while (y > 0)
    {
        if (y & 1)
            ans = ((ans%p)*(x%p))%p;
        y = y>>1;
        x = (x*x)%p;
    }
    return ans%p;
}
ll power(ll x, ll y)
{
    ll ans = 1;
   // x%=p;
    while (y > 0)
    {
        if (y & 1)
            ans = ((ans)*(x));
        y = y>>1;
        x = (x*x);
    }
    return ans;
}
const ll Random = chrono::high_resolution_clock::now().time_since_epoch().count();
struct chash {
    ll operator()(int x) const { return (x ^ Random); }
};
#define ht gp_hash_table<int, int, chash>
// void init()
// {
//  for(int i=0;i<2002;i++)
//  {
//      for(int j=0;j<2002;j++)
//      {
//          if(j==0 || j==i)
//              ncr[i][j]=1;
//          else if(j>i)
//              ncr[i][j]=0;
//          else
//              ncr[i][j]=((ncr[i-1][j-1]%CMOD) + (ncr[i-1][j] % CMOD) )%CMOD;
//      }
//  }
// }
// inline int scan()
// {
//     char c = getchar_unlocked();
//     int x = 0;
//     while(c<'0'||c>'9'){
//         c=getchar_unlocked();
//     }
//     while(c>='0'&&c<='9'){
//         x=(x<<1)+(x<<3)+c-'0';
//         c=getchar_unlocked();
//     }
//     return x;
// }
// ------------------End of Template-------------//
#define int long long
vector<int>v;
signed main()
{
    gur_chella
    int i, j;
    int T=1;
    //cin>>T;
    while(T--)
    {
        int n;
        cin>>n;
        for(i=1;i<=n;++i)
        {
            cin>>j;
            v.pb(j);
        }
        sort(all(v),greater<int>());
        int l=0, r=n-1;
        int l1=0, l2=0;
        bool par=true;
        while(l<=r)
        {
            if(par)
            {
                l1+=v[l++];
                par^=1;
            }
            else
            {
                l2+=v[r--];
                par^=1;
            }
        }
        cout<<(l1*l1) + (l2*l2);
    }
    
       
}