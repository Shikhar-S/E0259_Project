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
    cin >> n;
    while (n --) {
    	ll a , b ;
    	cin >> a >> b ;
    	ll g = __gcd(a  , b) ;
    	if (g == 1) cout << "Finite\n" ;
    	else cout << "Infinite\n" ;
	}
    return (0) ;
}
