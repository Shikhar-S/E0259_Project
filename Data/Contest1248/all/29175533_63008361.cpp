#include <bits/stdc++.h> 
using namespace std;
#define fl(i,a,b) for(int i=a;i<b;i++)
#define ll long long
#define endl '\n'
#define pb push_back
#define ff first
#define ss second
#define mod 1000000007
#define mx 100005
#define mx2 20
#define inf 1e9
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
ll dp[mx];
int power(ll x,ll y)
{
    
    ll res = 1;
    while(y)
    {
        if(y&1)
            res=res*x%mod;
        y>>=1;
        x=x*x%mod;
    }
    return res;
}
main()
{
	int n,m;
	cin>>n>>m;
	if(n<m)
	swap(n,m);	

	dp[0] = 2;
	dp[1] = 2;
	fl(i,2,n+1)
	{
		dp[i] = (dp[i-1] + dp[i-2])%mod;
	}
	
	//cout<<dp[1]<<endl;
	ll ans = dp[n];
	dp[0] = 2;
	dp[1] = 2;
	fl(i,2,m+1)
	{
		dp[i] = (dp[i-1] + dp[i-2])%mod;
		//cout<<dp[i]<<endl;
	}
	
	cout<<(ans+dp[m]-2+mod)%mod;	
	
}