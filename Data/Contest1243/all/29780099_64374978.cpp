//#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast,no-stack-protector") 
//#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
//#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>


#define ll long long
#define ull unsigned long long
#define int ll
#define ld long double
#define rep(i, l, r) for (int i = l; i < r; i++)
#define repb(i, r, l) for (int i = r; i > l; i--)
#define sz(a) (int)a.size()
#define fi first
#define se second
#define all(x) x.begin(),x.end()
#define pb push_back
#define mp(a, b) make_pair(a, b)
#define ret(a) {cout << a; exit(0);}

using namespace std;

mt19937 mrand(random_device{}()); 
const ll mod=1000000007;
int rnd(int x) { return mrand() % x;}
ll powmod(ll a,ll b,ll mod) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}

typedef pair < int , int > pii ;
typedef pair < long long  , long long > pll ;
const int N = 2e5 + 123;
int n , m, k;
int a[N];
string s;
void solve(){
      cin >> n;
      for(int i = 1; i <= n; i++){
      	int x;
      	cin >> x;
      	a[x]++;
      }
      for(int i = n; i >= 1 ; i--){
      		a[i] += a[i + 1];
      		if(a[i] >= i){
      			cout << i << '\n';
     			for(int i = 1; i <= n;i++)
			      	a[i] = 0;
      			return;
      		}
      }

}

main(){
	ios::sync_with_stdio(0); cin.tie(0);cout.tie(0);
	int t;
	cin >> t;
	while(t--){	
	solve();
	}

}
