/* monkukui 競技プログラミング用のテンプレート  (ここから) */
#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <deque>
#include <list>
#include <queue>
#include <stack>
#include <vector>
#include <utility>
#include <algorithm>
#include <map>
#include <set>
#include <complex>
#include <cmath>
#include <limits>
#include <climits>
#include <ctime>
#include <cassert>
#include <numeric>
#include <functional>
#include <bitset>

using namespace std;
using lint = long long int;
using ll = long long int;
using lnt = long long int;
using graph = vector<vector<int>>;
using wgraph = vector<vector<pair<int, long long int>>>;
long long int INF = 1001001001001001LL;
int inf = 100100100;
long long int MOD = 1000000007LL;
double PI = 3.1415926535897932;
long long int di[] = {-1, 0, 1, 0, -1, 1, 1, -1};
long long int dj[] = {0, 1, 0, -1, 1, 1, -1, -1};

template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}
inline void yes(){ cout << "yes" << endl; }
inline void Yes(){ cout << "Yes" << endl; }
inline void YES(){ cout << "YES" << endl; }
inline void no(){ cout << "no" << endl; }
inline void No(){ cout << "No" << endl; }
inline void NO(){ cout << "NO" << endl; }
inline void possible(){ cout << "possible" << endl; }
inline void Possible(){ cout << "Possible" << endl; }
inline void POSSIBLE(){ cout << "POSSIBLE" << endl; }
inline void impossible(){ cout << "impossible" << endl; }
inline void Impossible(){ cout << "Impossible" << endl; }
inline void IMPOSSIBLE(){ cout << "IMPOSSIBLE" << endl; }

#define rep(i,n) for(int i = 0; i < (n); i++)
#define rrep(i,n) for(int i = 1; i <= (n); i++)
#define drep(i,n) for(int i = (n)-1; i >= 0; i--)
#define srep(i,s,t) for(int i = s; i < t; i++)
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define pb push_back

/* monkukui 競技プログラミング用のテンプレート (ここまで)*/

int main(){
  
  lint n; cin >> n;
  vector<vector<lint>> cost(3, vector<lint> (n));
  for(int i = 0; i < 3; i++) {
    for(int j = 0; j < n; j++) {
      cin >> cost[i][j];
    }
  }

  vector<lint> d(n, 0);
  vector<vector<lint>> g(n);
  for(lint i = 0; i < n - 1; i++) {
    lint a, b; cin >> a >> b;
    a--;
    b--;
    d[a]++;
    d[b]++;
    g[a].push_back(b);
    g[b].push_back(a);
  }

  int si = 0;
  for(int i = 0; i < n; i++) {
    if(d[i] >= 3) {
      cout << -1 << endl;
      return 0;
    }

    if(d[i] == 1) si = i;
  }

  vector<int> p;
  vector<int> used(n, false);
  int ci = si;
  p.push_back(ci);
  used[ci] = true;
  ci = g[ci][0];
  while(1) {
    p.push_back(ci);
    used[ci] = true;
    if(g[ci].size() == 1) break;
    if(!used[g[ci][0]]) ci = g[ci][0];
    else ci = g[ci][1];
  }

  vector<lint> perm(3);
  perm[0] = 0;
  perm[1] = 1;
  perm[2] = 2;
  
  lint ans = INF;
  vector<lint> ans_vec;
  do{
    lint tmp = 0;
    for(int i = 0; i < n; i++) {
      int node = p[i];
      int color = perm[i % 3];
      tmp += cost[color][node];
    }
    if(ans > tmp) {
      ans = tmp;
      ans_vec = perm;
    }
    
  }while(next_permutation(perm.begin(), perm.end()));

  vector<int> anss(n);
  for(int i = 0; i < n; i++) {
    int node = p[i];
    int color = ans_vec[i % 3];
    anss[node] = color;
  }
  
  cout << ans << endl;
  for(int i = 0; i < n; i++) {
    if(i == n - 1) cout << anss[i] + 1 << endl;
    else cout << anss[i] + 1 << " ";
  }
  
  return 0;
}
