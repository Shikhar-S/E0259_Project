/*
author: madhav_1999 aka orthodoxparadox
17 October 2019 at 7:25 PM
*/

#include <bits/stdc++.h>
#include <ext/pb_ds/detail/standard_policies.hpp>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

#define dbl long double
#define int ll
#define ll long long
#define pii pair<int, int>
#define len(x) (int) x.size()
#define rev(a) reverse(all(a))
#define oiint ostream_iterator<int>(cout, " ") 
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define endl '\n'
#define all(a) a.begin(), a.end()
#define initialise(a, x) memset(a, x, sizeof(a))
#define onlyunique(v) v.erase(unique(all(v)), v.end()); //only for sorted vector
#define inf 2e18
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize ("O3")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#define _CRT_SECURE_NO_WARNINGS
#ifdef MADHAV
#define dbg(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1){cerr << name << " : " << arg1 << endl;}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args){
	const char* comma = strchr(names + 1, ',');
	cerr.write(names, comma - names) << " : " << arg1 << "  ";
	__f(comma + 1, args...);}
#else
#define dbg(...) 42
#endif
template <typename X> ostream& operator << (ostream& x,const vector<X>& v){for(int i=0;i<v.size();++i) x<<v[i]<<" ";return x;} 
template <typename X> ostream& operator << (ostream& x,const set<X>& v){for(auto it:v) x<<it<<" ";return x;} 
template <typename X, typename Y> ostream& operator << (ostream& x, const pair<X,Y>& v) {x<<v.ff<<" "<<v.ss;return x;} 
template <typename T, typename S> ostream& operator << (ostream& os, const map<T, S>& v) { for (auto it : v) os << it.first << "=>" << it.second << endl; return os; }
typedef tree <int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
struct pair_hash {inline std::size_t operator()(const std::pair<int, int> & v) const {return v.first*31+v.second;}};
const int MOD = 1e9 + 7;

int takemod(int a, int mod = MOD){a%=mod;if(a<0)a+=mod;return a;}

int fast_exp(int base, int expo, int mod = MOD) {
	int res=1;
	while(expo>0) {
		if(expo&1) res=(res*base)%mod;
		base=(base*base)%mod;
		expo>>=1;}
	return res;}

int modinv(int a, int mod = MOD){return takemod(fast_exp(takemod(a), mod-2, mod), mod);}

vector<int> belong[300 + 1];
int check(int a, int b, int n)
{
	int cnt = 0;
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
		{
			if(belong[a][i] > belong[b][j]) cnt++;
		}
	}
	return cnt;
}

void solve()
{
	int n;
	cin >> n;
	vector<int> v;
	for(int i = 1; i <= n; i++)
	{
		v.push_back(i);
	}
	int curj = 1, curej = n*n;
	for(int i = 1; i <= n; i++)
	{
		for(int j = curj; j < curj + n/2; j++)
		{
			belong[i].push_back(j);
		}
		for(int j = curej; j > curej - n/2; j--)
		{
			belong[i].push_back(j);
		}
		curj += n/2;
		curej -= n/2;
	}
	if(n & 1)
	{
		int cur = 1;
		for(int j = curj; j <= curej; j++)
		{
			belong[cur].push_back(j);
			cur++;
		}
	}

	for(int i = 1; i <= n; i++)
	{
		cout << belong[i] << endl;
	}
}

signed main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	#ifdef MADHAV
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	freopen("error.txt", "w", stderr);
	#endif
	clock_t t1, t2;
	t1 = clock();

	int t = 1;
	// cin >> t;
	while(t--)
	{
		solve();
	}
	#ifdef MADHAV
	t2 = clock(); cerr << "time taken: " << (t2-t1)/(dbl)CLOCKS_PER_SEC;
	#endif
	return 0;
}