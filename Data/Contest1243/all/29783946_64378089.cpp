#pragma GCC optimize("03")
#pragma GCC target("avx2")

#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <utility>
#include <unordered_map>
#include <unordered_set>
#define mp make_pair
#define pb push_back
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define sqr(a) (a)*(a)
#define um unordered_map 
#define us unordered_set
using namespace std;

hash<string> hfn;
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<ld,ld> pld;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef double dbl;
typedef unsigned int ui;
const int inf = 1e9;
const ll mod = 1e9 + 7;
const ld eps = 1e-7;
const ll biginf = 1e18;

void solve()
{
  int n;
  cin >> n;
  string s, t;
  cin >> s >> t;
  int ind = -1;
  bool made = false;
  for(int i = 0; i < n; i++)
  {
    if(s[i] != t[i])
    {
      if(made)
      {
        cout << "No" << endl;
        return;
      }
      if(ind == -1)
      {
        ind = i;
        continue;
      }
      else
      {
        if(s[ind] == s[i] && t[ind] == t[i])
        {
          made = true;
          continue;
        }
        else
        {
          cout << "No" << endl;
          return;
        }
      }
    }
  }
  if(ind != -1 && !made)
    cout << "No" << endl;
  else
    cout << "Yes" << endl;
}

void multisolve()
{
  int t;
  cin >> t;
  while(t--)
    solve();
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  //freopen("points.in", "r", stdin);
  //freopen("points.out", "w", stdout);
  //solve();
  multisolve();
}