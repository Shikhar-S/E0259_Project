#include <iostream>
#include <vector>
#include <limits.h>
#include <algorithm>
#include <string>
#include <math.h>
#include <limits.h>
#include <queue>
#include <map>
#include <set>
#include <iomanip>
#include <bitset>
#include <cassert>
#include <random>
#include <functional>
#include <stack>
#include <iomanip>
#include <cassert>
using namespace std;
long long MOD = 1e9 + 7;
typedef long long ll;
typedef pair<ll, ll> pll;

string hands[3] = {
	string("R"),string("P"),string("S")
};

int main() {
	ll T;
	cin >> T;
	for (ll t = 0; t < T; t++) {
		ll N, A, B, C;
		cin >> N >> A >> B >> C;
		string bob;
		cin >> bob;
		ll winnum = 0;
		ll a = A, b = B, c = C;
		vector<ll> ans(N, -1);
		for (ll n = 0; n < N; n++) {
			if (bob[n] == 'R' && b > 0) {
				winnum++;
				ans[n] = 1;
				b--;
			}
			else if (bob[n] == 'P' && c > 0) {
				winnum++;
				ans[n] = 2;
				c--;
			}
			else if (bob[n] == 'S' && a > 0) {
				winnum++;
				ans[n] = 0;
				a--;
			}
		}
		if (winnum < ceil((long double)N / 2)) {
			cout << "NO" << endl;
			continue;
		}
		cout << "YES" << endl;
		for (ll n = 0; n < N; n++) {
			if (ans[n] != -1)cout << hands[ans[n]];
			else if (a > 0) {
				cout << hands[0];
				a--;
			}
			else if (b > 0) {
				cout << hands[1];
				b--;
			}
			else if (c > 0) {
				cout << hands[2];
				c--;
			}
		}
		cout << endl;
	}
	return 0;
}