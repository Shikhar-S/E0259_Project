#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define rep0(a,b) for(int a=0;a<b;a++)
#define rep1(a,b) for(int a=1;a<=b;a++)
#define repp(a,b,c) for(int a=b;a<c;a++)
#define rev(a,b,c) for(int a=b;a>=c;a--)
#define in insert
#define len length()
#define si size()
#define lb lower_bound
#define ub upper_bound
#define beg begin()
#define en end()
#define F first
#define S second
#define pr(a) cout<<a
#define pr2(a,b) cout<<a<<" "<<b<<"\n"
#define get(a) cin>>a
#define nextl cout<<"\n"
#define deb(x) cout<<#x<<"="<<x<<"\n";
const ll mod = 1000000007;
const ll maxn = 500005;
const ll mm = 1e+18;
ll power(ll x, ll y)
{
    ll res = 1;
    x = x % mod;
    while (y > 0)
    {
        if (y & 1)
            res = (res*x) % mod;
        y = y>>1;
        x = (x*x) % mod;
    }
    return res;
}
ll ncr(ll n, ll k)
{
    ll C[k+1];
    memset(C, 0, sizeof(C));

    C[0] = 1;

    for (ll i = 1; i <= n; i++)
    {
        for (ll j = min(i, k); j > 0; j--)
            C[j] = (C[j] + C[j-1])%mod;
    }
    return C[k];
}
void solve()
{
    int n;
    cin>>n;
    int hi[1001]={0};
    rep0(i,n){
        int x;
        cin>>x;
        hi[x]++;
    }
    int ans;
    rev(i,999,1)hi[i]+=hi[i+1];
    rep1(i,1000){
        if(hi[i]>=i) ans=i;
    }
    cout<<ans;
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t=1;
    cin>>t;
    while(t--){
        solve();
        nextl;
    }
    return 0;
}
