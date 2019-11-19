//AUTHOR : TIRTH JARSANIA
//COLLEGE : DAIICT
 
#include<bits/stdc++.h>
using namespace std;
 
#define bp __builtin_popcountll
#define ll long long int
#define ld long double
#define pb push_back
#define ff first
#define ss second
#define pii pair<ll,ll>
#define precision(x,d) cout<<fixed<<setprecision(d)<<x
#define minQueue priority_queue<pii,vector<pii>,greater<pii> > 
#define maxQueue priority_queue<pii> 
#define FAST ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);

int main()
{
    FAST;
    ll n;
    cin >> n;
    string s;
    cin >> s;
    ll sum = 0;
    for(ll i=0 ; i<n; i++)
    {
        if( s[i] == '(' )  sum++;
        else sum--;
    }
    if( sum != 0 ) return cout << "0\n1 1",0;
    ll id1 = -1;
    ll id2 = -1;
    ll maxi = 0;
    for( ll i=0 ; i < n ; i++ )
    {
        for( ll j = i ; j < n ; j++ )
        {
            swap(s[i],s[j]);
            ll ans = 0;
            ll sum = 0;
            ll mn = 0;
            for(ll k=0 ; k<n ; k++ )
            {
                if( s[k] == '(' ) sum++;
                else sum--;
                mn = min(mn,sum);
            }
            sum = 0;
            for(ll k=0 ; k<n ; k++ )
            {
                if( s[k] == '(' ) sum++;
                else sum--;
                if( sum == mn ) ans++;   
            }
            
            if( ans > maxi )
            {
                maxi = ans;
                id1  = i;
                id2  = j;
            }
            swap(s[i],s[j]);
        }
    }
                   cout << maxi << "\n" << id1+1 << " " << id2+1 << "\n";
}