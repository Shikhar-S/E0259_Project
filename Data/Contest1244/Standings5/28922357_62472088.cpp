#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>

#include <functional>
#include <utility>
#include <cmath>
#include <algorithm>
#include <cassert>

#include <vector>
#include <set>
#include <queue>
#include <map>
#include <stack>
#include <unordered_map>

#include <string>
#include <iterator>
#include <iomanip>
#include <fstream>

using namespace std;

#define uint unsigned int
#define prll pair<ll,ll>
#define prdd pair<double,double>
#define m_p make_pair
#define ticonst (ll)1337228
#define INF (ll)1e18
#define ll long long

const ll q = 239017;
const ll mod = 1e9 + 7;
const ll mod2 = 1e9 + 13;
const ll MAXN = 3e5 + 100;
const ll MAXM = 310;
const ll L = 26;

void $main()
{
	ll t; cin >> t;
	while (t--)
	{
		ll n; cin >> n;
		string s; cin >> s;

		ll ans = n;
		for (ll i = 1; i <= n; ++i)
		{
			if (s[i - 1] == '1')
				ans = max(ans, max(abs(n - i + 1),i) * 2);
	    }

		cout << ans << '\n';
    }
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#else
	//freopen("wizard.in", "r", stdin);
	//freopen("wizard.out", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	// 🍑🍑🍑 //

	$main();

	return 0;
}

//257593BA