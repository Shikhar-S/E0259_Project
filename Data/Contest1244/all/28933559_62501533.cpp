
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

bool check(vector<ll> &a,ll k,ll mid)
{
	ll n = a.size();

	vector<ll> prefix(n);
	prefix[0] = a[0];
	for(int i=1;i<n;i++)
		prefix[i] = prefix[i-1] + a[i];

	vector<ll> suffix(n);
	suffix[n-1] = a[n-1];
	for(int i=n-2;i>=0;i--)
		suffix[i] = suffix[i+1] + a[i];

	for(int i=0;i<n;i++)
	{
		ll x = a[i];
		ll ind = upper_bound(a.begin(),a.end(),a[i]+mid) - a.begin();
		ind--;

		ll t1 = i;
		ll t2 = n-1-ind;

		// deb2(i,ind);
		// deb2(a[i],a[ind]);

		ll cost = 0;
		if(i!=0)
		cost+= t1*a[i] - prefix[i-1]; 
		if(ind!=n-1)
		cost+= suffix[ind+1] - t2*(a[i]+mid);

		// deb(cost);
		if(cost<=k)
			return true;
	}

	for(int i=0;i<n;i++)
	{
		ll x = a[i];
		ll ind = lower_bound(a.begin(),a.end(),a[i]-mid) - a.begin();

		ll t1 = ind;
		ll t2 = n-1-i;

		// deb2(i,ind);
		// deb2(a[i],a[ind]);

		ll cost = 0;
		if(ind!=0)
		cost+= t1*(a[i]-mid) - prefix[ind-1]; 
		if(i!=n-1)
		cost+= suffix[i+1] - t2*(a[i]);

		// deb(cost);
		if(cost<=k)
			return true;
	}
	return false;
} 
 
int32_t main() {
 
    FIO
    //fileio();
    //build();
    ll n,k;
    cin>>n>>k;

    vector<ll> a(n);
    for(int i=0;i<n;i++)
    	cin>>a[i];

    sort(a.begin(),a.end());
    ll low = 0 ,high = 1e9 + 5;
    ll ans = 0;

    // deb(check(a,k,2));

    while(low<=high)
    {
    	ll mid = (low+high)/2;

    	if(check(a,k,mid))
    	{
    		ans = mid;
    		high = mid-1;
    	}
    	else
    		low = mid+1;
    }
    cout<<ans<<endl;
 
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