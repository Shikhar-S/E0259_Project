#include <bits/stdc++.h>

using namespace std;

#define ll long long

string con(ll n)
{
    string res = "";
    while(n != 0){
        ll mod = n%2;
        if(mod) res += '1';
        else res += '0';
        n = n/2;
    }
    reverse(res.begin(), res.end());
    return res;
}

string str1, str2;
ll len;
ll dp[35][2][2][2][2];

ll fun(ll pos, ll s1, ll s2, ll b1, ll b2)
{
    if(pos == len) return 1;
    //cout << "HIGH" << endl;
    if(dp[pos][s1][s2][b1][b2] != -1) return dp[pos][s1][s2][b1][b2];
    ll res = 0;
    ll ns1, ns2, nb1, nb2;
    // check 0 0
    ns1 = s1, ns2 = s2, nb1 = b1, nb2 = b2;
    if(str1[pos] == '1') ns1 = 0, ns2 = 0;
    if((str2[pos] == '0') || (nb1 == 0 && nb2 == 0)) res += fun(pos+1, ns1, ns2, nb1, nb2);

    // check 0 1
    ns1 = s1, ns2 = s2, nb1 = b1, nb2 = b2;
    if(str1[pos] == '1') ns1 = 0;
    if(str2[pos] == '0') nb2 = 0;
    if((str1[pos] == '1') || (ns2 == 0)){
        if((str2[pos] == '0') || (nb1 == 0)) res += fun(pos+1, ns1, ns2, nb1, nb2);
    }
    // check 1 0
    ns1 = s1, ns2 = s2, nb1 = b1, nb2 = b2;
    if(str1[pos] == '1') ns2 = 0;
    if(str2[pos] == '0') nb1 = 0;
    if((str1[pos] == '1') || (ns1 == 0)){
        if((str2[pos] == '0') || (nb2 == 0)) res += fun(pos+1, ns1, ns2, nb1, nb2);
    }

    return dp[pos][s1][s2][b1][b2] = res;
}

ll calc(ll l, ll r)
{
    str1 = con(r);
    str2 = con(l);
    while((ll)str2.length() < (ll)str1.length()){
        str2 = "0" + str2;
    }
    len = (ll) str1.length();
    memset(dp, -1, sizeof dp);
    ll ans = fun(0, 1, 1, 1, 1);
    return ans;
}

int main()
{
    ll cases;
    scanf("%lld", &cases);
    while(cases--){
        ll l, r;
        scanf("%lld %lld", &l, &r);
        ll ans = calc(l, r);
        cout << ans << endl;
    }
}