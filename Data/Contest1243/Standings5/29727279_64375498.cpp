#include<bits/stdc++.h>
#define mod 1000000007
#define F first
#define S second
#define pb push_back
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()

using namespace std;
typedef long long int ll;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll t=1;
    cin>>t;
    while(t--)
    {
        ll n,i,ans=0;
        cin>>n;
        ll a[n+10];
        for(i=1;i<=n;i++)
            cin>>a[i];
        sort(a+1,a+n+1);
        reverse(a+1,a+n+1);
        for(i=1;i<=n;i++)
            ans=max(ans,min(i,a[i]));
        cout<<ans<<"\n";
    }
    return 0;
}