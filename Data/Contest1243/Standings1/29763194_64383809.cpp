#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn=10005;
int main()
{
    ll n;
    cin>>n;
    ll ans=n;
    for(ll i=2;i*i<=n;i++)
    {
        if(n%i==0)
        {
            ans=__gcd(ans,i);
            ans=__gcd(ans,n/i);
        }
    }
    cout<<ans<<endl;
    return 0;
}
