#pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;
using namespace __gnu_cxx;


#define f first
#define s second
#define sz(x) (int)(x).size()
#define em empty()
#define pb push_back
#define eb emplace_back
#define pf push_front
#define mem(a,b,s) for(int i=0 ; i<=s ; ++i) a[i]=b;
#define mem2(a,r,c,b) for(int i=0 ; i<=r ; ++i)    for(int j=0 ; j<=c ; ++j)    a[i][j]=b;
#define all(a) a.begin(),a.end()
#define rall(a)	a.rbegin(),a.rend()
#define mp make_pair
#define in insert
#define sc(x) scanf("%d",&(x))
#define scl(a)	scanf("%lld",&a)
#define sc2(a,b)	scanf("%d%d",&a,&b)
#define rep(x,a,b)	for(auto x=a ; x<=b ; ++x)
#define irep(x,a,b)	for(auto x=a ; x>=b ; --x)
#define X real()
#define Y imag()
#define vec(a,b) ((b)-(a))
#define polar(r,t) ((r)*exp(point(0,(t))))
#define angle(v) (atan2((v).Y,(v).X))
#define length(v) ((long double)hypot((v).Y,(v).X))
#define lengthSqr(v) (dot(v,v))
#define dot(a,b) ((conj(a)*(b)).real())
#define cross(a,b) ((conj(a)*(b)).imag())
#define rotate(v,t) (polar(v,t))
#define rotateabout(v,t,a)  (rotate(vec(a,v),t)+(a))
#define reflect(p,m) ((conj((p)/(m)))*(m))
#define normalize(p) ((p)/length(p))
#define same(a,b) (lengthSqr(vec(a,b))<EPS)
#define mid(a,b) (((a)+(b))/point(2,0))
#define perp(a) (point(-(a).Y,(a).X))
#define colliner pointOnLine
#define debug(x)	cerr << #x << " is " << x << endl;

typedef unsigned long long ull;
typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<pair<int,int> > vii;
typedef set<int> si;
typedef set<pair<int,int> > sii;
typedef map<int,int>	mii;
typedef pair<int,char>	ic;
typedef pair<int,string> is;
typedef long double ld;
typedef priority_queue<ii> pqii;
typedef priority_queue<int>pqi;
typedef complex<long double> point;
typedef string BIGINT;

const long double pi=acos(-1);
const long double EPS = 1e-9;
const int MAXN=1e5+10;
const ll MOD=1e9+7;
const int oo=2e9+10;
const ll OO=1e18;

int dx[]={0,1,0,-1,-1,-1,1,1};
int dy[]={1,0,-1,0,-1,1,-1,1};

ll n,g;


int main()
{
//	srand(time(0));
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
//	cout.tie(NULL);
#ifndef ONLINE_JUDGE
 	freopen("In.txt","r",stdin);
//	freopen("Out.txt","w",stdout);
#else
//	freopen("stations.in","r",stdin);
//	freopen("output.txt","w",stdout);
#endif

 	scanf("%lld",&n);
 	if(n==1)	g=1;
	for(ll i=2ll ; i*i<=n ; ++i)
		if(n%i==0ll)
		{
			g=__gcd(g,i);
			while(n%i==0)	n/=i;
		}
	if(n!=1)	g=__gcd(g,n);
	printf("%lld\n",g);
}
