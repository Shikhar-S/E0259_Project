#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <string>
#include <vector>
#include <queue>
#include <cmath>
#include <ctime>
#include <map>
#include <set>
#define MEM(x,y) memset ( x , y , sizeof ( x ) )
#define rep(i,a,b) for (int i = (a) ; i <= (b) ; ++ i)
#define per(i,a,b) for (int i = (a) ; i >= (b) ; -- i)
#define pii pair < int , int >
#define one first
#define two second
#define rint read<int>
#define int long long
#define pb push_back
#define db double
#define ull unsigned long long
#define lowbit(x) ( x & ( - x ) )

using std::queue ;
using std::set ;
using std::pair ;
using std::max ;
using std::min ;
using std::priority_queue ;
using std::vector ;
using std::swap ;
using std::sort ;
using std::unique ;
using std::greater ;

template < class T >
    inline T read () {
        T x = 0 , f = 1 ; char ch = getchar () ;
        while ( ch < '0' || ch > '9' ) {
            if ( ch == '-' ) f = - 1 ;
            ch = getchar () ;
        }
       while ( ch >= '0' && ch <= '9' ) {
            x = ( x << 3 ) + ( x << 1 ) + ( ch - 48 ) ;
            ch = getchar () ;
       }
       return f * x ;
}

int T , a , b , c , d , k ;

signed main (int argc , char * argv[]) {
    T = rint () ;
    while ( T -- ) {
        a = rint () ; b = rint () ; c = rint () ; d = rint () ; k = rint () ;
        int res = ceil ( (db) a / c ) , ans = ceil ( (db) b / d ) ;
        if ( res + ans > k ) puts ("-1") ; else printf ("%lld %lld\n" , res , ans ) ;
    }
    return 0 ;
}