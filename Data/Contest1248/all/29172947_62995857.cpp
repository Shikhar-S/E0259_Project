#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <list>
#include <map>
#include <string>
#include <cstring>
#include <stack>
#include <queue>
#include <cmath>
#include <ctime>
#include <bitset>
//#include <utility>
//#include <complex>
#include <assert.h>
//#include <limits.h>
//#include <iomanip>
//#include <unordered_map>
//#include <unordered_set>
//#include <bits/stdc++.h>
using namespace std;

#define rank rankk
#define mp make_pair
#define pb push_back
#define eb push_back
//#define eb emplace_back
#define xo(a,b) ((b)&1?(a):0)
#define fi first
#define se second
#define tm tmp
//#define LL ll
typedef unsigned long long ull;
typedef unsigned int ui;
typedef pair<int,int> pii;
typedef long long ll;
typedef pair<ll,int> pli;
typedef pair<int,ll>pil;
typedef pair<ll,ll> pll;
typedef pair<double,int> pdi;
typedef long double ld;
const int INF=0x3f3f3f3f;
const ll INFF=1e16;
//const ll INFF=0x3f3f3f3f3f3f3f3fll;
const int MAX=5e5+5;
const int MOD=1e9+7;
//const ll MOD=(ll)998244353;
ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
template<typename T>inline T abs(T a) {return a>0?a:-a;}
template<class T> inline
void read(T& num) {
    bool start=false,neg=false;
    char c;
    num=0;
    while((c=getchar())!=EOF) {
        if(c=='-') start=neg=true;
        else if(c>='0' && c<='9') {
            start=true;
            num=num*10+c-'0';
        } else if(start) break;
    }
    if(neg) num=-num;
}
inline ll powMM(ll a,ll b,ll M){
    ll ret=1;
    a%=M;
    while (b){
        if (b&1) ret=1LL*ret*a%M;
        b>>=1;
        a=1LL*a*a%M;
    }
    return ret;
}
namespace{
template<class T> inline int add(int x,T y){x+=y;if(x>=MOD)x-=MOD;return x;}
template<class T> inline void addi(int &x,T y){x+=y;if(x>=MOD)x-=MOD;}
template<class T> inline int mul(int x,T y){return 1LL*x*y%MOD;}
template<class T> inline void muli(int &x,T y){x=1LL*x*y%MOD;}
template<class T> inline int sub(int x,T y){int res=x-y;if(res<0)res+=MOD;return res;}
template<class T> inline void subi(int &x,T y){x-=y;if(x<0)x+=MOD;x%=MOD;}
template<class T> inline int half(int x){return x&1?(x+MOD)>>1:x>>1;}
//ll mul(ll a , ll b,ll Q){
//    return (a * b - (ll) ((long double)a * b / Q) * Q) % Q;
//}
}
//#define debug
//clock_t t1 = clock();
//fprintf(stderr, "%ld ms\n", clock() - t1);


char a[MAX];
int n;
pii ans;
int anval;
int dp[MAX];
int stk[MAX],top,st;
int cal(){
    int re=0;
    for(int i=1;i<=n;i++){
        if(a[i]=='(')dp[i]=dp[i+n]=1;
        else dp[i]=dp[i+n]=-1;
    }
    for(int i=1;i<=n+n;i++)dp[i]+=dp[i-1];
    if(dp[n]!=0)return 0;
    top=0;st=1;
    for(int i=1;i<=n;i++){
        while(top>=st&&dp[stk[top]]>=dp[i])--top;
//        if(!top)st=1;
        stk[++top]=i;
    }
//    if(dp[stk[st]]>=0)++re;
    for(int i=n+1;i<=n+n;i++){
        if(stk[st]==i-n)++st;
        while(top>=st&&dp[stk[top]]>=dp[i])--top;
        stk[++top]=i;
        if(dp[stk[st]]>=dp[i-n])++re;
//        if(stk[top]==dp[i-n])--top;
    }
    return re;
//    for(int i=1;i<=n;i++)
}
int main(){
    scanf("%d",&n);
    scanf("%s",a+1);
    for(int i=1;i<=n;i++)
        for(int j=i+1;j<=n;j++){
            swap(a[i],a[j]);
            int val=cal();
            if(val>anval)
                anval=val,ans=mp(i,j);
            swap(a[i],a[j]);
        }
    printf("%d\n",anval);
    if(anval==0)ans.fi=ans.se=1;
    printf("%d %d\n",ans.fi,ans.se);
    return 0;
}
/*
3
7
3 1 6 6 3 1 1
8
1 1 4 4 4 7 8 8
7
4 2 5 2 6 2 7




*/
