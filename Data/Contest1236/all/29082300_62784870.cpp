#include <bits/stdc++.h>
#define intt long long
#define pb push_back
#define mk make_pair
#define ii pair<int,int>
#define sc second
#define fr first
using namespace std;
intt dp[102][102][102];
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        intt a,b,c;
        cin>>a>>b>>c;
        intt res=0;
        while(b-1>=0&&c-2>=0)
        {
            b-=1,c-=2;
            res+=3;
        }
        while(a-1>=0&&b-2>=0)
        {
            b-=2,a-=1;
            res+=3;
        }
        cout<<res<<endl;
    }

    return 0;
}
