/*
@Date    : 2019-10-20 17:00:52
@Author  : Adscn (adscn@qq.com)
@Link    : https://www.cnblogs.com/LLCSBlog
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define IL inline
#define RG register
#define gi geti<int>()
#define gl geti<ll>()
#define gc getchar()
#define File(a) freopen(a".in","r",stdin);freopen(a".out","w",stdout)
template<typename T>IL bool chkmax(T &x,const T &y){return x<y?x=y,1:0;}
template<typename T>IL bool chkmin(T &x,const T &y){return x>y?x=y,1:0;}
template<typename T>
IL T geti()
{
	RG T xi=0;
	RG char ch=gc;
	bool f=0;
	while(!isdigit(ch))ch=='-'?f=1:f,ch=gc;
	while(isdigit(ch))xi=xi*10+ch-48,ch=gc;
	return f?-xi:xi;
}
template<typename T>
IL void pi(T k,char ch=0)
{
	if(k<0)k=-k,putchar('-');
	if(k>=10)pi(k/10);
	putchar(k%10+'0');
	if(ch)putchar(ch);
}
/*
IL unsigned int LOG2(unsigned int x)
{
	unsigned int ret;
	__asm__ __volatile__ ("bsrl %1, %%eax":"=a"(ret):"m"(x));
	return ret;
}
*/
const int N=1e5+7;
int a[N];
int main(void)
{
	#ifndef ONLINE_JUDGE
//	File("");
	#endif
	int n=gi;
	for(int i=1;i<=n;++i)a[i]=gi;
	sort(a+1,a+n+1);
	int ax=0,ay=0;
	if(n&1)ax=a[n],--n;
	for(int i=1;i<=n/2;++i)ay+=a[i];
	for(int i=n/2+1;i<=n;++i)ax+=a[i];
	cout<<1ll*ax*ax+1ll*ay*ay<<endl;
	return 0;
}