#include<bits/stdc++.h>
using namespace std;
#define int long long
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define trace1(x)                cerr<<#x<<": "<<x<<endl
#define trace2(x, y)             cerr<<#x<<": "<<x<<" | "<<#y<<": "<<y<<endl
#define trace3(x, y, z)          cerr<<#x<<":" <<x<<" | "<<#y<<": "<<y<<" | "<<#z<<": "<<z<<endl
#define trace4(a, b, c, d)       cerr<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<endl
#define trace5(a, b, c, d, e)    cerr<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<" | "<<#e<< ": "<<e<<endl
#define trace6(a, b, c, d, e, f) cerr<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<" | "<<#e<< ": "<<e<<" | "<<#f<<": "<<f<<endl
#define endl '\n'

int p(int a,int b)
{
    int res=1;
    while(b)
    {
        if(b%2)
            res*=a;
        a*=a;
        b/=2;
    }
    return res;
}
int32_t main()
{
    IOS;
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int odd1=0;
        for(int i=0;i<n;i++)
        {
            int x;
            cin>>x;
            if(x%2)
                odd1++;
        }
        int m;
        cin>>m;
        int odd2=0;
        for(int i=0;i<m;i++)
        {
            int x;
            cin>>x;;
            if(x%2)
                odd2++;
        }
        cout<<(odd1*odd2)+(n-odd1)*(m-odd2)<<endl;
    }
}
    
    