#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef unsigned long long ull;
typedef long double ld;
typedef vector<int> vi;
typedef vector<long long int> vl;
typedef vector<vector<int>> vvi;
typedef vector<vector<long long int>> vvl;
typedef pair<int, int> pii;
typedef pair<long long int, long long int> pll;
typedef vector<pair<int, int>> vii;
typedef vector<pair<long long int, long long int>> vll;
#define fast() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define test() long long int t; cin >> t; cin.ignore(); while(t--) 
#define ff first
#define ss second
#define pb push_back
#define pf push_front
#define mp make_pair
#define MOD 1000000007
#define SMOD 998244353
#define pq priority_queue
#define all(x) x.begin(),x.end()
#define SP(x) setprecision(x)
#define sp " "
#define inp(a) ll a;cin>>a;cin.ignore()
#define inps(a,b) ll a,b;cin>>a>>b;cin.ignore()
#define out(a) cout<<SP(20)<<a<<'\n'
#define outs(a,b) cout<<SP(20)<<a<<" "<<b<<'\n'
#define ins insert
#define er erase
#define lb lower_bound
#define ub upper_bound
#define printclock cerr<<"Time : "<<1000*(ld)clock()/(ld)CLOCKS_PER_SEC<<"ms\n";
#define inpa(a,n) ll a[n]; for(int i=0; i<n; i++){cin>>a[i];}
#define inpv(a,n) vl a; for(int i=0; i<n; i++){inp(x);a.pb(x);}
#define outa(a,n) for(int i=0;i<n;i++){cout<<a[i]<<" ";}cout<<'\n';
#define outv(v) for(auto i:v){cout<<i<<" ";}cout<<'\n';
set<char> vow = {'a','e','i','o','u','A','E','I','O','U'};
ll xpow(ll n, ll m){if(m==0){return 1;}else{ll x = xpow(n, m/2);if(m&1){return x*x*n;}else{return x*x;}}}
ll xmod(ll a, ll m){return (((a%m)+m)%m);}
ll xmodpow(ll n, ll m, ll y){if(m==0){return 1;}else{ll x = xmodpow(n, m/2, y);if(m&1){return xmod((xmod((xmod(x,y)*xmod(x,y)),y)*xmod(n,y)),y);}else{return xmod((xmod(x,y)*xmod(x,y)),y);}}}

vector <pll> g[2005];
bool vis[2005];
vector <ll> par(2005, -1);

ll prim(ll x)
{
    priority_queue<pair<ll, pll>, vector<pair<ll, pll>>, greater<pair<ll, pll>> > Q;
    ll y;
    ll minimumCost = 0;
    pair <ll, pll> p;
    Q.push({0, {x, -1}});
    ll xx;
    while(!Q.empty())
    {
        p = Q.top();
        Q.pop();
        xx = p.second.first;
        ll z = p.second.second;
        if(vis[xx] == true)
            continue;
        minimumCost += p.first;
        par[xx] = z;
        vis[xx] = true;
        for(int i = 0;i < g[xx].size();++i)
        {
            y = g[xx][i].second;
            if(vis[y] == false)
                Q.push({g[xx][i].ff, {g[xx][i].second, xx}});
        }
    }
    return minimumCost;
}

int main(){
    fast();

/* you get what you work for not what you wish for */

    ll n;
    cin >> n;
    vll a(n+5);
    for(int i=0; i<n; i++){
        cin >> a[i+1].ff >> a[i+1].ss;
    }
    vl c(n+5);
    for(int i=1; i<=n; i++){
        cin >> c[i];
    }
    vl k(n+5);
    for(int i=1; i<=n; i++){
        cin >> k[i];
    }
    for(int i=1; i<=n; i++){
        g[0].pb({c[i], i});
        g[i].pb({c[i], 0});
    }
    for(int i=1; i<=n; i++){
        for(int j=i+1; j<=n; j++){
            ll k1 = k[i];
            ll k2 = k[j];
            ll dis = abs(a[i].ff-a[j].ff) + abs(a[i].ss-a[j].ss);
            ll cost = (k1+k2)*dis;
            g[i].pb({cost, j});
            g[j].pb({cost, i});
        }
    }
    cout << prim(0) << endl;
    set <ll> build;
    for(int i=1; i<=n; i++){
        if(par[i]==0){
            build.ins(i);
        }
    }
    set <pll> conn;
    for(int i=1; i<=n; i++){
        if(par[i]!=0){
            conn.ins({i, par[i]});
        }
    }
    cout << build.size() << endl;
    for(auto i:build){
        cout << i << " ";
    }
    cout << endl;
    cout << conn.size() << endl;
    for(auto i:conn){
        cout << i.ff << " " << i.ss << endl;
    }
}