#include <bits/stdc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define V vector
#define PB push_back
#define MP make_pair
#define EB emplace_back
#define ALL(v) (v).begin(), (v).end()
#define debug(x) cerr << #x << " is " << x << endl
#define endl '\n'

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef V<int> vi;

const int INF = 1e9 + 7;

int32_t main()
{
	IO_OP;
	int t;
	cin >> t;
	while(t--) {
		int a, b, c, d, k;
		cin >> a >> b >> c >> d >> k;
		int x = (a+c-1)/c, y = (b+d-1)/d;
		if(x + y > k) cout << -1 << endl;
		else cout << x << " " << y << endl;
	}

}



