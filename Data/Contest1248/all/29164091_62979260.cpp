/*
   THE DARK NIGHT RISES
I LOVE YOU 72 AND WILL FOREVER DO SO
Patience, Persistence, Perseverance, Passion, Purpose
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;
typedef long double ld;
const int N = 2e5 + 20 ;
#define F first
#define S second
# define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define pb push_back
#define mk make_pair
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define rep(i,a,b) for(ll i=a;i<b;i++)
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vii> vvii;
#define sz(x)       (int)x.size()
const long long int mod=1e9 + 7;
const long double EPS=1e-12;
#define mem( a, val ) memset(a, val, sizeof( a ) )
#define deci( x ) cout<<fixed<<setprecision( x );
#define bitcount( x ) __builtin_popcountll( x )

const int dx[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
const int dy[8] = {-1, 0, 1, 1, 1, 0, -1, -1};

int solve()
{
	ll n , m ,temp;
	cin >> n ;
	ll odd = 0 , even = 0 ;
	ll ans = 0 ;
	rep(i,0,n)
	{
		cin >> temp ;
		odd += (temp%2) ;
		even += (temp%2==0);
	}
	//cout << odd << " " << even << endl ;
	 cin >> m ;
	rep(i,0,m)
	{
		 cin >> temp ;
		if(temp%2)
		{
			ans += odd ;
		}
		else ans += even ;
	}
	cout << ans << '\n';
}
int main()
{
	fast;
	ll t;
	t=1;
	cin>>t;
	while(t--)
	{
		solve();
	}

	return 0;
}
// Patience, Persistence, Perseverance, Passion, Purpose
// I LOVE YOU 72 AND WILL FOREVER DO SO.