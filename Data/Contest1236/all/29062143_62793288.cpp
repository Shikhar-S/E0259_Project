#include <bits/stdc++.h>

#define endl '\n'
#define ll long long int
#define let(x, a) __typeof(a) x(a)
#define all(a) (a).begin(), (a).end()
#define present(c, x) ((c).find(x) != (c).end())
#define tr(v, it) for (let(it, v.begin()); it != v.end(); it++)
#define rtr(v, it) for (let(it, v.rbegin()); it != v.rend(); it++)

#define trace1(x)					cerr << #x << ": " << x << endl;
#define trace2(x, y)				cerr << #x << ": " << x << " | " << #y << ": " << y << endl;
#define trace3(x, y, z)				cerr << #x << ": " << x << " | " << #y << ": " << y << " | " << #z << ": " << z << endl;
#define trace4(a, b, c, d)			cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << endl;
#define trace5(a, b, c, d, e)		cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << " | " << #e << ": " << e << endl;
#define trace6(a, b, c, d, e, f)	cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << " | " << #e << ": " << e << " | " << #f << ": " << f << endl;

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	int n;
	cin>>n;
	if(n%2 == 0) {
		int a=n*n, b=1;
		for(int i=0;i<n;i++) {
			for(int j=0;j<n/2;j++) {
				cout<<a--<<" ";
			}
			for(int j=0;j<n/2;j++) {
				cout<<b++<<" ";
			}
			cout<<endl;
		}
		return 0;
	}
	for(int i=0;i<n;i++) {
		int a=n*n-i;
		for(int j=0;j<n/2+1;j++) {
			cout<<a<<" ";
			a-=n;
		}
		a=1+i;
		for(int j=0;j<n/2;j++) {
			cout<<a<<" ";
			a+=n;
		}
		cout<<endl;
	}
	return 0;
}