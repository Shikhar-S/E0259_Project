
#include<bits/stdc++.h>
using namespace std;

#define PI acos(-1)
#define hell 1000000007
#define HELL 998244353
#define io ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define fix(n) cout << fixed << setprecision(n)
#define mset(a,n) memset(a,n,sizeof a)
#define rep(i,a,b) for (__typeof((b)) i=(a);i<(b);i++)
#define repp(i,a,b,p) for(__typeof((b)) i=(a);i<(b);i+=p)
#define ren(i,a,b) for(__typeof((a)) i=(a);i>=(b);i--)
#define renn(i,a,b,p) for(__typeof((a) i=(a);i>=(b);i-=p)
#define ADD(a,b,c) ((a)%c+(b)%c)%c
#define SUB(a,b,c) ((a)%c-(b)%c+c)%c
#define MUL(a,b,c) (((a)%c)*((b)%c))%c
#define lbd lower_bound
#define ubd upper_bound
#define ll long long
#define ld long double
#define pb push_back
#define fi first
#define se second
#define vll vector<ll>
#define pll pair<ll,ll>
#define vpll vector<pll>
#define all(v) (v).begin(), (v).end()
#define sz(x) (ll)x.size()
#define endl "\n"
#define out(n) cout<<n<<" "
#define outl(n) cout<<n<<endl
#define line cout<<endl
#define bug(n) {outl(n);return;}
#define N 2505
#define pii pair<int,int>





void solve(){
	ll n;
	cin>>n;
	ll pe=0,po=0,qe=0,qo=0;
	rep(i,0,n){
		ll temp;
		cin>>temp;
		if(temp%2==0)
			pe++;
		else
			po++;
	}
	int m;
	cin>>m;
	rep(i,0,m){
		ll temp;
		cin>>temp;
		if(temp%2==0)
			qe++;
		else
			qo++;
	}
	ll ans=0;
	ans+=pe*qe;
	ans+=po*qo;
	cout<<ans<<endl;

}
void prep(){

}
int main(){
    io;
    ll t=1;
    cin>>t;
    prep();
    fix(12);
    while(t--)
        solve();
    return 0;
}
