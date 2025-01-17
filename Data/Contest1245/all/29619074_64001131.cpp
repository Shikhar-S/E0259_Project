#include <iostream>
#include <algorithm>

using namespace std;

int gcd(int a, int b) {
	if (b == 0) return a;
	return gcd(b, a % b);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	while (t--) {
		int a, b;
		cin >> a >> b;
		if (gcd(a, b) == 1) {
			cout << "Finite\n";
		}
		else {
			cout << "Infinite\n";
		}
	}
}