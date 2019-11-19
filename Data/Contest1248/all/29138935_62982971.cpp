/****************************
/////  Shubham Singhal
/////  LNMIIT
*****************************/
#include <bits/stdc++.h>
#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define ppb pop_back
#define pf push_front
#define ppf pop_front
#define eb emplace_back
#define lwr lower_bound
#define upr upper_bound
#define pq priority_queue
#define umap unordered_map
#define rep(i,n) for(i=0; i<n;i++)
#define repp(i,a,n) for(i=a; i<n;i++)
#define precise(x) cout<<fixed<<setprecision(x)
#define all(x) x.begin(),x.end()
#define lcm(a,b) (a*b)/__gcd(a,b)
#define prn(x) cout<<x<<"\n"
#define prn2(x, y) cout<<x<<" "<<y<<"\n"
#define prn3(x, y, z) cout<<x<<" "<<y<<" "<<z<<"\n"
#define prn4(x, y, z, a) cout<<x<<" "<<y<<" "<<z<<" "<<a<<"\n"
#define prnv(x) for(auto i:x) cout<<i<<" "; cout<<"\n"
#define MOD 1000000007
#define MAX 300005
using namespace std;
 
typedef unsigned long long ull;
typedef long long ll;
typedef double ld;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<int, ll> pil;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd; 
typedef vector<int> vi;
typedef vector<long> vl;
typedef vector<char> vc;
typedef vector<ll> vll;
typedef vector<bool> vb;
typedef vector<double> vd;
typedef vector<string> vs;
typedef vector<pii> vpii;
typedef vector<pil> vpil;
typedef vector<pli> vpli;
typedef vector<pll> vpll;
const long long INF64 = 1'000'000'000'000'000'000ll;
clock_t time_p=clock();
void time()
{
    time_p=clock()-time_p;
    cerr<<"Time Taken : "<<(float)(time_p)/CLOCKS_PER_SEC<<"\n";
}
void doc()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
}
void fast()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
}
int main()
{
	fast();
	ll i,n;
	cin>>n;
	vll a(n);
	rep(i,n)
		cin>>a[i];
	sort(all(a));
	ll t1=0,t2=0;
	for(i=0;i<n;i++)
	{
		if(i<n/2)
			t1+=a[i];
		else
			t2+=a[i];
	}
	cout<<t1*t1+t2*t2;

}