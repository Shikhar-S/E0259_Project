#include<bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int k;
	cin >> k;
	while (k--) {
		int n;
		cin >> n;
		vector<int> a(n);
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		sort(a.rbegin(), a.rend());
		int ans = 0;
		for (int i = 0; i < n; i++) {
			ans = max(ans, min(i + 1, a[i]));
		}
		cout << ans << '\n';
	}
	return 0;
}