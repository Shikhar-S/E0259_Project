#include <bits/stdc++.h>
using namespace std;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

int n;
vector <int> arr;
long long answer;

void In()
{
	cin >> n;
	arr.resize(n);
	for (int i = 0; i < n; i++) cin >> arr[i];
}

void Solve()
{
	sort (arr.rbegin(),arr.rend());
	for (int i = 0; i < n; i++) if (arr[i] < i+1)
	{
		answer = i;
		return;
	}
	answer = n;
}

void Out()
{
	cout << answer << endl;
}

int main()
{__
	int t = 1;
	cin >> t;
	while (t--)
	{
		In();
		Solve();
		Out();
	}
}