

#include<bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
//using namespace __gnu_pbds;
//typedef tree<LL, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
#define LL                  long long
#define ull                 unsigned long long
#define scl(n)              scanf("%lld", &n)
#define scf(n)              scanf("%lf", &n)
#define sci(n)              scanf("%d", &n)
#define scii(n,m)           scanf("%d %d",&n,&m)
#define sciii(n,m,p)        scanf("%d %d %d",&n,&m,&p)
#define scs(n)              scanf("%s", n)
#define pfi(n)              printf("%d\n",n)
#define pfl(n)              printf("%I64\n",n)
#define pfs(s)              printf("%s\n",s)
#define dist2D(x1,y1,x2,y2)         ((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2))
#define dist3D(x1,y1,z1,x2,y2,z2)   ((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2)+(z1-z2)*(z1-z2))

#define	deb(x)		        cout<<#x<<" "<<x<<endl

#define FASTREAD            ios_base::sync_with_stdio(0);cin.tie(nullptr);
#define MOD                 1000000007
#define MODP                99999999999973LL
#define pb                  push_back
#define mp                  make_pair
#define pp                  pair<LL,LL>
#define memo(a,b)           memset(a,b,sizeof(a))
#define INF                 1e18
#define EPS                 1e-8
#define Pi                  acos(-1.0)
//int Set(int mask,int pos){return mask=mask | (1<<pos);}
//int reset(int mask,int pos){return mask= mask & ~(1<<pos);}
//bool check(int mask,int pos){return (bool)(mask & (1<<pos));}
//LL bigmod(LL b, LL p, LL md){if(p==0) return 1;if(p%2==1){ return ((b%md)*bigmod(b,p-1,md))%md;} else {LL y=bigmod(b,p/2,md);return (y*y)%md;}}

#define N 200005


int main()
{
   int T;
   cin>>T;

   while(T--)
   {
       int n;
       cin>>n;

       string s,t;
       cin>>s>>t;

       int flag=0;
       char a,b;
       bool ok=true;

       int cnt=0;
       for(int i=0;i<n;i++)
       {
           if(s[i]!=t[i])
           {
               cnt++;
               if(flag)
               {
                   if(s[i]!=a || t[i]!=b)
                   {
                       ok=false;
                       break;
                   }
               }
               else
               {
                   flag=1;
                   a=s[i];
                   b=t[i];
               }
           }
       }

       if(ok && cnt==2)
        cout<<"YES"<<endl;
       else
        cout<<"NO"<<endl;

   }

    return 0;
}

/* LL dx[] = {1,-1,0,0} , dy[] = {0,0,1,-1}; */ // 4 Direction
/* LL dx[] = {1,-1,0,0,1,1,-1,-1} , dy[] = {0,0,1,-1,1,-1,1,-1}; */ // 8 Direction
/* LL dx[] = {1,-1,1,-1,2,2,-2,-2} , dy[] = {2,2,-2,-2,1,-1,1,-1}; */ // Knight Direction
/* LL dx[] = {2,-2,1,1,-1,-1} , dy[] = {0,0,1,-1,1,-1}; */ // Hexagonal Direction

