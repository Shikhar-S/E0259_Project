#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll N = 1e5 + 10, mod = 1e9 + 7;
ll dp[N];

int main() {
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    ll n, m;
    cin >> n >> m;
    dp[1] = 2;
    dp[2] = 4;
    for (ll i = 3; i <= max(n, m); i++) 
        dp[i] = (dp[i - 1] + dp[i - 2]) % mod;
    cout << (dp[n] + dp[m] - 2) % mod << "\n";
    return 0;
}