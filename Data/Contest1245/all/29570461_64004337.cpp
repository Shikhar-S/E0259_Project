/**
 *     author:     TelmaZzzz
 *     create:     2019-11-01-22.29.19
**/
#include <map>
#include <set>
#include <ctime>
#include <cmath>
#include <queue>
#include <stack>
#include <ctime>
#include <string>
#include <vector>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>
//#include <random>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
void _R(int &x) { scanf("%d", &x); }
void _R(ll &x) { scanf("%lld", &x); }
void _R(db &x) { scanf("%lf", &x); }
void _R(char &x) { scanf(" %c", &x); }
void _R(char *x) { scanf("%s", x+1); }
void R() {}
template<class T, class... U> void R(T &head, U &... tail) { _R(head); R(tail...); }
void _W(const int &x) { printf("%d", x); }
void _W(const ll &x) { printf("%lld", x); }
void _W(const db &x) { printf("%.16f", x); }
void _W(const char &x) { putchar(x); }
void _W(const char *x) { printf("%s", x); }
template<class T> void _W(const vector<T> &x) { for (auto i = x.begin(); i != x.end(); _W(*i++)) if (i != x.cbegin()) putchar(' '); }
void W() {}
template<class T, class... U> void W(const T &head, const U &... tail) { _W(head); putchar(sizeof...(tail) ? ' ' : '\n'); W(tail...); }
#define rep(x,y,z) for(int x=y;x<=z;x++)
#define erp(x,y,z) for(int x=y;x>=z;x--)
#define PB push_back
#define MP make_pair
#define INF 1073741824
#define inf 1152921504606846976
#define pi 3.14159265358979323846
#define Fi first
#define Se second
//#pragma comment(linker,"/STACK:10240000,10240000")
//mt19937 rand_(time(0));
const int N=3e5+7,M=2e6;
const long long mod=1e9+7;
inline int read(){int ret=0;char ch=getchar();bool f=1;for(;!isdigit(ch);ch=getchar()) f^=!(ch^'-');for(;isdigit(ch);ch=getchar()) ret=(ret<<1)+(ret<<3)+ch-48;return f?ret:-ret;}
ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
ll ksm(ll a,ll b,ll mod){int ans=1;while(b){if(b&1) ans=(ans*a)%mod;a=(a*a)%mod;b>>=1;}return ans;}
ll inv2(ll a,ll mod){return ksm(a,mod-2,mod);}//逆元
//int head[N],NEXT[M],ver[M],tot;void link(int u,int v){ver[++tot]=v;NEXT[tot]=head[u];head[u]=tot;}
void TelmaZzzz(){
#ifndef ONLINE_JUDGE
    freopen("1.txt","r",stdin);
#endif
}

char str[N];
ll dp[N];
int main(){
    TelmaZzzz();
    //ios::sync_with_stdio(false);
    R(str);
    int n=strlen(str+1);
    dp[0]=1;
    bool mark=true;
    for(int i=1;i<=n;i++){
        if(str[i]=='m'||str[i]=='w'){
            mark=false;
        }
        if(str[i]=='n'){
            if(str[i-1]=='n'){
                dp[i]=dp[i-1]+dp[i-2];
                dp[i]%=mod;
            }
            else {
                dp[i]=dp[i-1];
            }
        }
        else if(str[i]=='u'){
            if(str[i-1]=='u'){
                dp[i]=dp[i-1]+dp[i-2];
                dp[i]%=mod;
            }
            else {
                dp[i]=dp[i-1];
            }
        }
        else {
            dp[i]=dp[i-1];
        }
    }
    if(mark) W(dp[n]);
    else puts("0");

    //cout << "time: " << (long long)clock() * 1000 / CLOCKS_PER_SEC << " ms" << endl;
    return 0;
}

