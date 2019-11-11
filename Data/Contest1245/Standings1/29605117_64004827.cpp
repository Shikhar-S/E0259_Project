#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<map>
#include<utility>
#include<set>
#include<stack>
#include<list>
#include<deque>
#include<bitset>
#include<iomanip>
#include<cstring>
#include<sstream>
#include<cstdio>
#include<cstdlib>
#include<climits>
#include<cmath>
#include<cctype>


#define pb push_back
#define mp make_pair
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define ren(i,a,b) for(int i=a;i>=b;i--)
#define ff first
#define ss second
#define pll pair<long long int,long long int>
#define pii pair<int,int>
#define vll vector<long long int>
#define vii vector<int>
#define gi(n) scanf("%d",&n)
#define gll(n) scanf("%lld",&n)
#define gstr(n) scanf("%s",n)
#define gl(n) cin >> n
#define oi(n) printf("%d",n)
#define oll(n) printf("%lld",n)
#define ostr(n) printf("%s",n)
#define ol(n) cout << n
#define os cout<<" "
#define on cout<<"\n"
#define o2(a,b) cout<<a<<" "<<b
#define all(n) n.begin(),n.end()
#define present(s,x) (s.find(x) != s.end())
#define cpresent(s,x) (find(all(s),x) != s.end())
#define tr(container, it) for(__typeof(container.begin()) it = container.begin(); it != container.end(); it++)
using namespace std;

typedef unsigned long long int ull;
typedef long long int ll;
typedef long double ld;
typedef vector<vector<ll> > mat;
const int N=2e5+5;
ll f[N],m=1e9+7;

int main()
{ios_base::sync_with_stdio(false);
string s;
cin>>s;
int n=s.length();
rep(i,0,n-1)
{
	if(s[i]=='m'||s[i]=='w')
	{
		ol("0");
		return 0;
	}
}

f[1]=1;
f[2]=2;
rep(i,3,N-1)
{
	f[i]=(f[i-1]+f[i-2])%m;
}
ll ans=1,cnt=1;
rep(i,1,n-1)
{
	if(s[i]==s[i-1]&&(s[i]=='n'||s[i]=='u'))
	{
		cnt++;
	}
	else
	{
		ans=(ans*f[cnt])%m;
		cnt=1;
	}
}
ans=(ans*f[cnt])%m;
ol(ans);
return 0;
}


