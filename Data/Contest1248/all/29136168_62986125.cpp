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

const ll MXN = 5e4 + 10;
const ll MXM = 5e2 + 10;
const ll MX5 = 4e5 + 10;
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
ll A[MX5], B[MX5];

int Main(){
    //fast_io
    //file_io
    ll n,m;
    ll a1=0,b1=0,a2=0,b2=0;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> A[i];
        if(A[i]%2==0){
            a1++;
        }
        else{
            b1++;
        }
    }
    cin >> m;
    for(int i=0;i<m;i++){
        cin >> B[i];
        if(B[i]%2==0){
            a2++;
        }
        else{
            b2++;
        }
    }
    ll ans = 0;
    for(int i =0;i<n;i++){
        if(A[i] % 2 == 0){
            ans += a2;
        }
        else{
            ans += b2;
        }
    }
    cout << ans << endl;
    return 0;
}
int main(){
    ll t;cin >> t;
    while(t--){
        Main();
    }
    return 0;
}
//! N.N
