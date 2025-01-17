#include <iostream>

#include <algorithm> 

#include <cstdio>

using namespace std;

typedef long long ll;

#define wfor(i,j,k) for(i=j;i<k;++i)

#define mfor(i,j,k) for(i=j;i>=k;--i)

// void read(int &x) {

// 	char ch = getchar(); x = 0;

// 	for (; ch < '0' || ch > '9'; ch = getchar());

// 	for (; ch >= '0' && ch <= '9'; ch = getchar()) x = x * 10 + ch - '0';

// }

const int maxn=1e5+5;

int num[maxn];

int main()

{

    std::ios::sync_with_stdio(false);

    #ifdef test

    freopen("F:\\Desktop\\question\\in.txt","r",stdin);

    #endif

    #ifdef ubuntu

    freopen("/home/time/debug/debug/in","r",stdin);

    freopen("/home/time/debug/debug/out","w",stdout);

    #endif

    int n;

    cin>>n;

    int i;

    wfor(i,0,n)

    {

        cin>>num[i];

    }

    sort(num,num+n);

    int l=0,r=n-1;

    int flag=1;

    ll x=0,y=0;

    while(l<=r)

    {

        if(flag==1)

        {

            flag=0;

            x+=num[r];

            r--;

        }else

        {

            flag=1;

            y+=num[l];

            l++;

        }

    }

    cout<<x*x+y*y<<endl;

    return 0;

}