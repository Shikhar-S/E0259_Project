#include <bits/stdc++.h>
using namespace std;

#define trace(...) __f( #__VA_ARGS__ , __VA_ARGS__ )
template <typename Arg1>
void __f( const char* name , Arg1&& arg1 ) {
        cerr << name << " : " << arg1 << "\n";
}
template <typename Arg1, typename... Args>
void __f( const char* na , Arg1&& arg1 , Args&&... args ) {
        const char* c = strchr( na + 1 , ',' );
        cerr.write( na , c - na ) << " : " << arg1 << " , ";
        __f( c + 1 , args... );
}
#define endl "\n"
#define all(V) V.begin(),V.end()
#define Unique(V) sort(all(V)),V.erase(unique(all(V)),V.end())
#define IO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
typedef long long int LL;
typedef pair <int,int> pii;
const int MOD = 1e9 + 7;
const int inf = 1e9;
const double EPS = 1e-9;
const double PI = acos(-1.0);
const long long INF = 1e18;
const int N = 1e5 + 5;

LL BigMod( LL b , LL p , LL mod ) {
        LL res = 1%mod , x = b%mod;
        while( p ) {
                if( p&1 ) res = ( res * x )%mod;
                x = ( x * x )%mod; p >>= 1;
        }
        return res%mod;
}
int main( ) {
        IO;
        #ifdef LOCAL
            //freopen( "input.txt" , "r" , stdin );
        #endif // LOCAL
        LL n , m;
        cin >> n >> m;
        LL x = ( BigMod( 2 , m , MOD ) - 1 + MOD ) %MOD;
        cout << BigMod( x , n , MOD ) << endl;
        return 0;
}








