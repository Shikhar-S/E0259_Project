#include<bits/stdc++.h>
using namespace std;

#define fi(i,a,b)    for(long long i=a;i<=b;i++)
#define fr(i,a)      for(long long i=0;i<a;i++)
#define fd(i,a,b)    for(long long i=b;i>=a;i--)
#define clr(x)       memset(x,0,sizeof(x))
#define cln(x)       memset(x,-1,sizeof(x))
#define __           printf(" ")
#define _            printf("\n")
#define _o           printf("1\n")
#define stree        long long lft=node<<1,rht=(node<<1)|1,mid=(s+e)>>1
#define snode        long long s,long long e,long long node
#define slft         s,mid,lft
#define srht         mid+1,e,rht
#define sin()        if(S<=s&&e<=E)
#define sout()       if(S>e||s>E)
#define mod          1000000007
#define read()       freopen("in.txt","r",stdin)
#define write()      freopen("out.txt","w",stdout)
#define sfl(x)       scanf("%I64d",&x)
#define sfll(x,y)    scanf("%I64d %I64d",&x,&y)
#define sflll(x,y,z) scanf("%I64d %I64d %I64d",&x,&y,&z)
#define pfl(x)       printf("%I64d",x)
#define pfll(x,y)    printf("%I64d %I64d",x,y)
#define pflll(x,y,z) printf("%I64d %I64d %I64d",x,y,z)
#define xx           200000

typedef long long ll;
typedef pair<long long,long long> pll;

long long a[100010];


long long ans=0;
long long n,m;
long long cnt[xx+1000],add=100010;



void calc(){
     long long ret=0;
     clr(cnt);
     fi(i,1,n) cnt[i+add]=1;
     long long t=n;
     long long lft=add+1,rht=add+n,my=0;

     fi(i,1,m){
        long long cur=a[i]+add-my;
        ret+=t-cnt[cur-1]-cnt[rht];
        cnt[cur-2]+=cnt[cur-1];
        cnt[cur-1]=0;
        t-=cnt[rht];
        my++;
        lft--;
        rht--;
        //cout<<ret<<endl;
     }
     ret+=t-cnt[rht];
     ans+=ret;
     return;
}


main(){
    cin>>n>>m;

    fi(i,1,m) sfl(a[i]);

    if(n==1) {
        cout<<0<<endl;
        return 0;
    }

    calc();
    fi(i,1,m) a[i]=n-a[i]+1;
    calc();
    ans+=n;
    cout<<ans<<endl;
    return 0;
}
