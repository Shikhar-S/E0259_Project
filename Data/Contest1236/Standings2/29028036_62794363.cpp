#include <bits/stdc++.h>
using namespace std;
#define sd(x) scanf("%d", &x)
#define sz(v) (int) v.size()
#define pr(v) For(i, 0, sz(v)) {cout<<v[i]<<" ";} cout<<endl;
#define slld(x) scanf("%lld", &x)
#define all(x) x.begin(), x.end()
#define For(i, st, en) for(ll i=st; i<en; i++)
#define tr(x) for(auto it=x.begin(); it!=x.end(); it++)
#define fast std::ios::sync_with_stdio(false);cin.tie(NULL);
#define pb push_back
#define ll long long
#define int long long
#define mp make_pair
#define F first
#define S second
typedef pair<int, int> pii;
#define MOD 1000000007
#define INF 1000000000000000007
#define MAXN 200005

// it's swapnil07 ;)


signed main(){
    fast
    #ifdef SWAPNIL07
        freopen("/home/swapnil/Desktop/c++/input.txt","r",stdin);
        freopen("/home/swapnil/Desktop/c++/output.txt","w",stdout);
    #endif
    int n; cin>>n;
    int v = 1;
    int rows = 0;
    int flag = 0;
    vector<int> vect[n];
    while(rows != n){
        rows++;
        if(!flag){
            For(i, 0, n){
                vect[i].pb(v);
                v++;
            }
        }
        else{
            for(int i=n-1; i>=0; i--){
                vect[i].pb(v);
                v++;
            }
        }
        flag = 1-flag;
    }
    For(i, 0, n){
        for(int j: vect[i]){
            cout<<j<<" ";
        }
        cout<<"\n";
    }
    return 0;
}