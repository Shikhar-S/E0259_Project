#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef long double ld;
#define rep(i,a,b)  for(ll i=a;i<b;i++)
#define nl cout<<endl

#define pii pair<ll,ll>
#define vi  vector<ll>
#define vii vector<pii>
#define mi  map<ll,ll>
#define all(a)  (a).begin(),(a).end()

#define pb push_back
#define ff first
#define ss second
#define hell 1000000007

#define test4(x,y,z,a) cout<<"x is "<<x<<"		y is "<<y<<"		z is "<<z<<"		a is "<<a<<endl;
#define test3(x,y,z) cout<<"x is "<<x<<"		y is "<<y<<"		z is "<<z<<endl;
#define test2(x,y) cout<<"x is "<<x<<"		y is "<<y<<endl;
#define test1(x) cout<<"x is "<<x<<endl;
#define N 300009

ll power(ll a,ll b,ll m)
{
	ll ans=1;
	while(b)
	{
		if(b&1)
			ans=(ans*a)%m;
		b/=2;
		a=(a*a)%m;
	}
	return ans;
}
int main()
{	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
        ll n;cin>>n;
	ll a[n+2];
	rep(i,1,n+1)
	cin>>a[i];
	sort(a+1,a+n+1);
	if(n==1)
	{
		cout<<a[1]*a[1]<<endl;
		return 0;
	}
	if(n&1)	
	{
		ll x=0,y=0;
		for(ll i=n;i>n/2;i--)
		x+=a[i];
		for(ll i=1;i<=n/2;i++)
		y+=a[i];
		//x+=a[(n/2)+1];
		cout<<(x*x)+(y*y);nl;
	}
	else
	{
		ll x=0,y=0;
		for(ll i=n;i>n/2;i--)
		x+=a[i];
		for(ll i=1;i<=n/2;i++)
		y+=a[i];
		cout<<(x*x)+(y*y);nl;
	}
}
	
		
	