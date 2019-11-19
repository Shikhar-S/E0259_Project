#include "bits/stdc++.h"
using namespace std;
 
const int N = 1e5 + 5;

void solve() {
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);

	int n; cin >> n;
	vector<int> v(n);
	for(int i = 0; i < n; ++i) cin >> v[i];
	sort(v.begin(), v.end());
	int l = 0, r = n - 1;
	long long x = 0, y = 0;
	int turn = 0;
	while(l <= r) {
		if(!turn) {
			x += v[r--];
		} else {
			y += v[l++];
		}
		turn ^= 1;
	}
	long long ans = 1LL * x * x + 1LL * y * y;
	cout << ans << endl;
	
}
 
int main() {
	solve();
	return 0;  
}
