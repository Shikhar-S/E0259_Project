#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
//#define int                 long long
#define ll                  long long
#define ld                  long double
#define rep(i,n)            for(int i=0;i<n;i++)
#define hell                1000000007
#define inf                 (ll)1e15
#define vi                  vector<int>
#define vii                 vector< vi >
#define pb                  push_back
#define mp                  make_pair
#define fi                  first
#define se                  second
#define pii                 pair<int,int>
#define all(c)              c.begin(),c.end()
#define sz(c)               (int)c.size()
#define hash1               105727LL
#define hash2               hell
//#define endl                '\n'
#define eps                 1e-10
#define pi                  3.141592653589793238462643383279502884197
typedef tree<pair<int,int>,null_type,less<pair<int,int> >,
				rb_tree_tag,tree_order_statistics_node_update> statisticsTree;
ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a % b); }
ll lcm(ll a, ll b) { return a * (b / gcd(a, b)); }
ll power(ll x, ll y,ll p)
{
	ll res=1;
	x=x%p;
	while(y>0)
	{
		if(y&1)
			res=((res%p)*(x%p))%p;
		y=y>>1;
		x=((x%p)*(x%p))%p;
	}
	return res;
}
ll raichu(ll x,ll y)
{
	ll res=1;
	while(y>0)
	{
		if(y&1)
			res=((res)*(x));
		y=y>>1;
		x=((x)*(x));
	}
	return res;
}
bool isprime(ll n)
{
	if(n<2) return false;
	else if(n==2) return true;
	else if(n%2==0) return false;
	else
	{
		ll z=sqrt(n);
		rep(i,z-1) if(n%(i+2)==0) return false;
		return true;
	}
}
int32_t main()
{
	//freopen("B-large.in","r",stdin);
	//freopen("out2.txt","w",stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int tests=1,Tests;
	cin>>tests;
	Tests=tests;
	while(tests--)
	{
		int n;
		cin>>n;
		string s;
		cin>>s;
		int mi=n,ma=-1;
		rep(i,n)
		{
			if(s[i]=='1')
			{
				mi=min(mi,i);
				ma=max(ma,i);
			}
		}
		if(ma==-1)
		{
			cout<<n<<endl;
		}
		else
		{
			int ans=n;
			ans=max(ans,2*(ma+1));
			ans=max(ans,2*(n-mi));
			// if(mi!=ma)
			// {
			// 	ans=max(ans,)
			// }
			cout<<ans<<endl;
		}
	}
	return 0;
}