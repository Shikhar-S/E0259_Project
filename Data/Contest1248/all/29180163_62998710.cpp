#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ld long double
#define fi first
#define se second
#define pb push_back
#define pii pair<int,int>
#define all(x) (x).begin(), (x).end()
const int MOD = 1e9+7;
int mpow(int a,int b,int p=MOD){a=a%p;int res=1;while(b>0){if(b&1)res=(res*a)%p;a=(a*a)%p;b=b>>1;}return res%p;}
const int N=1e5+2;
int f[N];
int32_t main(){
      ios_base::sync_with_stdio(false);
      cin.tie(NULL);
      #ifndef ONLINE_JUDGE
      freopen("input.txt", "r", stdin);
      // freopen("output.txt","w",stdout);
      #endif
      f[1]=2;
      f[2]=4;
      for(int i=3;i<N;i++) f[i]=(f[i-1]+f[i-2])%MOD;
      int n,m;
      cin>>n>>m;
      // int x=n-3;
      // cout<<mpow(2,x)<<" ";
      cout<<(f[n-1]+f[m]+f[n]-(f[n-1]+f[1]))%MOD<<"\n";
      // int tot=(n*m);
      // int ans=0;
      // for(int ii=0;ii<(1LL<<tot);ii++)
      // {
      //   int a[n][m];
      //   for(int j=0;j<tot;j++)
      //   {
      //     int x;
      //     if(ii&(1LL<<j)) x=1;
      //     else x=0;
      //     a[j/m][j%m]=x;
      //   }
      //   bool f=true;
      //   for(int i=0;i<n;i++)
      //   {
      //     for(int j=0;j<m;j++)
      //     {
      //       int cnt=0;
      //       if(i-1>=0&&a[i-1][j]==a[i][j]) cnt++;
      //       if(i+1<n&&a[i+1][j]==a[i][j]) cnt++;
      //       if(j-1>=0&&a[i][j-1]==a[i][j]) cnt++;
      //       if(j+1<m&&a[i][j+1]==a[i][j]) cnt++;
      //       if(cnt>1) f=false;
      //     }
      //   }
      //   if(f) ans++;
      // }
      // cout<<ans<<"\n";
}
// I never lose. I either win or I learn