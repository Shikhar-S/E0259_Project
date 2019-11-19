#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <functional>
#pragma warning(disable:4996)
#pragma comment(linker, "/STACK:336777216")
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;

typedef double db;
typedef long double ldb;
typedef pair <int, int> pii;
typedef pair <db, db> pdd;
typedef vector<int> vi;
typedef vector<vector<int> > matrix;
#define m1 make_pair
#define pb push_back
#define flush fflush(stdout)
#define IOS std::ios::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);
#define reset(x,v) memset(x,v,sizeof(x))
#define sz(x) (int)(x.size())
#define ff first
#define ss second
#define endl "\n"
#define  int long long int
#define debug(x) (cerr << #x << ": " << x << "\n")
#define setbits(x) __builtin_popcount(x)
inline ll gcd(ll a,ll b){if(a==0) return b;return gcd(b%a,a);}
inline ll power(ll a,ll n,ll m){if(n==0)return 1;ll p=power(a,n/2,m);p=(p*p)%m;if(n%2) return (p*a)%m;else return p;}
const ll hell =1000000007;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x3f3f3f3f3f3f3f3f;

typedef tree<int, null_type, less<int>, rb_tree_tag,
tree_order_statistics_node_update>
ordered_set;
vector<pair<int,int> > adj[2005];int x[2005];int y[2005];int c[2005];int k[2005];int ans[2005];bool is[2005];
int ans1[2005];
int32_t main()
{
    IOS;
    int n;
    cin>>n;
    // int x[n+1];
    //int y[n+1];
    for(int i=1;i<=n;i++)
        cin>>x[i]>>y[i];
    // int c[n+1];int k[n+1];
    for(int i=1;i<=n;i++)
        cin>>c[i];
    for(int i=1;i<=n;i++)
        cin>>k[i];
    int d;
    for(int i=1;i<=n;i++)
    {
        for(int j=i+1;j<=n;j++)
        {
            d=abs(x[i]-x[j])+abs(y[i]-y[j]);
            adj[i].pb(m1(j,(k[i]+k[j])*(d)));
            adj[j].pb(m1(i,(k[i]+k[j])*(d)));
        }
    }
    set<pair<int,int> >s;
    set<pair<int,int> >::iterator it;pair<int,int>pr;int u,v,w;
    int tl=0;
    for(int i=1;i<=n;i++)
    {ans[i]=c[i];
        is[i]=1;
    }
    for(int i=1;i<=n;i++)
        s.insert(m1(ans[i],i));
    //int ans1[n+1]={0};
    while(!s.empty())
    {
        pr=(*s.begin());
        s.erase(s.begin());
        u=pr.second;
        for(int i=0;i<adj[u].size();i++)
        {
            v=adj[u][i].first;
            w=adj[u][i].second;
            it=s.find(m1(ans[v],v));
            if(it!=s.end())
            {
                
                if(ans[v]>=w)
                {
                    s.erase(s.find(m1(ans[v],v)));
                    is[v]=0;
                    ans[v]=w;
                    s.insert(m1(ans[v],v));
                    ans1[v]=u;
                }
                
            }
            
        }
    }
    for(int i=1;i<=n;i++)
        tl+=ans[i];
    cout<<tl<<endl;
    int cnt=0;
    for(int i=1;i<=n;i++)
        if(is[i])
            cnt++;
    cout<<cnt<<endl;
    for(int i=1;i<=n;i++)
        if(is[i])
            cout<<i<<" ";
    cout<<endl;
    // int mn;
    // vector<pair<int,int> >pe;int j1;int x1;
    cout<<n-cnt<<endl;
    for(int i=1;i<=n;i++)
        if(!is[i])
            cout<<i<<" "<<ans1[i]<<endl;
    /*
     cout<<pe.size()<<endl;
     for(int i=0;i<pe.size();i++)
     cout<<pe[i].first<<" "<<pe[i].second<<endl;
     */
    return 0;
}

