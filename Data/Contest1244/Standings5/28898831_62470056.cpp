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
		int n, mx = 0;
		string s;
		cin >> n >> s;
		for(int i=0;i<n;i++) {
			if(s[i] == '1') {
				mx = max(mx, max(i+1, n-i));
			}
		}
		if(mx == 0) cout << n << endl;
		else cout << mx * 2 << endl;
	}

}



