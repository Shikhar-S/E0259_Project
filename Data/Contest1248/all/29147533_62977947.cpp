#include <bits/stdc++.h>
using namespace std;
#define ll			long long
#define ld			long double
#define go(i,l,r)	for(int i=l;i<=r;i++)
#define rep(i,n)	for(int i=1;i<=n;i++)
#define rep0(i,n)	for(int i=0;i<n;i++)
#define PB			push_back
#define MP			make_pair
#define PII			pair<int,int>
#define VI			vector<int>
#define ALL(x)		(x).begin(),(x).end()
#define put(x)		putchar(x)
#define eoln        put('\n')
#define space		put(' ')
#define int long long
inline int read(){
	int x=0,neg=1;char c=getchar();
	while(!isdigit(c)){
		if(c=='-')	neg=-1;
		c=getchar();
	}
	while(isdigit(c))	x=x*10+c-'0',c=getchar();
	return x*neg;
}
inline void print(int x){
	if(x<0){
		putchar('-');
		print(abs(x));
		return;
	}
	if(x<=9)	putchar(x+'0');
	else{
		print(x/10);
		putchar(x%10+'0');
	}
}
signed main(){
	int T=read();
	while(T--){
		int n=read(),cnt1=0,cnt2=0,cnt3=0,cnt4=0;
		rep(i,n){
			int x=read();
			if(x%2==0)	cnt1++;
			else		cnt2++;
		}
		int m=read();
		rep(i,m){
			int x=read();
			if(x%2==0)	cnt3++;
			else		cnt4++;
		}
		print(cnt1*cnt3+cnt2*cnt4);eoln;
	}
	return 0;
}
