#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file 
#include <ext/pb_ds/tree_policy.hpp> 
#include <functional> // for less 
#define pb push_back
#define For(i,s,e) for (ll i=(s); i<(e); i++)
#define Debug_array(a,n) for (ll i=(0); i<(n); i++) cout<<a[i]<<" "
#define Foe(i,s,e) for (ll i=(s); i<=(e); i++)
#define Fod(i,s,e) for (ll i=(s)-1; i>=(e); i--)
#define pii pair<ll,ll>
#define fi first
#define se second
#define endl "\n"
#define mp make_pair
#define big_prime 15486277
#define bigger_prime 179424697
#define biggest_prime 32416188691
//#define random_shuffle(indices.begin(), indices.end());
//std::random_device rd;
//std::mt19937 g(rd());
//std::shuffle(v.begin(), v.end(), g);
using namespace __gnu_pbds; 
using namespace std;
template <class T> ostream& operator << (ostream &os, const vector<T> &v) { for (T i : v) os << i << ' '; return os; }
template <class T> ostream& operator << (ostream &os, const set<T> &v) { for (T i : v) os << i << ' '; return os; }
template <class T, class S> ostream& operator << (ostream &os, const pair<T, S> &v) { os << v.first << ' ' << v.second; return os; }
// template <class T, class S> ostream& operator << (ostream &os, const unordered_map<T, S> &v) { for (auto i : v) os << '(' << i.first << "=>" << i.second << ')' << ' '; return os; }
 
#ifndef ONLINE_JUDGE
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
    template <class Arg1> void __f(const char* name, Arg1&& arg1) { cerr << name << " : " << arg1 << endl; }
    template <class Arg1, class... Args>
    void __f(const char* names, Arg1&& arg1, Args&&... args) {
        const char* sep = strchr(names + 1, ',');
        cerr.write(names, sep - names) << " : " << arg1 << "  ";
        __f(sep + 1, args...);
    }
#else
#define trace(...) 0
#define _CRT_SECURE_NO_WARNINGS
#endif // ifndef ONLINE_JUDGE


typedef long long ll;
typedef tree<ll, null_type, less<ll>, rb_tree_tag,tree_order_statistics_node_update> ordered_set; 

#define Mod 1000000007
#define MAX 100100

ll checker(ll n,ll m){
	ll ans = 0;
	For(mask,0,(1LL<<(n*m))){
		bool a[n][m];
		ll c = 0;
		For(i,0,n) For(j,0,m){
			a[i][j] = ((mask&(1LL<<c))!=0);
			c++;
		}
		pii dir[4] = {{0,1},{1,0},{-1,0},{0,-1}};

		bool ok = 1;
		For(i,0,n) For(j,0,m){
			ll C[2];
			C[0]=0;
			C[1]=0;
			For(t,0,4){
				pii c(i+dir[t].fi,j+dir[t].se);
				if(c.fi>=0 && c.fi<n && c.se>=0 && c.se<m){
					C[a[c.fi][c.se]]++;
				}
			}
			if(C[a[i][j]]>1) ok = 0;
		}
		if(ok) ans++;
	}
	return ans;
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	ll fib[MAX];
	fib[1] = 1;
	fib[2] = 1;
	For(i,3,MAX) fib[i] = (fib[i-1]+fib[i-2])%Mod;
	For(i,1,MAX) fib[i] = (2*fib[i])%Mod;

	ll n,m;cin>>n>>m;

	ll f[MAX];
	f[1]=2;
	For(i,2,MAX) f[i] = (f[i-1]+fib[i-1])%Mod;

	f[1]=f[n];
	For(i,2,MAX) f[i] = (f[i-1]+fib[i-1])%Mod;

	cout<<f[m]<<endl;





























	
}