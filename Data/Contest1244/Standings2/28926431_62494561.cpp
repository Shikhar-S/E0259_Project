// !FromHere
#include <bits/stdc++.h>

using namespace std;
using namespace __gnu_cxx;

typedef double db;
typedef long long ll;
typedef pair<db, db> pdd;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
typedef unsigned long long ull;

#define F          first
#define S          second
#define pnl        printf("\n")
#define sz(x)      (int)x.size()
#define sf(x)      scanf("%d",&x)
#define pf(x)      printf("%d\n",x)
#define all(x)     x.begin(),x.end()
#define rall(x)    x.rbegin(),x.rend()
#define rep(i, n)  for(int i = 0; i < n; ++i)

const db eps = 1e-9;
const db pi = acos(-1);
const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x3f3f3f3f3f3f3f3f;
const int mod = 1000 * 1000 * 1000 + 7;

int n;
long long k;
ll arr[100005];
ll sL[100005];
ll sR[100005];

bool ok(ll dif) {
    bool can = 0;
    for (int i = 1; i <= n; ++i) {
        ll need = 0;
        // left
        need += (i - 1) * arr[i] - sL[i - 1];
        // right
        int l = i, r = n, mid;
        while (l < r) {
            mid = l + (r - l + 1) / 2;
            if (arr[mid] - arr[i] <= dif) l = mid;
            else r = mid - 1;
        }
        if (l < n)
            need += (sL[n] - sL[l]) - (n - l) * (arr[i] + dif);
        if (need <= k) can = 1;
    }
    for (int i = n; i >= 1; --i) {
        ll need = 0;
        // right
        need += (sL[n] - sL[i]) - (n - i) * arr[i];
        // left
        int l = 1, r = i, mid;
        while (l < r) {
            mid = l + (r - l) / 2;
            if (arr[i] - arr[mid] <= dif) r = mid;
            else l = mid + 1;
        }
        need += (l - 1) * max(0LL, arr[i] - dif) - sL[l - 1];
        if (need <= k) can = 1;
    }
    return can;
}

int main() {
    scanf("%d%lld", &n, &k);
    for (int i = 1; i <= n; ++i)
        scanf("%lld", &arr[i]);
    sort(arr + 1, arr + 1 + n);
    for (int i = 1; i <= n; ++i)
        sL[i] = sL[i - 1] + arr[i];
    for (int i = n; i > 0; --i)
        sR[i] = sR[i + 1] + arr[i];
    ll l = 0, r = 1000000000, mid;
    while (l < r) {
        mid = l + (r - l) / 2;
        if (ok(mid)) r = mid;
        else l = mid + 1;
    }
    cout << l << endl;
    return 0;
}
