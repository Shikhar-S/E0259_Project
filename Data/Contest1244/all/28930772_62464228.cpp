//Code of C#oder Born_Clear
#include <bits/stdc++.h>
using namespace std;
#define loop(n) for(int i=0;i<n;++i)
#define FORD(i,a,b) for(int i=a;i>=b;--i)
#define pb push_back
#define mp make_pair
#define all(x) x.begin(),x.end()
#define ll long long
#define s(x) scanf("%d", &x)
#define sd(x) scanf("%lf", &x)
#define sl(x) scanf("%lld", &x)
#define mod 1000000007
#define fi first
#define se second
#define p(x) printf("%d",x)
#define pl(x) printf("%lld", x)
#define pd(x) printf("%lf", x)
#define pn() printf("\n")
#define vi(v) vector<int>v
#define vl(v) vector<long long int>v
#define pii pair<int,int>
#define pll pair<long long int,long long int>
#define len(s) s.length()
void input(int n,int a[]){loop(n)cin>>a[i];}
ll bin_expo(ll A, ll B, ll M){ll res = 1LL;while (B > 0){if(B % 2 == 1){res = (res * A) % M;}A = (A * A) % M; B = B / 2;}return res;}

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		ll a,b,c,d,k;
		cin>>a>>b>>c>>d>>k;
		ll x=ceil((double)((a*1.0)/c)),y=ceil((double)((b*1.0)/d));
		if(x+y>k)
		{
			cout<<-1<<endl;
		}
		else
		{
			cout<<x<<" "<<y<<endl;
		}
	}	
	return 0;
}