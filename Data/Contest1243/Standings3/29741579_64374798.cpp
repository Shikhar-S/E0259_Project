#include <bits/stdc++.h>
#define rep(i,s,e) for(int i = s; i < e; i++)
#define test(t) int t; cin >> t; while(t--) 
#define iterate(it,s) for(auto it = s.begin(); it != s.end(); ++it)
#define MOD 1000000007

using namespace std;

typedef vector<int> vi;
typedef pair<int,int> pi;
typedef set<int> si;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout << setprecision(6) << fixed;
  int t;
  cin >> t;
  while(t--) {
    int n;
    cin >> n;
    int a[n];
    rep(i,0,n) cin >> a[i];
    sort(a,a+n);
    int best = 0;
    rep(i,0,n) {
      // cout << a[n-i-1] << " vs " << i+1 << endl;
      if(a[n-i-1] >= i+1) best = i+1;
      else break;
    }
    cout << best << endl;
  }
  return 0;
}

