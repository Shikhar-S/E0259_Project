#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<cstdlib>
using namespace std;
#define il inline
#define re register
#define debug printf("Now is Line : %d\n",__LINE__)
#define file(a) freopen(#a".in","r",stdin);freopen(#a".out","w",stdout)
//#define int long long
#define D double
#define inf 123456789
#define mod 1000000007
il int read() {
    re int x = 0, f = 1; re char c = getchar();
    while(c < '0' || c > '9') { if(c == '-') f = -1; c = getchar();}
    while(c >= '0' && c <= '9') x = x * 10 + c - 48, c = getchar();
    return x * f;
}
#define rep(i, s, t) for(re int i = s; i <= t; ++ i)
#define drep(i, s, t) for(re int i = t; i >= s; -- i)
#define Next(i, u) for(re int i = head[u]; i; i = e[i].next)
#define mem(k, p) memset(k, p, sizeof(k))
#define lb(x) (x)&(-(x))
#define ls k * 2
#define rs k * 2 + 1
#define maxn 305
int n, m, a[maxn][maxn], cnt;
int main() {
	n = read();
	rep(i, 1, n) {
		if(i & 1) rep(j, 1, n) a[j][i] = ++ cnt;
		else drep(j, 1, n) a[j][i] = ++ cnt;
	}
	rep(i, 1, n) {
		rep(j, 1, n) {
			printf("%d ", a[i][j]);
		}
		puts("");
	}
	return 0;
}

