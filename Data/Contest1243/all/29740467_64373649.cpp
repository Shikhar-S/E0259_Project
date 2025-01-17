#define _USE_MATH_DEFINES
#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <string>
#include <assert.h>
#include <queue>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <random>
#include <cmath>

//#define ll long long
#define ld long double
//#define mp make_pair
#define pb push_back
#define eb emplace_back
#define int long long
using namespace std;

const int INF = 2e9;
const int MOD = 1e9 + 7;
const int MB = 30;

void go() {
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	sort(a.rbegin(), a.rend());
	int ans = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] >= i + 1) {
			ans = i + 1;
		}
	}
	cout << ans << '\n';
}

void solve() {
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		go();
	}
}

signed main() {
	/*
	freopen("cyclic.in", "r", stdin);
	freopen("cyclic.out", "w", stdout);
	*/
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cout.precision(12);
	solve();
}
