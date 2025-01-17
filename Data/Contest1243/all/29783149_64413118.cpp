#include <bits/stdc++.h>

using namespace std;

#define mx 100005
//#define int long long
#define pii pair <int, int>
#define piii pair <int, pii>
#define fi first
#define se second
#define mod 1000000007
#define inf 1e18+19
#define pb push_back
#define si(x) scanf("%lld", &x)
#define mem(ara, x) memset(ara, x, sizeof ara)
#define read() freopen("in.txt", "r", stdin)
#define write() freopen("out.txt", "w", stdout)
#define fst ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

string s, t;
vector <pii> v;

bool ss(int n, int i){
    for(int j=i+1;j<n;j++){
        if(s[j] == s[i]){
            swap(t[i], s[j]);
            v.push_back({j, i});
            return true;
        }
    }
    return false;
}

void ds(int n, int i){
    for(int j=i+1;j<n;j++){
        if(t[j] == s[i]){
            swap(t[j], s[n-1]);
            v.push_back({n-1, j});

            swap(t[i], s[n-1]);
            v.push_back({n-1, i});
            return;
        }
    }
    return;
}

int32_t main(){
    //read();
    fst;
    int k;
    cin >> k;
    while(k--){
        int n;
        int q[2][28];
        mem(q, 0);
        v.clear();

        cin >> n >> s >> t;
        for(int i=0;i<n;i++){
            q[0][s[i]-'a']++;
            q[1][t[i]-'a']++;
        }

        bool f = true;
        for(int i=0;i<26;i++){
            int a = q[0][i];
            int b = q[1][i];
            if((a+b)%2){
                f = false;
                break;
            }
        }

        if(!f){
            cout << "No" << endl;
            continue;
        }
        cout << "Yes" << endl;
        for(int i=0;i<n;i++){
            if(s[i]==t[i]) continue;
            if(ss(n, i)) continue;
            ds(n, i);

        }
        cout << ((int) v.size()) << endl;
        for(auto u: v) cout << u.fi+1 << " " << u.se+1 << endl;

    }
    return 0;
}















