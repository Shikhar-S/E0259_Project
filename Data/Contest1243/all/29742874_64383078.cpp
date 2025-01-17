#include<bits/stdc++.h>
using namespace std;

typedef long double                 ld;
typedef long long                   ll;
typedef pair<int,int>               pii;
typedef pair<ll,ll>                 pll;
typedef pair<string , string>       pss;

#define all(x)                      (x).begin(),(x).end()
#define Sort(x)                     sort(all((x)))
#define F                           first
#define S                           second
#define sep                         ' '
#define endl                        '\n'
#define file_io                     freopen("input.txt" , "r+" , stdin) ; freopen("output.txt" , "w+" , stdout);
#define fast_io                     ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define error(x)                    cerr << "$$$ " << x << '\n';
#define error2(x,y)                 cerr << "#F : " << x << "      #S : " << y << '\n';
#define kill(x)                     return cout << x << endl , 0;
#define pb                          push_back

const ll MXN = 1e3 + 10;
const ll MXM = 5e2 + 10;
const ll MX5 = 1e5 + 10;
const ll MX6 = 1e6 + 10;
const ll INF = 8e18;
const ld eps = 1e-9;
const ll MOD = 1e9 + 7; //998244353;

ll power(ll a, ll b, ll md) {
    return (!b ? 1 : (b & 1 ? a * power(a * a % md, b / 2, md) % md : power(a * a % md, b / 2, md) % md));
}
ll bmm(ll a,ll b){
    return (a%b==0 ? b : bmm(b,a%b));
}
string base2(ll n){
    string a="";while(n>=2){a+=(char)(n%2+'0');n/=2;}a+=(char)(n+'0');reverse(all(a));return a;
}

ll A[MX5];
ll mr1[200], mr2[200];
vector<ll> v;
int main(){
    //fast_io
    //file_io
    ll q;
    cin >> q;
    while(q--){
        ll n, ans = 0;
        cin >> n;
        string s, t;
        cin >> s >> t;
        fill(mr1, mr1 + 140, 0);
        fill(mr2, mr2 + 140, 0);
        for(int i = 0; i < n; i++) mr1[s[i]]++;
        for(int i = 0; i < n; i++) mr2[t[i]]++;
        v.clear();
        for(int i = 0; i < n; i++){
            if(s[i] != t[i]){
                ans++; v.pb(i);
            }
        }
        bool f  = 0;
        for(int i = 'a' ; i <= 'z' ; i++){
            if(mr1[i] && mr2[i]) f=1;
        }

        if(ans == 0){
            if(f) cout << "YES" << endl;
            else cout << "NO" << endl;
        }
        else if(ans == 2){
            ll ind1 = v[0];
            ll ind2 = v[1];
            ll a1 = s[ind1], a2 = s[ind2];
            ll b1 = t[ind1], b2 = t[ind2];
            if(a1 == a2 && b1 == b2){
                cout << "YES" << endl;
            }
            else{
                cout << "NO" << endl;
            }
        }
        else{
            cout << "NO" << endl;
        }
    }



    return 0;
}
//! N.N
