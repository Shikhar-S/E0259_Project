#include<bits/stdc++.h>
#pragma GCC optimize ("-O3")
using namespace std;
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define ll long long
#define int long long
#define double long double
#define pb push_back
#define max(a,b) (a>b?a:b)
#define min(a,b) (a<b?a:b)
#define diff(a,b) (a>b?a-b:b-a)
const int N=1e6+5;
void pairsort(int a[], int b[], int n){
    pair<int, int> pairt[n];
    for (int i = 0; i < n; i++) 
    {
        pairt[i].first = a[i];
        pairt[i].second = b[i];
    }
    sort(pairt, pairt + n);
    for (int i = 0; i < n; i++) 
    {
        a[i] = pairt[i].first;
        b[i] = pairt[i].second;
    }
}
int gcd(int a, int b){
    if (b == 0)
        return a;
    return gcd(b, a % b); 
}
int isPrime(int n){
    if(n < 2)
        return 0;
    if(n < 4)
        return 1;
    if(n % 2 == 0 or n % 3 == 0)
        return 0;
    for(int i = 5; i*i <= n; i += 6)
        if(n % i == 0 or n % (i+2) == 0)
            return 0;
    return 1;
}
long long C(int n, int r) {
    if(r>n-r) 
        r=n-r;
    long long ans=1;
    for(int i=1;i<=r;i++){
        ans*=n-r+i;
        ans/=i;
    }
    return ans;
}
int mod = 1e9+7;
int modexpo(int x,int p){
    int res = 1;
    x = x%mod;
    while(p){
        if(p%2)
            res = res * x;
        p >>= 1;
        x = x*x % mod;
        res %= mod;
    }
    return res;
}
int n;
set<int> s;
bitset<1000005> pv;
void sieve()
{
    pv[0]=pv[1]=true;
    for(int i=4;i<N;i+=2)
        pv[i]=true;
    int j;
    for(int i=3;(j=i*i)<N;i+=2)
        if(!pv[i])
            for(;j<N;j+=i+i)
                pv[j]=true;
}
int32_t main()
{
    IOS;
    cin>>n,sieve();
    if(isPrime(n)||n==1)
    {
        cout<<n;
        return 0;
    }
    for(int i=2;i<=sqrt(n)&&s.size()<2;i++)
        if(n%i==0)
        {
            if(!pv[i])
                s.insert(i);
            if(isPrime(n/i))
                s.insert(n/i);
        }
    if(s.size()>=2)
    {
        cout<<1;
        return 0;
    }
    cout<<*s.begin();
    return 0;
}