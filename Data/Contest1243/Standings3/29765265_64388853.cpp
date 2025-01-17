#include <iostream>
#include <iomanip>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <map>
#include<unordered_map>
#include <set>
#include <queue>
#include <stack>
#include <vector>
#include<bitset>
#include<deque>
#include<string>
#include<list>
#include<iterator>
#include<sstream>
#include <algorithm>
# include <math.h>
#define lli long long int
#define lower(a) transform(a.begin(),a.end(),a.begin(),::tolower);

using namespace std;

const int N = 3e5 + 500;
const long long mod = 1e9 + 7;
const long long cmod = 998244353 ;
const long long inf = 1LL << 61;
const int M = 1e6 + 500;
const lli ths = 1LL << 40;
const int NN = 5e3 + 6;


void solve()
{
    lli n;
    cin>>n;
    lli x = n;
    for(int i = 2; i <= sqrt(n); i ++) {
        if(n % i == 0) {
            x = __gcd(x, i * 1ll);
            if(n / i != i){
                lli t = n / i;
                x = __gcd(x, t);
            }
           // cout<<i<<'\n';
            //return ;
        }
    }
    cout<<x;
    cout<<'\n';
    return ;
}

/*
*/

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    t = 1;
//    cin>>t;
    while(t --)
    {
        solve();
    }
    return 0;
}

