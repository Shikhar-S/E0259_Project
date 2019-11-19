
#include<bits/stdc++.h>
#define pb push_back
#define ff first
#define ss second
#define mp make_pair
#define mod 1000000007
#define deb(x) cout<<#x<<" : "<<x<<endl;
#define deb2(x,y) cout<<#x<<" : "<<x<<"\t"<<#y<<" : "<<y<<endl;
#define deb3(x,y,z) cout<<#x<<" : "<<x<<"\t"<<#y<<" : "<<y<<"\t"<<#z<<" : "<<z<<endl;
#define inf 1000000000000000 

#define FIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
typedef long long ll;
#define ld long double

/*
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 
  
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> 
*/

using namespace std;
 
 
long long modulo(long long base,long long exponent,long long modulus);
long long choose(ll n,ll k);
ll inverse(ll a,ll m);
void build();
void fileio();
ll ncr(ll n,ll r);
 
const int nax=1e6+10;
const int LG=log2(nax)+1;
vector<ll> fact(nax);

vector<ll> a;
vector<ll> adj[nax];
ll c[4][nax];

void dfs(ll x,ll p)
{
	a.pb(x);
	for(int i=0;i<adj[x].size();i++)
	{
		ll y = adj[x][i];
		if(y==p) continue;
		dfs(y,x);
	}
}
 
int32_t main() {
 
    FIO
    //fileio();
    //build();
    ll n;
    cin>>n;

    for(int i=1;i<=n;i++)
    	cin>>c[1][i];
    for(int i=1;i<=n;i++)
    	cin>>c[2][i];
    for(int i=1;i<=n;i++)
    	cin>>c[3][i];

    for(int i=0;i<(n-1);i++)
    {
    	ll x,y;
    	cin>>x>>y;

    	adj[x].pb(y);
    	adj[y].pb(x);
    }

    for(int i=1;i<=n;i++)
    {
    	if(adj[i].size()>2)
    	{
    		cout<<-1<<endl;
    		return 0;
    	}
    }
    for(int i=1;i<=n;i++)
    {
    	if(adj[i].size()==1)
    	{
    		dfs(i,-1);
    		break;
    	}
    }

    ll perm[] = {1,2,3};
  	sort (perm,perm+3);

  	ll ans = LONG_LONG_MAX;
  	
  	do {
    	
    	ll cost = 0;
    	for(int i=0;i<n;i++)
    	{
    		ll x = a[i];
    		cost += c[perm[i%3]][x];
    	}

    	ans = min(ans,cost);
  	} while ( std::next_permutation(perm,perm+3) );

  	sort (perm,perm+3);
  	vector<ll> f(n+1,0);
  	do {
    	
    	ll cost = 0;
    	for(int i=0;i<n;i++)
    	{
    		ll x = a[i];
    		cost += c[perm[i%3]][x];
    	}

    	if(cost==ans)
    	{
    		for(int i=0;i<n;i++)
    		{
    			f[a[i]] = perm[i%3];
    		}
    		cout<<cost<<endl;
    		for(int i=1;i<=n;i++)
    			cout<<f[i]<<" ";
    		cout<<endl;
    		return 0;
    	}
  	} while ( std::next_permutation(perm,perm+3) );

 
    return 0;
}
 
ll ncr(ll n,ll r)
{
    if(r>n || r<0 || n<0)
        return 0;
    ll ans=fact[n];
    ll temp=(fact[n-r]*fact[r])%mod;
    ans=(ans*inverse(temp,mod))%mod;
    return ans;
}

void fileio()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
} 
void build()
{
    fact[0]=1;
    for(ll i=1;i<nax;i++)
        fact[i]=(fact[i-1]*i)%mod;   
}
 
long long modulo(long long base,long long exponent,long long modulus)
{
    if(modulus ==1)
        return 0;
 
    long long result=1;
    base=base % modulus;
    while(exponent>0)
    {
        if(exponent%2==1)
        {
            result=(result*base) % modulus;
 
        }
        exponent=exponent>>1;
        base = (base*base) % modulus;
    }
    return result;
}
 
long long choose(ll n,ll k)
{
    if(k==0)  return 1;
    return (n* choose(n-1,k-1))/k;
}
 
void EE(ll a,ll b,ll &co1,ll &co2)
{
    if(a%b==0)
    {
        co1=0;
        co2=1;
        return;
    }
    EE(b,a%b,co1,co2);
    ll temp=co1;
    co1=co2;
    co2=temp-co2*(a/b);
}
 
ll inverse(ll a,ll m)
{
    ll x,y;
    EE(a,m,x,y);
    if(x<0) x+=m;
    return x;
}