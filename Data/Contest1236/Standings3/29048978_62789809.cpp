
#pragma GCC optimize("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
 
 
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>

#include <cmath>
#include <random>
#include <iomanip>
#include <algorithm>
#include <numeric>
#include <functional>
 
#include <vector>
#include <queue>
#include <string>
#include <stack>
#include <set>
#include <map>
#include <deque>
#include <array>
#include <iterator>
#include <bitset>
#include <initializer_list>
 
//#include <ext/rope>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
  
using namespace std;
//using namespace __gnu_cxx;
//using namespace __gnu_pbds;
 
//template<class T, class C = null_type> using Tree = tree<T, C, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update>;
 
namespace io{
 
      template<typename A, typename B> ostream& operator << ( ostream &os, pair<A, B> &p ) { return os << p.first << " " << p.second; }
      template<typename A> ostream& operator << ( ostream &os, vector<A> &v ) { for( A p : v ) cout << p << " "; return os; }
      template<typename A, typename B> ostream& operator << ( ostream &os, vector<pair<A, B>> &v ) { for( auto p : v ) cout << p << endl; return os; }
      template<typename A, typename B> ostream& operator << ( ostream &os, map<A, B> &mp ) { for( auto it : mp ) os << it.first << " " << it.second << endl; return os; }
      template<typename A> ostream& operator << ( ostream &os, set<A> &st ) { for( A p : st ) cout << p << " "; return os; }
 
      template<typename A, typename B> istream& operator >> ( istream &is, pair<A, B> &p ) { return is >> p.first >> p.second; }
      template<typename A> istream& operator >> ( istream &is, vector<A> &v ) { for( A &p : v ) is >> p; return is; }
      template<typename A, typename B> istream& operator >> ( istream &is, vector<pair<A, B>> &v ) { for( auto &p : v ) is >> p.first >> p.second; return is; }
 
      template<typename A, typename B> inline void output( pair<A, B> &p ) { cout << "{" << p.first << ", " << p.second << "}" << endl; }
      template<typename A, typename B> inline void output( map<A, B> &mp ){ cout << endl; for( auto it: mp ) cout << "{" << it.first << ", " << it.second << "}" << endl; }
      template<typename A> inline void output( vector<A> &v ){ cout << "{"; for( int i = 0; i < v.size(); i++ ){ cout << v[i]; if( i < v.size() - 1 ) cout << ", "; } cout << "}"; cout << endl; }
      template<typename A, typename B> inline void output( vector<pair<A, B>> &v ) { cout << endl; for( auto p : v ) cout << "{" << p.first << ", " << p.second << "}" << endl; }
      template<typename A> inline void output( set<A> &st ){ cout << "{"; for( A p : st ){ cout << p; if( p != *st.rbegin() ) cout << ", "; } cout << "}"; cout << endl; }
 
      long long read(){ char c; long long d = 1, x = 0; do c = getchar(); while( c == ' ' || c == '\n' ); if( c == '-' ) c = getchar(), d = -1; while( isdigit( c ) ){ x = x * 10 + c - '0'; c = getchar(); } return d * x;}
 
}

using namespace io;

const int MOD = ( int ) 1e9 + 7; // 998244353
const double EPS = 1e-9;
const double PI = acos ( -1. );
long long llinf = __INT64_MAX__;
int inf = INT_MAX;


#define int long long
#define add push_back
#define rem pop_back
#define F first
#define S second
 

#define ALL( x ) x.begin(), x.end()
#define RALL( x ) x.rbegin(), x.rend()
#define SORT( x ) sort( ALL( x ) )
#define REV( x ) reverse( ALL( x ) )
#define print( x ) cout << #x << " = " << x << endl;
#define write( x ) cout << #x << ": "; output( x ); 


#define forn( i, a, b ) for( int i = a; i <= b; i++ )
#define forv( i, a, b ) for( int i = a; i >= b; i-- )
#define sqr( x ) ( x ) * ( x )
#define gcd( a, b ) __gcd( a, b )
#define lcm( a, b ) ( ( a ) * ( ( b ) / gcd( a, b ) ) )
inline int gcd( int a, int b ) { while( b ) { a %= b; swap( a, b ); } return a; }
 

template<typename T1, typename T2> auto max ( T1 a, T2 b ) { auto max = a > b ? a : b; return max; }
template<typename T1, typename T2> auto min ( T1 a, T2 b ) { auto min = a < b ? a : b; return min; }
 
template<typename T1, typename T2> void updmax ( T1 &a, T2 b ) { a = a > b ? a : b; }
template<typename T1, typename T2> void updmin ( T1 &a, T2 b ) { a = a < b ? a : b; }
 

const int MAXN = ( int ) 1e6 + 10;
const int N = 1001;

static int a[MAXN], b[MAXN];
static int c[N][N];
 
int n, m, k;
string s, t;
 
 int pow_mod( int a, int n )
{
      int res = 1;
      while( n ){
            if( n % 2 ) res = ( res * a ) % MOD;
            a = ( a * a ) % MOD;
            n >>= 1;
      }
      return res;
}
void solution()
{
      int ans = 0;
      int a, b, c;
      cin >> a >> b >> c;
      for( int i = 0; i <= 100; i++ ){
            for( int j = 0; j <= 100; j++ ){
                  if( i <= a && i * 2 + j <= b && 2 * j <= c ){
                        updmax( ans, i + i * 2 + j + 2 * j );
                  }
            }
      }
      cout << ans << endl;
}
 
 
int32_t main ( )
{
 
      int T1 = clock();
 
      //freopen("FILE_NAME.in", "r", stdin);
      //freopen("FILE_NAME.out", "w", stdout);
 
      ios_base::sync_with_stdio ( false ); cin.tie ( nullptr ); cout.tie ( nullptr );
      //cout.precision(15);
 
      int query = 1;
      cin >> query;
 
      while ( query-- ) solution();

      int T2 = clock();

      cerr << "Time: " << ( T2 - T1 ) / 1000. << " s." << endl;
 
      return 0;
 
}