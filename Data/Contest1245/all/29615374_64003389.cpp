#include <bits/stdc++.h>
#include <unistd.h>
 
using namespace std;
 
typedef long long ll;
typedef pair<ll,ll> P;
 
long long int INF = 3e18;
const ll fact_table = 800000;
double Pi = 3.1415926535897932384626;
 
vector<ll> G[550010];
//vector<P> tree[500010];
priority_queue <ll> pql;
priority_queue <P> pqp;
//big priority queue
priority_queue <ll,vector<ll>,greater<ll> > pqls;
priority_queue <P,vector<P>,greater<P> > pqps;
//small priority queue
//top pop
 
int dx[8]={1,0,-1,0,1,1,-1,-1};
int dy[8]={0,1,0,-1,1,-1,-1,1};
char dir[] = "DRUL";
//ll bit[500005];
//↓,→,↑,←
 
 
#define p(x) cout<<x<<"\n";
#define el cout<<endl;
#define pe(x) cout<<(x)<<" ";
#define ps(x) cout<<fixed<<setprecision(25)<<x<<endl;
#define pu(x) cout<<(x);
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define CLEAR(a) a = decltype(a)(); 
 

//ll mod = 998244353;
ll mod = 1000000007;
 
ll rui(ll number1,ll number2){
 
    if(number2 == 0){
        return 1;
    }else{
        ll number3 = rui(number1,number2 / 2);
        number3 *= number3;
        number3 %= mod;
        if(number2%2==1){
            number3 *= number1;
            number3 %= mod;
        }
        return number3;
    }
}
ll gcd(ll number1,ll number2){
 
    if(number1 > number2){
        swap(number1,number2);
    }
    if(number1 == 0 || number1 == number2){
        return number2;
    }else{
        return gcd(number2 % number1,number1);
    }
}
void YES(bool condition){
 
    if(condition){
        p("YES");
    }else{
        p("NO");
    }
    return;
}
void Yes(bool condition){

    if(condition){
        p("Yes");
    }else{
        p("No");
    }
    return;
}
 

ll fact[fact_table + 5],rfact[fact_table + 5];
 
void c3_init(){
    fact[0] = rfact[0] = 1;
    for(ll i=1; i<=fact_table; i++){
        fact[i] = (fact[i-1]*i) % mod;
    }
    rfact[fact_table] = rui(fact[fact_table],mod - 2);
    for(ll i=fact_table; i>=1; i--){
       rfact[i-1] = rfact[i] * i;
       rfact[i-1] %= mod;
    }
    return;}
ll c3(ll n,ll r){
    return (((fact[n] * rfact[r]) % mod ) * rfact[n-r]) % mod;}

 
ll n,m,num,sum,a,b,c,d,e,g,h,w,i,j,q,r,l;
ll k,ans;
ll x[500005],y[500005],z[500005];
char s[500005];

void solve(){
    cin >> n;
    cin >> a >> b >> c;
    cin >> s;
    ans = 0;
    for(int i=0;i<n;i++){
        if(s[i] == 'S'){
            if(a){
                x[i] = 1;
                ans ++;
                a--;
            }else{
                x[i] = 0;
            }
        }else if(s[i] == 'P'){
            if(c){
                x[i] = 1;
                ans ++;
                c--;
            }else{
                x[i] = 0;
            }
        }else{
            if(b){
                x[i] = 1;
                ans ++;
                b--;
            }else{
                x[i] = 0;
            }
        }
    }
    if(ans >= (n + 1) / 2){
        p("YES");
        for(int i=0;i<n;i++){
            if(x[i]){
                if(s[i] == 'P'){
                    pu("S");
                }else if(s[i] == 'R'){
                    pu("P");
                }else{
                    pu("R");
                }
            }else{
                if(a){
                    pu("R");
                    a--;
                }else if(b){
                    b--;
                    pu("P");
                }else{
                    c--;
                    pu("S");
                }
            }
        }
        el;
    }else{
        p("NO");
    }

}
int main(){
    cin >> q;
    for(int i=0;i<q;i++){
        solve();
    }

    return 0;
    
}









