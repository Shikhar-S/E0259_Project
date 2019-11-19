#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#include<bits/stdc++.h>
 
using namespace std;
 
#define all(a) a.begin(),a.end()
#define F first
#define S second
#define pb push_back
#define ll long long
#define vi vector<int>
#define pi pair<int,int>
#define mp make_pair
#define int ll
#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 42
#endif
 
const int mod=1e9+7;
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int powz(int a,int b){
	int res=1;
	while(b){
		if(b&1)res=(res*1ll*a)%mod;
		b/=2;
		a=(a*1ll*a)%mod;
	}
	return res;
}
void add(int &a,int b){
	a+=b;
	if(a>=mod){
		a-=mod;
	}
}

int mul(int a,int b){
	return (a*1ll*b)%mod;
}
 
template <typename A, typename B>
istream& operator>>(istream& input,pair<A,B>& x) {
	input>>x.F>>x.S;
	return input;
}
 
template <typename A>
istream& operator>>(istream& input,vector<A>& x) {
	for(auto& i:x)
		input>>i;
	return input;
}
 
template<typename A>
ostream& operator<<(ostream& output,vector<A>& x) {
	for(auto& i:x)
		output<<i<<' ';
	return output;
}

const int N=500002;

void solve(){
	int n;
	cin>>n;
	ll k;
	cin>>k;
	vi a(n);
	cin>>a;
	sort(all(a));
	ll cur=a[n-1]-a[0];
	for(int i=1;i<=(n)/2;i++){
		if(k<=((a[i]-a[i-1])*i)){
			cur-=k/i;
			break;
		}
		cur-=(a[i]-a[i-1]);
		k-=(a[i]-a[i-1])*i;
		if(k<=((a[n-i]-a[n-i-1])*i)){
			cur-=k/i;
			break;
		}
		k-=(a[n-i]-a[n-i-1])*i;
		cur-=(a[n-i]-a[n-i-1]);
		if(cur<0)break;
	}
	cout<<max(0ll,cur);
	
}
 
signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int tc=1;
	//~ cin>>tc;
	for(int _=0;_<tc;_++){
		//~ cout<<"Case #"<<_+1<<": ";
		solve();
		if(_!=tc-1)
		cout<<"\n";
	}
}
