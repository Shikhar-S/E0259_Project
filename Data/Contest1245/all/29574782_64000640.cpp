// Author : Rutvik Kothari
// Da-iict

#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define int long long
#define ld long double
#define ull unsigned long long
#define pll pair<ll,ll>
#define MS(x, y) memset(x, y, sizeof(x))
#define all(x) x.begin(),x.end()
#define ff first
#define ss second
#define endl "\n"
#define INFL LLONG_MAX
#define pb push_back
#define FIO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

#define trace1(x)                cerr<<#x<<": "<<x<<endl
#define trace2(x, y)             cerr<<#x<<": "<<x<<" | "<<#y<<": "<<y<<endl
#define trace3(x, y, z)          cerr<<#x<<": " <<x<<" | "<<#y<<": "<<y<<" | "<<#z<<": "<<z<<endl
#define trace4(a, b, c, d)       cerr<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<endl
#define trace5(a, b, c, d, e)    cerr<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<" | "<<#e<< ": "<<e<<endl
#define trace6(a, b, c, d, e, f) cerr<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<" | "<<#e<< ": "<<e<<" | "<<#f<<": "<<f<<endl

const ll N = 1e5 + 5;
const ll M = 1e6 + 5;
const ll mod = 1000007;
const ll m1 = 1e9 + 7;
const ll m2 = 1e9 + 9;
const ll p1 = 402653189;
const ll p2 = 1610612741;
const int LN = 21;

ll powermodm(ll x,ll n,ll M){ll result=1;while(n>0){if(n % 2 ==1)result=(result * x)%M;x=(x*x)%M;n=n/2;}return result;}
ll power(ll _a,ll _b){ll _r=1;while(_b){if(_b%2==1)_r=(_r*_a);_b/=2;_a=(_a*_a);}return _r;}
ll gcd(ll a,ll b){if(a==0)return b;return gcd(b%a,a);}
ll lcm(ll a,ll b){return (max(a,b)/gcd(a,b))*min(a,b);}

ll dx[4]={-1,  1,  0,  0};
ll dy[4]={ 0,  0,  1, -1};

ll pw[LN],fact[N],invfact[N];

void pre()
{
    fact[0]=1;
    for(int i=0;i<LN;i++)pw[i]=power(2,i);
    for(int i=1;i<N;i++)fact[i]=(i*fact[i-1])%mod;
    for(int i=0;i<N;i++)invfact[i]=powermodm(fact[i],mod-2,mod);
}


int32_t main()
{
    FIO;
    //pre();

    ll i,j;
    
    ll t;
    cin>>t;
    
    while(t--)
    {
        ll n;
        cin>>n;
        
        ll r,p,s;
        cin>>r>>p>>s;
        
        string str;
        cin>>str;
        
        ll r1=0,p1=0,s1=0;
        
        for(i=0;i<n;i++)
        {
            if(str[i] == 'R')r1++;
            if(str[i] == 'P')p1++;
            if(str[i] == 'S')s1++;
        }
        
        ll ans = min(r1,p) + min(p1,s) + min(s1,r);
        
        if(2*ans >= n)
        {
            cout<<"YES\n";
            
            bool visited[n];
            MS(visited,false);
            char tans[n+5];
            
            for(i=0;i<n;i++)
            {
                if(str[i] == 'R' && p)
                {
                    visited[i] = true;
                    p--;
                    tans[i] = 'P';
                }
                if(str[i] == 'P' && s)
                {
                    visited[i] = true;
                    s--;
                    tans[i] = 'S';
                }
                if(str[i] == 'S' && r)
                {
                    visited[i] = true;
                    r--;
                    tans[i] = 'R';
                }
            }
            
            for(i=0;i<n;i++)
            {
                if(!visited[i])
                {
                    visited[i] = true;
                    
                    if(r)
                    {
                        tans[i] = 'R';
                        r--;
                    }
                    else if(s)
                    {
                        tans[i] = 'S';
                        s--;
                    }
                    else
                    {
                        tans[i] = 'P';
                        p--;
                    }
                }
            }
            for(i=0;i<n;i++)
                cout<<tans[i];
            cout<<"\n";
        }
        else
            cout<<"NO\n";
    }
    
    return 0;
}