//  Mayank Agarwal
//  IIIT Hyderabad



#include<bits/stdc++.h>
using namespace std;
const long long int M = 1000000007; 
#define ll long long int
#define ld double
#define pb push_back
#define mp make_pair
ll power(ll x, ll y,  ll p) 
{ 
    ll res = 1;      
    x = x % p;   
    while (y > 0) 
    { 
        if (y & 1) 
            res = (res*x) % p; 
        y = y>>1;x = (x*x) % p; 
    } return res%p; 
} 
ll modinver(ll a,ll b)
{
    return (power(a,1,M)*power(b,M-2,M))%M;
}
void SieveOfEratosthenes(int n) 
{   
    bool prime[10005]; 
    memset(prime, true, sizeof(prime)); 
  
    for (int p=2; p*p<=n; p++) 
    { 
        if (prime[p] == true) 
        { 
            for (int i=p*p; i<=n; i += p) 
                prime[i] = false; 
        } 
    } 
} 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    ll t;
    cin>>t;
    while(t--)
    {
    	ll a,b,c,d,k;
    	cin>>a>>b>>c>>d>>k;
    	ll ans=0;
    	ll x1,x2;
    	if(a%c==0)
    	{
    		ans+=a/c;
    		x1=a/c;
    	}
    	else
    	{
    		x1=a/c+1;
    		ans+=a/c+1;
    	}
    	if(b%d==0)
    	{
    		x2=b/d;
    		ans+=b/d;
    	}
    	else{
    		x2=b/d+1;
    		ans+=b/d+1;
    	}
    	if(ans<=k)
    	{
    		cout<<x1<<" "<<x2<<'\n';
    	}
    	else
    	{
    		cout<<"-1\n";
    	}
    }
}
