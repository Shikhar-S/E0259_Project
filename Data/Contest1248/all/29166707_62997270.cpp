/*
Nahid Hossain
Jahangirnagar University
Roll:54
*/
#include<bits/stdc++.h>
#define ll          long long int
#define db          double
#define ma 100005
using namespace std;

ll b[ma];
int main()
{
    ll n,i,j,x,y;
    while(cin>>n)
    {
        for(i=1;i<=n;i++)cin>>b[i];
        sort(b+1,b+n+1);
        ll x=0,y=0;

        ll q=(n/2)+(n%2);

        for(i=n;i>=1;i--)
        {
            if(q==0)break;
            q--;
            x+=b[i];
        }

        for(i=1;i<=(n/2);i++)y+=b[i];
        cout<<y*y+x*x<<endl;
    }
}
