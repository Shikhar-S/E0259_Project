#define _USE_MATH_DEFINES
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
//#include <unordered_map>
#include <set>
#include <cmath>
#include <cstdio>
#include <map>
#include <queue>
#include <bitset>
#include <stack>
#define speed ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define ll long long
#define eps 1e-9
using namespace std;


//inline int FastI() {
//	char c = ' '; int a = 0;
//	while (!isdigit(c)) c = getchar_unlocked();
//	while (isdigit(c)) {
//		a *= 10;
//		a += c - '0';
//		c = getchar_unlocked();
//	}
//	return a;
//}
//
//inline void FastO(int val) {
//	bool c = 0;
//	for (int i = 1000000000; i >= 1; i /= 10) {
//		if (val / i) {
//			c = 1;
//			fputc_unlocked(val / i + '0', stdout);
//			val %= i;
//		}
//		else if (c) fputc_unlocked('0', stdout);
//	}
//	if (!c) fputc_unlocked('0', stdout);
//}
//
//inline void FastO(long long val) {
//	bool c = 0;
//	for (long long i = 1000000000000000000; i >= 1; i /= 10) {
//		if (val / i) {
//			c = 1;
//			fputc_unlocked(val / i + '0', stdout);
//			val %= i;
//		}
//		else if (c) fputc_unlocked('0', stdout);
//	}
//	if (!c) fputc_unlocked('0', stdout);
//}


const int MAX_N = 1e5 + 10;
const int MAX_M = 1e5 + 10;
const long long INF = 1e18;
const long long MOD = 1e9 + 7;


void solve()
{
	int n;
	scanf("%d", &n);
	vector <long long> a(n, 0);
	for (int i = 0; i < n; i++)
		scanf("%lld", &a[i]);
	sort(a.begin(), a.end());
	long long x = 0, y = 0;
	for (int i = 0; i < n; i++)
	{
		if (i < n / 2)
			x += a[i];
		else
			y += a[i];
	}
	printf("%lld", x * x + y * y);
}


void multitest()
{
	int t;
	scanf("%d", &t);
	for (int i = 0; i < t; i++)
		solve();
}

int main()
{
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	solve();
	//multitest();
}