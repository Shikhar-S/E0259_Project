/*
Nahid Hossain
Jahangirnagar University
Roll:54
*/
#include<bits/stdc++.h>
#define ll          long long int
#define db          double
#define pf          printf
#define sf          scanf
#define ff          first
#define ss          second
#define clr         clear()
#define sz          size()
#define pb          push_back
#define mk          make_pair
#define pi          acos(-1)
#define inf         100000000000000000
#define mod         100000007
#define ull         unsigned long long int
#define f(i,k,n)    for(ll i=k;i<n;i++)
#define fr(i,n,k)   for(i=n;i>=k;i--)
#define ent(a)      scanf("%lld",&a)
#define ent2(a,b)   scanf("%lld%lld",&a,&b)
#define ent3(a,b,c) scanf("%lld%lld%lld",&a,&b,&c)
#define mem(a)      memset(a,0,sizeof(a))
#define vec(v,s)    vector<ll>v[s]
#define arr(a,s)    ll a[s];
#define bitone(x)   __builtin_popcount(x)
//#define check(n,pos) (n&(1<<pos))
//#define set(n,pos)  (n|(1<<pos))
//knight and king//

//for(i=x;i>0;i=(i-1)&x)
int dr[]= {2, 2, -2, -2, 1, -1, 1, -1};
int dc[]= {1,-1,  1, -1, 2,  2,-2, -2};
int dr1[]= {0, 0, 0, 1, 1, 1, -1, -1, -1};
int dc1[]= {-1,0, 1,-1, 0, 1, -1, 0,   1};
int dr2[]= {0, 0, 1, -1};
int dc2[]= {1,-1, 0,  0};
////////////////////////////
#define ma 100005
using namespace std;
ll mark[ma];
ll ans;
map<pair<ll,ll>,ll>mp;
set<ll>s;
void dfs(ll u)
{
    ll i;
    vector<ll>v;
    set<ll>::iterator it;
    mark[u]=1;
    for(it=s.begin();it!=s.end();it++)
    {
        ll x=*it;
        ll y=u;
        if(x>y)
        {
            if(mp[{y,x}]==0)v.pb(x);
        }
        else
        {
            if(mp[{x,y}]==0)v.pb(x);
        }
    }

    for(i=0;i<v.sz;i++)
    {
        ans++;

        s.erase(s.find(v[i]));
    }

    for(i=0;i<v.sz;i++)dfs(v[i]);


}
int main()
{
    ll n,m,i,j,u,v;
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    while(cin>>n>>m)
    {

        for(i=1;i<=m;i++)
        {
            cin>>u>>v;
            if(u>v)swap(u,v);
            mp[{u,v}]=1;
        }




        for(i=1;i<=n;i++)s.insert(i);
        for(i=1;i<=n;i++)
        {
            if(mark[i]==0)
            {
                s.erase(s.find(i));
                dfs(i);
            }
        }
        cout<<n-1-ans<<endl;



    }
    return 0;
}
