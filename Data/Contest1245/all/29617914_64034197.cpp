#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int gcd (int a, int b) {return b==0?a:gcd(b,a%b);}

int main() {
	ios::sync_with_stdio(0);
	int t; cin>>t;
	while (t--) {
		int a,b; cin>>a>>b;
		if (gcd(a,b)==1) cout<<"Finite"<<endl;
		else cout<<"Infinite"<<endl;
	}
	return 0;
}