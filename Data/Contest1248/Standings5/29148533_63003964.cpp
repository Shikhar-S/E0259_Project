#include <bits/stdc++.h>
using namespace std;

#define F first
#define S second
#define ll long long
#define ld long double
#define vi   vector<int>
#define pii pair<int, int>
#define ull unsigned long long
#define sz(v)  ((int)((v).size()))
#define all(v) ((v).begin()),((v).end())
#define MEM(dp,i) memset(dp ,i, sizeof (dp))
#define repit( cont , i  ) for( auto i : cont)
#define forr(c,x,n)   for(ll c=x;c<=(ll)n; ++c )
#define forrr(c,x,n)  for(ll c=x;c>=( ll )n ;--c )
#define db(x) cout << " LOOK " <<(#x) <<" = " <<  x << '\n'
#define ICPC ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define printarr(a , l , r ) forr ( i , l , r )cout << a[i] << " ";cout<<endl;
#define printarr2(a, n , m) forr ( i , 1 , n){forr ( j , 1, m )cout << a[i][j] << " ";cout<<endl;}

//freopen("input.txt", "r", stdin);
//freopen("output.txt", "w", stdout);


ll mod =  1000000007;
ll ans = 0 ;
ll mem[100007][2];
ll n , m ;
ll dp ( int i , int f , int h  )
{
    if ( i == h )
        return 1 ;
    ll &ret = mem[i][f];
    if ( ~ret)
        return ret;
    ret = 0 ;
    if ( f)
        ret = dp ( i+1 , 0 , h  ) %mod  ;
    else
        ret =  ( dp ( i+1 , 0  , h ) %mod ) + ( dp ( i+1 , 1  , h ) %mod );

    return ret %mod ;
}
int main()
{
ICPC;

cin >> n >> m ;

MEM( mem , -1 );
ans =  2 *   dp ( 1 , 0 , m ) - 2  ;
ans %= mod;
MEM( mem , -1 ) ;
ans += 2 *   dp ( 1 , 0 , n ) ;
ans %= mod ;

cout << ans;
}
