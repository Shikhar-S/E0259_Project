#include <bits/stdc++.h>
#define pb push_back
#define F first
#define S second
#define all(x) x.begin(), x.end()
using namespace std;
typedef long long ll ; 
typedef long double ld ;
typedef pair<ll , ll> pll ;

const ll N = 2e5 + 30 , Mod = 1e9 + 7 ;
const ll SQ = 330 ;

ll a[N] ;
int main () {
    ios::sync_with_stdio(0), cin.tie(0) ;
    ll n ;
    cin >> n ;
    for (int i = 0 ; i < n ; i ++ )cin >> a[i] ;
    sort(a , a + n) ;
    reverse(a , a + n) ;
    ll x = 0 , y = 0;
    for (int i = 0 ; i < (n + 1) / 2 ; i ++) x += a[i] ;
    for (int i = (n + 1) / 2 ; i < n ; i ++) y += a[i] ;
    cout << x * x + y * y << endl;
    
    return (0) ;
}
