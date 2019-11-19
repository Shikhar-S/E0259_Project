//#pragma GCC optimize("O3")
#include<algorithm>
#include<array>
#include<bitset>
#include<cassert>
#include<climits>
#include<cmath>
#include<cstdio>
#include<deque>
#include<iomanip>
#include<iostream>
#include<map>
#include<numeric>
#include<queue>
#include<set>
#include<sstream>
#include<stack>
#include<unordered_map>
#include<unordered_set>
#include<vector>
using namespace std;

template<class T1,class T2>
ostream& operator << (ostream& out,pair<T1,T2> p)
{
    out<<'('<<p.first<<','<<p.second<<')';
    return out;
}

template<class T1,class T2>
istream& operator >> (istream& in,pair<T1,T2> &p)
{
    in>>p.first>>p.second;
    return in;
}

template<class T>
istream& operator >> (istream& in,vector<T> &v)
{
    for(auto &x:v)
        in>>x;
    return in;
}

template<class T>
ostream& operator << (ostream& out,vector<vector<T>> &v)
{
    for(auto &x:v)
        out<<x<<'\n';
    return out;
}

template<class T>
ostream& operator << (ostream& out,vector<T> &v)
{
    for(auto x:v)
        out<<x<<' ';
    return out;
}

long long gcd(long long a,long long b)
{
    if(b>a) swap(a,b);
    return (b?gcd(b,a%b):a);
}

#define ll         long long
#define ull        unsigned long long
#define pii        pair<int,int>
#define pll        pair<long long,long long>
#define tiii       pair< pair<int,int>,int >
#define vb         vector<bool>
#define vi         vector<int>
#define vl         vector<long long>
#define vvi        vector<vector<int>>
#define vvl        vector<vector<long long>>
#define First      first.first
#define Second     first.second
#define Third      second
#define pb         push_back
#define mp         make_pair
#define rep(i,a,b) for(register int i=a;i<b;i++)
#define all(x)     x.begin(),x.end()
#define lbnd       lower_bound
#define ubnd       upper_bound
#define acc        accumulate
#define F          first
#define S          second
#define throwex    throw("Found the error.");

#define h          1000000007

const long double pi=2*asin(1);

signed main()
{
    ios::sync_with_stdio(0);
    #ifdef ONLINE_JUDGE
    cin.tie(0);
    cout.tie(0);
    cerr.setstate(ios::failbit);
    #endif

    int n;
    cin>>n;
    vl v(n);
    cin>>v;
    sort(all(v));
    ll a=0, b=0;
    rep(i,0,n/2)
        a+=v[i];
    rep(i,n/2,n)
        b+=v[i];
    cout<<a*a+b*b;
}
