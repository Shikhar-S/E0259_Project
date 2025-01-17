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
    string s, t;
    cin>>s>>t;
    vector<lli> x;
    lli cnt = 0;
    for(int i = 0; i < n; i ++) {
        if(s[i] != t[i]) {
            cnt ++;
            x.push_back(i);
        }
    }
    if(cnt != 2) {
        cout<<"NO\n";
        return ;
    }
    lli i = x[0], j = x[1];
    string t1, t2;
    t1 = s;
    t2 = t;
    swap(t1[i], t2[j]);
    swap(s[j], t[i]);
    if(t1 == t2 || s == t) {
        cout<<"YES";
    }
    else {
        cout<<"NO";
    }
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
    cin>>t;
    while(t --)
    {
        solve();
    }
    return 0;
}

