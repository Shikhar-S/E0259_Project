#include <iostream>
#include <fstream>
#include <numeric>
#include <stdio.h>
#include <cmath>
#include <queue>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <set>
#include <stack>
#include <map>
#include <deque>
#include <bitset>
#include <cstring>
#include <sstream>
 
#define f first
#define s second
#define ll long long
#define ld long double
#define pb push_back
#define all(x) x.begin(),x.end()
#define mp make_pair
#define y0 eto
#define y1 mezhdy
#define y2 nami
#define left extermination
#define right dismemberment
 
using namespace std;
 
typedef pair<int,int> pii;
 
template <class T>void read(vector<T> &a,ll n){T x; a.clear();for(ll i=0;i<n;i++){cin>>x;a.pb(x);}}
template <class T>void write(vector<T> &a){for(T x : a) cout<<x<<" ";cout<<endl;}

const ll mod=1000000007;

ll n,m;

ll bpow(ll a,ll x)
{
    if(!x) return 1;
    if(x&1) return a*bpow(a,x-1)%mod;
    ll b=bpow(a,x/2);
    return b*b%mod;
}

int main()
{
    ios_base::sync_with_stdio(0);
    //freopen("INPUT.txt", "r", stdin);
    cin>>n>>m;
    cout<<bpow((bpow(2,m)-1+mod)%mod,n)<<endl;
    
}
